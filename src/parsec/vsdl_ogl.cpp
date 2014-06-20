/*
 * PARSEC - SDL OpenGL  Video Wrapper
 *
 * $Author: uberlinuxguy $ - $Date: 2004/09/15 12:25:37 $
 *
 * Orginally written by:
 *   Copyright (c) Andreas Varga       <sid@parsec.org>   1999
 *   Copyright (c) Markus Hadwiger     <msh@parsec.org>   1999
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */ 
#include "config.h"

// C library
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// compilation flags/debug support
#include "config.h"
#include "debug.h"

// general definitions
#include "general.h"
#include "objstruc.h"

// global externals
#include "globals.h"

// subsystem headers
#include "vid_defs.h"

// rendering subsystem
#include "r_patch.h"

// opengl headers
#include "r_gl.h"
#include "ro_api.h"

// local module header
#include "vsdl_ogl.h"

// proprietary module headers
#include "con_aux.h"
#include "con_int.h"
#include "e_supp.h"



// flags
//#define DEBUG_640x480_WINDOWED
#define EXPLICIT_GL_ORTHO
//#define LIST_ONLY_SAFE_MODES
//#define REVERSED_DEPTH_RANGE


//NOTE:
// if REVERSED_DEPTH_RANGE is set, glDepthRange() will be used to reverse
// the depth range. otherwise, it will be reversed in the projection matrices.
// this is a work-around for the DRI drivers, since they have problems with a
// reversed depth range. for them, REVERSED_DEPTH_RANGE should not be set.
// currently, this is only an issue under Linux. for consistency and testing,
// this flag has also been added here.


// globally usable orthogonal projection-matrix (with glLoadMatrixf()) --------
//
GLfloat gl_orthogonal_matrix[] = {

	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.0f, 0.0f, 1.0f
};

GLfloat gl_orthogonal_params[ 6 ];


// special opengl flag values -------------------------------------------------
//
enum {

	GL_FLAG_EXTCTRL_GLEXTS_OFF	= 0,	// don't use extensions
	GL_FLAG_EXTCTRL_GLEXTS_ON	= 1,	// use available extensions

	GL_FLAG_SWAPCTRL_NONE		= 0,	// no explicit synchronization
	GL_FLAG_SWAPCTRL_GLFLUSH	= 1,	// glFlush() prior to SwapBuffers()
	GL_FLAG_SWAPCTRL_GLFINISH	= 2,	// glFinish() prior to SwapBuffers()

	GL_FLAG_BPPCTRL_OFF			= 0,	// never switch colordepth
	GL_FLAG_BPPCTRL_ON			= 1		// colordepth switching allowed
};


// user-specifiable opengl flags (will be registered as int commands) ---------
//
int	gl_flag_swapctrl	= GL_FLAG_SWAPCTRL_NONE;
int gl_flag_bppctrl		= GL_FLAG_BPPCTRL_ON;


int						oldpixdepth		= 0;

int 					sdl_win_width;
int 					sdl_win_height;
int						sdl_win_bpp;

GLint 					sdl_wsz_x;
GLint 					sdl_wsz_y;
GLsizei 				sdl_wsz_w;
GLsizei 				sdl_wsz_h;

SDL_Window *			curwindow = NULL;
SDL_GLContext			curcontext = NULL;


// display next opengl buffer -------------------------------------------------
//
void VSDL_CommitOGLBuff()
{
	// Tell SDL to swap the GL Buffers
	SDL_GL_SwapWindow(curwindow);
}


// init interface code to GL functions ---------------------------------------
//
int VSDL_InitOGLInterface( int printmodelistflags )
{
	MSGOUT( "Using the OpenGL subsystem as rendering device." );

	if ( SDL_Init(SDL_INIT_VIDEO) < 0 ) {
		MSGOUT("ERROR: Trouble initializing video subsystem.");
		return FALSE;
	}

	Resolutions.clear();

	SDL_DisplayMode curmode = {};
	SDL_GetDesktopDisplayMode(0, &curmode);

	MaxScreenBPP = SDL_BITSPERPIXEL(curmode.format);

	for (int i = 0; i < SDL_GetNumDisplayModes(0); i++) {
		
		if (SDL_GetDisplayMode(0, i, &curmode) < 0) {
			MSGOUT("Could not get info for SDL display mode #%d: %s\n", i, SDL_GetError());
			continue;
		}

		int xres = curmode.w;
		int yres = curmode.h;

		int bpp = SDL_BITSPERPIXEL(curmode.format);

		// we don't support resolutions below 640x480, or uneven ones
		if (xres < 640 || yres < 480 || xres % 2 != 0 || yres % 2 != 0)
			continue;

		// we don't support non-standard screen formats
		if (bpp != 32 && bpp != 16)
			continue;

		// TODO: look into supporting resolution-based BPP (if it's used at all anymore)
		// for now, we can't use any screen mode that doesn't support the max known BPP
		if (bpp < MaxScreenBPP)
			continue;

		// make sure we don't already have this resolution in our list
		if (GetResolutionIndex(xres, yres) < 0) {
			Resolutions.push_back(resinfo_s(xres, yres));
		}
	}

	ASSERT(Resolutions.size() > 0);

	// sort resolution list, putting the smallest at the front
	std::sort(Resolutions.begin(), Resolutions.end());

	return TRUE;
}


