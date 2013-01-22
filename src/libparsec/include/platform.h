#ifndef _PLATFORM_H
#define _PLATFORM_H
// platform.h - platform dependent include selection should go here.


/* Sick of this junk, hard coding some stuff because there's no reason for the mass
   system dependent code anymore */

#undef SYSTEM_WINDOWS
#undef SYSTEM_LINUX
#undef SYSTEM_MACOSX

#define SYSTEM_SDL

#include "platform_sdl.h"

//PARSEC_SERVER Needs this:
#define CPU_VENDOR_OS "i386-pc-win32"

#if ! defined ( PARSEC_CLIENT ) && ! defined ( PARSEC_SERVER )
#error "Error: Building libparsec must be called from the client or server make files... for now..."
#endif

// target system specification
// These should be defined by the compiler or by the 
// building IDE
/*
#if defined ( __WIN32__ ) || defined (WIN32) || defined( __linux__) || defined(__CYGWIN__) || defined(__APPLE__)
//	#define SYSTEM_WINDOWS
//	#undef SYSTEM_LINUX
//	#undef SYSTEM_MACOSX
//	#define CPU_VENDOR_OS "i386-pc-win32"
//#elif defined( __linux__ )
	#undef SYSTEM_WINDOWS
	#define SYSTEM_LINUX
	#undef SYSTEM_MACOSX
#ifndef __CYGWIN__
	#define __CYGWIN__ // temporary, for SDL testing.
#endif
	#define CPU_VENDOR_OS "i386-pc-linux-gnu"
#elif defined( __APPLE__ )
	#undef SYSTEM_WINDOWS
	#define SYSTEM_LINUX
    #undef SYSTEM_MACOSX
	#define CPU_VENDOR_OS "i386-pc-linux-gnu"
#endif



#ifdef SYSTEM_LINUX
#include "platform_lnx.h"
#elif defined ( SYSTEM_WINDOWS )
#include "platform_w32.h"
#elif defined ( SYSTEM_MACOSX )
#include "platform_mac.h"
#else
#error "Unkown System Type Specified.
#endif
	*/

#endif //_PLATFORM_H