// globally usable projective projection-matrix (with glLoadMatrixf()) --------
//
GLfloat gl_projective_matrix[] = {

	1.0f, 0.0f, 0.0f, 0.0f,
	0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.0f, 1.0f, 1.0f,
	0.0f, 0.0f, 0.0f, 0.0f
};


// calculate the global projective projection-matrix --------------------------
//
void VSDL_CalcProjectiveMatrix()
{
	//NOTE:
	// this matrix is equivalent to the following:
	// - glLoadIdentity();
	// - glFrustum( left, right, bottom, top, znear, zfar );
	// - glMultMatrixf( { 1,0,0,0, 0,1,0,0, 0,0,-1,0, 0,0,0,1 } );

	float crit_x = Criterion_X * Near_View_Plane;
	float crit_y = Criterion_Y * Near_View_Plane;

	float left	= -crit_x;
	float right	=  crit_x;
	float bottom	=  crit_y;
	float top		= -crit_y;
	float znear	= Near_View_Plane;
	float zfar	= Far_View_Plane;

	float r_min_l	= right - left;
	float t_min_b	= top   - bottom;
	float f_min_n	= zfar  - znear;
	float n2		= znear * 2;

	gl_projective_matrix[ 0 ]	= n2 / r_min_l;
	gl_projective_matrix[ 5 ]	= n2 / t_min_b;
	gl_projective_matrix[ 8 ]	= -( right + left ) / r_min_l;
	gl_projective_matrix[ 9 ]	= -( top + bottom ) / t_min_b;
	gl_projective_matrix[ 10 ]	=  ( zfar + znear ) / f_min_n;
	gl_projective_matrix[ 14 ]	= -( zfar * n2    ) / f_min_n;
}



// calculate the global orthographic projection-matrix ------------------------
//
void VSDL_CalcOrthographicMatrix()
{
	//NOTE:
	// this matrix is equivalent to the following:
	// - glLoadIdentity();
	// - glOrtho( wgl_wsz_x, wgl_wsz_x + wgl_wsz_w,
	//            wgl_wsz_y + wgl_wsz_h, wgl_wsz_y,
	//            -1.0, 0.0 );

	float left	= sdl_wsz_x;
	float right	= sdl_wsz_x + sdl_wsz_w;
	float bottom	= sdl_wsz_y + sdl_wsz_h;
	float top		= sdl_wsz_y;
	float znear	= 1.0f;
	float zfar	= 0.0f;

	// make the parameters accessible separately
	// to enable use of glOrtho()
	gl_orthogonal_params[ 0 ] = left;
	gl_orthogonal_params[ 1 ] = right;
	gl_orthogonal_params[ 2 ] = bottom;
	gl_orthogonal_params[ 3 ] = top;
	gl_orthogonal_params[ 4 ] = -znear;
	gl_orthogonal_params[ 5 ] = -zfar;

	float r_min_l	= right - left;
	float t_min_b	= top   - bottom;
	float f_min_n	= zfar  - znear;

	gl_orthogonal_matrix[ 0 ]	= 2.0f / r_min_l;
	gl_orthogonal_matrix[ 5 ]	= 2.0f / t_min_b;
	gl_orthogonal_matrix[ 10 ]	= 2.0f / f_min_n;
	gl_orthogonal_matrix[ 12 ]	= -( right + left ) / r_min_l;
	gl_orthogonal_matrix[ 13 ]	= -( top + bottom ) / t_min_b;
	gl_orthogonal_matrix[ 14 ]	= -( zfar + znear ) / f_min_n;
}


// configure opengl projection matrix and viewport ----------------------------
//
PRIVATE
void SDL_ConfigureProjection()
{

}


// query available extensions -------------------------------------------------
//
PRIVATE
void SDL_RCQueryExtensions()
{
	const char * extliststr = (const char *) glGetString(GL_EXTENSIONS);
	
	if (!extliststr || !extliststr[0])
		return;
	
	MSGOUT("Extensions:\n");
	
	size_t extliststrlen = strlen(extliststr);
	int extlen = 0, startindex = -1;
	
	// extensions are separated by a single space, so we need to iterate over the string to find extension names
	for (size_t i = 0; i < extliststrlen; i++) {
		// print current extension if we encounter a space or we're at the end of the string
		if (extliststr[i] == ' ' || i == extliststrlen-1) {
			if (i == extliststrlen-1)
				extlen++;

			if (extlen > 0) // extension has been found, lets print it
				MSGOUT("\t%.*s\n", extlen, extliststr + startindex);
			
			// reset counters
			extlen = 0;
			startindex = -1;
		} else {
			// keep track of the length of the current extension we're traversing
			extlen++;
			if (startindex == -1) // keep track of the start index as well
				startindex = i;
		}
	}
}


// display current rendering context info -------------------------------------
//
void SDL_RCDisplayInfo()
{
	MSGOUT( "--OpenGL driver info--\n" );

	MSGOUT( "Vendor:\n" );
	MSGOUT( " %s\n", glGetString( GL_VENDOR ) );
	MSGOUT( "Renderer:\n" );
	MSGOUT( " %s\n", glGetString( GL_RENDERER ) );
	MSGOUT( "Version:\n" );
	MSGOUT( " %s\n", glGetString( GL_VERSION ) );

	// query extensions string
	//SDL_RCQueryExtensions();
}


// initialize OpenGL extensions via GLEW --------------------------------------
//
PRIVATE
void VSDL_InitGLExtensions()
{
	// don't rely purely on extension string list to determine capabilities
	glewExperimental = GL_TRUE;

	// initialize extensions from GLEW
	if (glewInit() != GLEW_OK) {
		MSGOUT("Warning: failed to initialize GLEW\n");
		return;
	}

	// some drivers support core GL occlusion querying but not the ARB extension
	// so we just use the core GL function pointers for the ARB functions since the interface is the same
	if (GLEW_VERSION_1_5 && !GLEW_ARB_occlusion_query) {
		glBeginQueryARB = (PFNGLBEGINQUERYARBPROC) glBeginQuery;
		glDeleteQueriesARB = (PFNGLDELETEQUERIESARBPROC) glDeleteQueries;
		glEndQueryARB = (PFNGLENDQUERYARBPROC) glEndQuery;
		glGenQueriesARB = (PFNGLGENQUERIESARBPROC) glGenQueries;
		glGetQueryObjectivARB = (PFNGLGETQUERYOBJECTIVARBPROC) glGetQueryObjectiv;
		glGetQueryObjectuivARB = (PFNGLGETQUERYOBJECTUIVARBPROC) glGetQueryObjectuiv;
		glGetQueryivARB = (PFNGLGETQUERYIVARBPROC) glGetQueryiv;
		glIsQueryARB = (PFNGLISQUERYARBPROC) glIsQuery;
	}

	// same deal with vertex buffers
	if (GLEW_VERSION_1_5 && !GLEW_ARB_vertex_buffer_object) {
		glBindBufferARB = glBindBuffer;
		glBufferDataARB = glBufferData;
		glBufferSubDataARB = glBufferSubData;
		glDeleteBuffersARB = glDeleteBuffers;
		glGenBuffersARB = glGenBuffers;
		glGetBufferParameterivARB = glGetBufferParameteriv;
		glGetBufferPointervARB = glGetBufferPointerv;
		glGetBufferSubDataARB = glGetBufferSubData;
		glIsBufferARB = glIsBuffer;
		glMapBufferARB = glMapBuffer;
		glUnmapBufferARB = glUnmapBuffer;
	}
}


// setup current rendering context --------------------------------------------
//
PRIVATE
void SDL_RCSetup()
{
	VSDL_InitGLExtensions();
	
	// attempt to enable MSAA if set
	if (AUX_MSAA > 0 && (GLEW_VERSION_1_3 || GLEW_ARB_multisample)) {
		glEnable(GL_MULTISAMPLE);
	
		GLint buffers;
		GLint samples;
		
		glGetIntegerv(GL_SAMPLE_BUFFERS, &buffers);
		glGetIntegerv(GL_SAMPLES, &samples);
		
		if ((AUX_MSAA && !buffers) || (AUX_MSAA != samples)) {
			// OpenGL multisampling values different than expected 
			MSGOUT("MSAA warning: expected 1 buffer and %d samples, got %d buffer(s) and %d sample(s)\n", AUX_MSAA, buffers, samples);
			if (samples > 0 && buffers > 0) {
				AUX_MSAA = samples;
			} else {
				// clean up
				glDisable(GL_MULTISAMPLE);
				AUX_MSAA = 0;
			}
		}
	} else {
		// MSAA is 0 or multisampling isn't supported
		AUX_MSAA = 0;
	}
	

	// calculate projection matrix, setup projection
	// calc projection matrices
	VSDL_CalcProjectiveMatrix();
	VSDL_CalcOrthographicMatrix();

	// set projection to screen coordinate identity
	glMatrixMode( GL_PROJECTION );
	GLint rc = glGetError();
	/*
	glLoadIdentity();
	glOrtho( sdl_wsz_x, sdl_wsz_x + sdl_wsz_w,
	            sdl_wsz_y + sdl_wsz_h, sdl_wsz_y,
	            -1.0, 0.0 );
	*/

#ifdef EXPLICIT_GL_ORTHO
	glLoadIdentity();

	//glOrtho( sdl_wsz_x, sdl_wsz_x + sdl_wsz_w,
    //        sdl_wsz_y + sdl_wsz_h, sdl_wsz_y,
    //        -1.0, 0.0 );
	glOrtho( gl_orthogonal_params[ 0 ], gl_orthogonal_params[ 1 ],
			 gl_orthogonal_params[ 2 ], gl_orthogonal_params[ 3 ],
			 gl_orthogonal_params[ 4 ], gl_orthogonal_params[ 5 ] );

#else
	glLoadMatrixf( gl_orthogonal_matrix );
#endif

	// select reversed depth range
	glDepthRange( 1.0, 0.0 ); // FIXME: glDepthRangef on GLES

	// no transformation
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();

	// set viewport
	glViewport( sdl_wsz_x, sdl_wsz_y, sdl_wsz_w, sdl_wsz_h );
	rc = glGetError();
	if (rc == GL_INVALID_VALUE) {
		MSGOUT("Error: Invalid GL Viewport values");
		exit(1);
	}

	//glFrontFace( GL_CW ); //FIXME: ?? why was this labelled FIXME?

	// initial clear
	glClearColor( 0, 0, 0, 1 );
	glClearDepth( 0 );
	
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );

	glColorMask( GL_TRUE, GL_TRUE, GL_TRUE, GL_TRUE );

	// prettiest possible mipmaps, please
	if (GLEW_VERSION_1_4 || GLEW_SGIS_generate_mipmap)
		glHint(GL_GENERATE_MIPMAP_HINT, GL_NICEST);

	// same with texture compression
	if (GLEW_VERSION_1_3 || GLEW_ARB_texture_compression)
		glHint(GL_TEXTURE_COMPRESSION_HINT, GL_NICEST);

	// limit maximum texture size
	int maxgltexsize = 0;
	glGetIntegerv(GL_MAX_TEXTURE_SIZE, &maxgltexsize);

	if (maxgltexsize < VidInfo_MaxTextureSize) {
		VidInfo_MaxTextureSize = maxgltexsize;
		VidInfo_MaxTextureLod  = CeilPow2Exp(maxgltexsize);
	}

	// determine maximum number of active texture units
	if (GLEW_VERSION_1_3 || GLEW_ARB_multitexture) {
		GLint maxtextureunits;
		glGetIntegerv(GL_MAX_TEXTURE_UNITS, &maxtextureunits);

		// GL 2.0 / shaders introduce texture image units, max tex units is the greater of the above and below
		if (GLEW_VERSION_2_0 || GLEW_ARB_vertex_shader) {
			GLint maxteximageunits;
			glGetIntegerv(GL_MAX_COMBINED_TEXTURE_IMAGE_UNITS, &maxteximageunits);
			maxtextureunits = max(maxtextureunits, maxteximageunits);
		}

		VidInfo_NumTextureUnits = max(maxtextureunits, 1);
	} else {
		VidInfo_NumTextureUnits = 1;
	}

	// initialize GL state tracking
	RO_InitializeState();
}


// ----------------------------------------------------------------------------
//
static int fullscreen_mode	= TRUE;



// set opengl graphics mode ---------------------------------------------------
//
int VSDL_InitOGLMode()
{
	// set our mode index
	ASSERT(VID_MODE_AVAILABLE(GetResolutionIndex(GameScreenRes.width, GameScreenRes.height)));

	fullscreen_mode	= !Op_WindowedMode;

	Uint32 mode_flags = SDL_WINDOW_OPENGL;
	
	sdl_win_bpp = GameScreenBPP;

	sdl_win_width = GameScreenRes.width;
	sdl_win_height = GameScreenRes.height;

	if ( fullscreen_mode ) {
		mode_flags |= SDL_WINDOW_FULLSCREEN;
	}

	sdl_wsz_x = 0;
	sdl_wsz_y = 0;
	sdl_wsz_w = sdl_win_width;
	sdl_wsz_h = sdl_win_height;

	
	// set the SDL GL Attributes

	if ( sdl_win_bpp == 32 ) {

	    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,    	    8);
	    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,  	    8);
	    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,   	    8);
	    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,  	    8);
	    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,  	    24);

	} else if ( sdl_win_bpp == 16 ) {
	
	    SDL_GL_SetAttribute(SDL_GL_RED_SIZE,    	    5);
	    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE,  	    6);
	    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE,   	    5);
	    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE,  	    0);
	    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE,  	    16);

	} else {
	
		ASSERT( 0 );
		PANIC( 0 );
	}
	
	// use double buffering if possible
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// set antialiasing
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, AUX_MSAA > 0 ? 1 : 0);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, AUX_MSAA);

    // SDL's default values.
    int contextprofile = 0;
    int gl_majorversion = 2;
    int gl_minorversion = 1;

    const char *driver = SDL_GetCurrentVideoDriver();

    // We always want to use OpenGL ES on some video backends.
    if (driver && strstr(driver, "RPI")) {
        contextprofile |= SDL_GL_CONTEXT_PROFILE_ES;

        // OpenGL ES 1.1 for now...
        gl_majorversion = 1;
        gl_minorversion = 1;
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, contextprofile);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, gl_majorversion);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, gl_minorversion);

	// change the video mode.
	printf("Changing vid mode to %ix%i, bpp: %i, vsync: %d, aa: %dx\n", sdl_win_width, sdl_win_height, sdl_win_bpp, FlipSynched, AUX_MSAA);

	if (curwindow != NULL) {
		SDL_DestroyWindow(curwindow);
		curwindow = NULL;
	}

    if (curcontext != NULL) {
        SDL_GL_DeleteContext(curcontext);
        curcontext = NULL;
    }

	curwindow = SDL_CreateWindow("Parsec", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_UNDEFINED, sdl_win_width, sdl_win_height, mode_flags);

	if (curwindow == NULL) {
		MSGOUT("Could not create SDL window: %s\n", SDL_GetError());
		return FALSE;
	}

    curcontext = SDL_GL_CreateContext(curwindow);

    if (curcontext == NULL) {
        MSGOUT("Could not create OpenGL context: %s\n", SDL_GetError());
        return FALSE;
    }

	// set vertical synchronization
	SDL_GL_SetSwapInterval(FlipSynched ? 1 : 0);

	// setup current rendering context
	SDL_RCSetup();

	// display current rendering context info
	SDL_RCDisplayInfo();

    // disable system cursor inside the SDL window
	SDL_ShowCursor(SDL_DISABLE);

	return TRUE;
}


// shut down rendering canvas -------------------------------------------------
//
void VSDL_ShutDownOGL()
{
	// invalidate texture cache
	R_InvalidateCachedTexture( NULL );
	
	SDL_ShowCursor(SDL_ENABLE);
	
	if (curwindow != NULL) {
		SDL_DestroyWindow(curwindow);
		curwindow = NULL;
	}
	
	if (curcontext != NULL) {
		SDL_GL_DeleteContext(curcontext);
		curcontext = NULL;
	}
}


// registration table for opengl int commands (user-specifiable flags) --------
//
int_command_s gl_int_commands[] = {
	{ 0x00,	"gl.swapctrl",	0, 2,	&gl_flag_swapctrl,	NULL,	NULL },
	{ 0x00,	"gl.bppctrl",	0, 1,	&gl_flag_bppctrl,	NULL,	NULL },
};

#define NUM_GL_INT_COMMANDS		CALC_NUM_ARRAY_ENTRIES( gl_int_commands )


// module registration function -----------------------------------------------
//
REGISTER_MODULE( VSDL_OGL )
{
	// register opengl int commands (flags)
	for ( int curcmd = 0; curcmd < NUM_GL_INT_COMMANDS; curcmd++ ) {
		CON_RegisterIntCommand( &gl_int_commands[ curcmd ] );
	}
}
