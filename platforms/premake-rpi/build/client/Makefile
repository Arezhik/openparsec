# GNU Make project makefile autogenerated by Premake
ifndef config
  config=debug32
endif

ifndef verbose
  SILENT = @
endif

ifndef CC
  CC = gcc
endif

ifndef CXX
  CXX = g++
endif

ifndef AR
  AR = ar
endif

ifeq ($(config),debug32)
  OBJDIR     = obj/x32/Debug
  TARGETDIR  = .
  TARGET     = $(TARGETDIR)/parsec
  DEFINES   += -DDEBUG -DPARSEC_CLIENT -DGLES
  INCLUDES  += -I../../../../src/libraries -I/usr/include -I/usr/local/include -I/opt/vc/include -I../../../../src/libparsec/include -I../../../../src/parsec/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -g
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -L/usr/lib32 -L/opt/vc/lib
  LIBS      += -lEGL -lGLESv1_CM -lSDL2 -lSDL2_mixer   
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(ARCH) $(LIBS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
	@echo Running post-build commands
	cp parsec ../../../../parsec_root/client/
  endef
endif

ifeq ($(config),release32)
  OBJDIR     = obj/x32/Release
  TARGETDIR  = .
  TARGET     = $(TARGETDIR)/parsec
  DEFINES   += -DPARSEC_CLIENT
  INCLUDES  += -I../../../../src/libraries -I/usr/include -I/usr/local/include -I/opt/include -I../../../../src/libparsec/include -I../../../../src/parsec/include
  CPPFLAGS  += -MMD -MP $(DEFINES) $(INCLUDES)
  CFLAGS    += $(CPPFLAGS) $(ARCH) -O2
  CXXFLAGS  += $(CFLAGS) 
  LDFLAGS   += -s -L/usr/lib32
  LIBS      += -lSDL2 -lSDL2_mixer -lEGL -lGL
  RESFLAGS  += $(DEFINES) $(INCLUDES) 
  LDDEPS    += 
  LINKCMD    = $(CXX) -o $(TARGET) $(OBJECTS) $(LDFLAGS) $(RESOURCES) $(ARCH) $(LIBS)
  define PREBUILDCMDS
  endef
  define PRELINKCMDS
  endef
  define POSTBUILDCMDS
	@echo Running post-build commands
	cp parsec ../../../../parsec_root/client/
  endef
endif

OBJECTS := \
	$(OBJDIR)/net_swap.o \
	$(OBJDIR)/sw_path.o \
	$(OBJDIR)/sys_date.o \
	$(OBJDIR)/sl_timer.o \
	$(OBJDIR)/obj_cust.o \
	$(OBJDIR)/utl_math.o \
	$(OBJDIR)/net_pckt_gmsv.o \
	$(OBJDIR)/sys_file.o \
	$(OBJDIR)/net_util.o \
	$(OBJDIR)/utl_logfile.o \
	$(OBJDIR)/g_emp.o \
	$(OBJDIR)/con_tab.o \
	$(OBJDIR)/sl_path.o \
	$(OBJDIR)/obj_odt.o \
	$(OBJDIR)/utl_clpo.o \
	$(OBJDIR)/net_stream.o \
	$(OBJDIR)/utl_bsp.o \
	$(OBJDIR)/con_arg.o \
	$(OBJDIR)/utl_clip.o \
	$(OBJDIR)/e_modulemanager.o \
	$(OBJDIR)/utl_math2.o \
	$(OBJDIR)/debug.o \
	$(OBJDIR)/net_wrap.o \
	$(OBJDIR)/sw_timer.o \
	$(OBJDIR)/sys_swap.o \
	$(OBJDIR)/utl_cull.o \
	$(OBJDIR)/obj_creg.o \
	$(OBJDIR)/e_relist.o \
	$(OBJDIR)/con_vald.o \
	$(OBJDIR)/g_extra.o \
	$(OBJDIR)/obj_clas.o \
	$(OBJDIR)/obj_type.o \
	$(OBJDIR)/do_font.o \
	$(OBJDIR)/g_planet.o \
	$(OBJDIR)/aud_bkgn.o \
	$(OBJDIR)/sys_glob.o \
	$(OBJDIR)/ro_obj.o \
	$(OBJDIR)/sl_msg.o \
	$(OBJDIR)/ro_api.o \
	$(OBJDIR)/con_geom.o \
	$(OBJDIR)/e_replay.o \
	$(OBJDIR)/m_status.o \
	$(OBJDIR)/e_vtxani.o \
	$(OBJDIR)/ro_part.o \
	$(OBJDIR)/obj_expl.o \
	$(OBJDIR)/ro_supp.o \
	$(OBJDIR)/m_option.o \
	$(OBJDIR)/con_shad.o \
	$(OBJDIR)/net_pckt_peer.o \
	$(OBJDIR)/con_kmap.o \
	$(OBJDIR)/g_sfx.o \
	$(OBJDIR)/aud_glob.o \
	$(OBJDIR)/m_logo.o \
	$(OBJDIR)/e_mouse.o \
	$(OBJDIR)/aud_game.o \
	$(OBJDIR)/net_util_cl.o \
	$(OBJDIR)/net_glob.o \
	$(OBJDIR)/h_frmplt.o \
	$(OBJDIR)/net_gmsv.o \
	$(OBJDIR)/con_cani.o \
	$(OBJDIR)/img_3df.o \
	$(OBJDIR)/m_list.o \
	$(OBJDIR)/vid_init.o \
	$(OBJDIR)/snd_api.o \
	$(OBJDIR)/e_colani.o \
	$(OBJDIR)/vsdl_buffo.o \
	$(OBJDIR)/vid_glob.o \
	$(OBJDIR)/isdl_mouse.o \
	$(OBJDIR)/net_pckt.o \
	$(OBJDIR)/g_boot.o \
	$(OBJDIR)/obj_comm.o \
	$(OBJDIR)/m_main.o \
	$(OBJDIR)/ro_patch.o \
	$(OBJDIR)/img_load.o \
	$(OBJDIR)/d_misc.o \
	$(OBJDIR)/g_swarm.o \
	$(OBJDIR)/img_supp.o \
	$(OBJDIR)/vsdl_ogl.o \
	$(OBJDIR)/e_demo.o \
	$(OBJDIR)/obj_part.o \
	$(OBJDIR)/do_iter.o \
	$(OBJDIR)/img_tga.o \
	$(OBJDIR)/snd_wav.o \
	$(OBJDIR)/net_conn.o \
	$(OBJDIR)/t_pack.o \
	$(OBJDIR)/ro_perf.o \
	$(OBJDIR)/e_events.o \
	$(OBJDIR)/h_strmap.o \
	$(OBJDIR)/ro_poly.o \
	$(OBJDIR)/inp_glob.o \
	$(OBJDIR)/net_univ.o \
	$(OBJDIR)/m_button.o \
	$(OBJDIR)/vid_supp.o \
	$(OBJDIR)/con_aux.o \
	$(OBJDIR)/con_main.o \
	$(OBJDIR)/con_say.o \
	$(OBJDIR)/net_rmev.o \
	$(OBJDIR)/net_peer.o \
	$(OBJDIR)/e_supp.o \
	$(OBJDIR)/h_text.o \
	$(OBJDIR)/e_global.o \
	$(OBJDIR)/obj_ctrl.o \
	$(OBJDIR)/con_rc.o \
	$(OBJDIR)/con_conf.o \
	$(OBJDIR)/g_stars.o \
	$(OBJDIR)/img_api.o \
	$(OBJDIR)/g_bot_cl.o \
	$(OBJDIR)/con_info.o \
	$(OBJDIR)/net_rmev_gmsv.o \
	$(OBJDIR)/e_color.o \
	$(OBJDIR)/h_cockpt.o \
	$(OBJDIR)/img_jpg.o \
	$(OBJDIR)/e_texani.o \
	$(OBJDIR)/e_shader.o \
	$(OBJDIR)/g_stgate.o \
	$(OBJDIR)/g_vapor.o \
	$(OBJDIR)/vsdl_inito.o \
	$(OBJDIR)/sys_bind.o \
	$(OBJDIR)/g_global.o \
	$(OBJDIR)/vsdl_suppo.o \
	$(OBJDIR)/net_prediction.o \
	$(OBJDIR)/isdl_supp.o \
	$(OBJDIR)/img_conv.o \
	$(OBJDIR)/inp_comm.o \
	$(OBJDIR)/con_com.o \
	$(OBJDIR)/net_rmev_peer.o \
	$(OBJDIR)/aud_supp.o \
	$(OBJDIR)/aud_sdlmixer.o \
	$(OBJDIR)/r_glob.o \
	$(OBJDIR)/con_int.o \
	$(OBJDIR)/inp_init.o \
	$(OBJDIR)/con_tani.o \
	$(OBJDIR)/net_serv.o \
	$(OBJDIR)/isdl_joy.o \
	$(OBJDIR)/g_supp.o \
	$(OBJDIR)/g_wfx.o \
	$(OBJDIR)/vid_plug.o \
	$(OBJDIR)/obj_xtra.o \
	$(OBJDIR)/net_game_gmsv.o \
	$(OBJDIR)/e_loader.o \
	$(OBJDIR)/sys_conv.o \
	$(OBJDIR)/g_explod.o \
	$(OBJDIR)/m_viewer.o \
	$(OBJDIR)/ro_sfx.o \
	$(OBJDIR)/net_udp.o \
	$(OBJDIR)/nw_udp.o \
	$(OBJDIR)/part_api.o \
	$(OBJDIR)/nl_udp.o \
	$(OBJDIR)/g_laser.o \
	$(OBJDIR)/g_gameloop.o \
	$(OBJDIR)/net_game.o \
	$(OBJDIR)/do_misc.o \
	$(OBJDIR)/h_drwhud.o \
	$(OBJDIR)/obj_vani.o \
	$(OBJDIR)/g_cloud.o \
	$(OBJDIR)/g_shkwav.o \
	$(OBJDIR)/inp_user.o \
	$(OBJDIR)/part_def.o \
	$(OBJDIR)/e_callbk.o \
	$(OBJDIR)/obj_game.o \
	$(OBJDIR)/con_std.o \
	$(OBJDIR)/e_level.o \
	$(OBJDIR)/con_list.o \
	$(OBJDIR)/g_telep.o \
	$(OBJDIR)/sl_err.o \
	$(OBJDIR)/sl_main.o \
	$(OBJDIR)/d_glob.o \
	$(OBJDIR)/obj_iter.o \
	$(OBJDIR)/con_load.o \
	$(OBJDIR)/obj_ani.o \
	$(OBJDIR)/net_game_peer.o \
	$(OBJDIR)/e_record.o \
	$(OBJDIR)/part_sys.o \
	$(OBJDIR)/part_ani.o \
	$(OBJDIR)/h_radar.o \
	$(OBJDIR)/inp_sdl.o \
	$(OBJDIR)/g_camera.o \
	$(OBJDIR)/e_getopt.o \
	$(OBJDIR)/h_global.o \
	$(OBJDIR)/e_draw.o \
	$(OBJDIR)/sl_opt.o \
	$(OBJDIR)/con_ext.o \
	$(OBJDIR)/con_path.o \
	$(OBJDIR)/do_patch.o \
	$(OBJDIR)/do_bmap.o \
	$(OBJDIR)/obj_coll.o \
	$(OBJDIR)/con_act.o \
	$(OBJDIR)/h_supp.o \
	$(OBJDIR)/aud_comm.o \

RESOURCES := \

SHELLTYPE := msdos
ifeq (,$(ComSpec)$(COMSPEC))
  SHELLTYPE := posix
endif
ifeq (/bin,$(findstring /bin,$(SHELL)))
  SHELLTYPE := posix
endif

.PHONY: clean prebuild prelink

all: $(TARGETDIR) $(OBJDIR) prebuild prelink $(TARGET)
	@:

$(TARGET): $(GCH) $(OBJECTS) $(LDDEPS) $(RESOURCES)
	@echo Linking client
	$(SILENT) $(LINKCMD)
	$(POSTBUILDCMDS)

$(TARGETDIR):
	@echo Creating $(TARGETDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(TARGETDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(TARGETDIR))
endif

$(OBJDIR):
	@echo Creating $(OBJDIR)
ifeq (posix,$(SHELLTYPE))
	$(SILENT) mkdir -p $(OBJDIR)
else
	$(SILENT) mkdir $(subst /,\\,$(OBJDIR))
endif

clean:
	@echo Cleaning client
ifeq (posix,$(SHELLTYPE))
	$(SILENT) rm -f  $(TARGET)
	$(SILENT) rm -rf $(OBJDIR)
else
	$(SILENT) if exist $(subst /,\\,$(TARGET)) del $(subst /,\\,$(TARGET))
	$(SILENT) if exist $(subst /,\\,$(OBJDIR)) rmdir /s /q $(subst /,\\,$(OBJDIR))
endif

prebuild:
	$(PREBUILDCMDS)

prelink:
	$(PRELINKCMDS)

ifneq (,$(PCH))
$(GCH): $(PCH)
	@echo $(notdir $<)
	-$(SILENT) cp $< $(OBJDIR)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
endif

$(OBJDIR)/stb_image.o: ../../../../src/libraries/stb_image/stb_image.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/stb_image_write.o: ../../../../src/libraries/stb_image/stb_image_write.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/glew.o: ../../../../src/libraries/glew/glew.c
	@echo $(notdir $<)
	$(SILENT) $(CC) $(CFLAGS) -o "$@" -c "$<"
$(OBJDIR)/net_swap.o: ../../../../src/libparsec/net_swap.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/sw_path.o: ../../../../src/libparsec/sw_path.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/sys_date.o: ../../../../src/libparsec/sys_date.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/sl_timer.o: ../../../../src/libparsec/sl_timer.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/obj_cust.o: ../../../../src/libparsec/obj_cust.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/utl_math.o: ../../../../src/libparsec/utl_math.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/net_pckt_gmsv.o: ../../../../src/libparsec/net_pckt_gmsv.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/sys_file.o: ../../../../src/libparsec/sys_file.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/net_util.o: ../../../../src/libparsec/net_util.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/utl_logfile.o: ../../../../src/libparsec/utl_logfile.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/g_emp.o: ../../../../src/libparsec/g_emp.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/con_tab.o: ../../../../src/libparsec/con_tab.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/sl_path.o: ../../../../src/libparsec/sl_path.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/obj_odt.o: ../../../../src/libparsec/obj_odt.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/utl_clpo.o: ../../../../src/libparsec/utl_clpo.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/net_stream.o: ../../../../src/libparsec/net_stream.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/utl_bsp.o: ../../../../src/libparsec/utl_bsp.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/con_arg.o: ../../../../src/libparsec/con_arg.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/utl_clip.o: ../../../../src/libparsec/utl_clip.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/e_modulemanager.o: ../../../../src/libparsec/e_modulemanager.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/utl_math2.o: ../../../../src/libparsec/utl_math2.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/debug.o: ../../../../src/libparsec/debug.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/net_wrap.o: ../../../../src/libparsec/net_wrap.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/sw_timer.o: ../../../../src/libparsec/sw_timer.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/sys_swap.o: ../../../../src/libparsec/sys_swap.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/utl_cull.o: ../../../../src/libparsec/utl_cull.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/obj_creg.o: ../../../../src/libparsec/obj_creg.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/e_relist.o: ../../../../src/libparsec/e_relist.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/con_vald.o: ../../../../src/libparsec/con_vald.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/g_extra.o: ../../../../src/libparsec/g_extra.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/obj_clas.o: ../../../../src/libparsec/obj_clas.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/obj_type.o: ../../../../src/libparsec/obj_type.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/do_font.o: ../../../../src/parsec/do_font.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/g_planet.o: ../../../../src/parsec/g_planet.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/aud_bkgn.o: ../../../../src/parsec/aud_bkgn.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/sys_glob.o: ../../../../src/parsec/sys_glob.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ro_obj.o: ../../../../src/parsec/ro_obj.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/sl_msg.o: ../../../../src/parsec/sl_msg.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ro_api.o: ../../../../src/parsec/ro_api.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/con_geom.o: ../../../../src/parsec/con_geom.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/e_replay.o: ../../../../src/parsec/e_replay.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/m_status.o: ../../../../src/parsec/m_status.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/e_vtxani.o: ../../../../src/parsec/e_vtxani.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ro_part.o: ../../../../src/parsec/ro_part.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/obj_expl.o: ../../../../src/parsec/obj_expl.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ro_supp.o: ../../../../src/parsec/ro_supp.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/m_option.o: ../../../../src/parsec/m_option.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/con_shad.o: ../../../../src/parsec/con_shad.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/net_pckt_peer.o: ../../../../src/parsec/net_pckt_peer.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/con_kmap.o: ../../../../src/parsec/con_kmap.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/g_sfx.o: ../../../../src/parsec/g_sfx.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/aud_glob.o: ../../../../src/parsec/aud_glob.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/m_logo.o: ../../../../src/parsec/m_logo.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/e_mouse.o: ../../../../src/parsec/e_mouse.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/aud_game.o: ../../../../src/parsec/aud_game.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/net_util_cl.o: ../../../../src/parsec/net_util_cl.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/net_glob.o: ../../../../src/parsec/net_glob.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/h_frmplt.o: ../../../../src/parsec/h_frmplt.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/net_gmsv.o: ../../../../src/parsec/net_gmsv.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/con_cani.o: ../../../../src/parsec/con_cani.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/img_3df.o: ../../../../src/parsec/img_3df.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/m_list.o: ../../../../src/parsec/m_list.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/vid_init.o: ../../../../src/parsec/vid_init.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/snd_api.o: ../../../../src/parsec/snd_api.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/e_colani.o: ../../../../src/parsec/e_colani.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/vsdl_buffo.o: ../../../../src/parsec/vsdl_buffo.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/vid_glob.o: ../../../../src/parsec/vid_glob.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/isdl_mouse.o: ../../../../src/parsec/isdl_mouse.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/net_pckt.o: ../../../../src/parsec/net_pckt.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/g_boot.o: ../../../../src/parsec/g_boot.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/obj_comm.o: ../../../../src/parsec/obj_comm.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/m_main.o: ../../../../src/parsec/m_main.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ro_patch.o: ../../../../src/parsec/ro_patch.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/img_load.o: ../../../../src/parsec/img_load.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/d_misc.o: ../../../../src/parsec/d_misc.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/g_swarm.o: ../../../../src/parsec/g_swarm.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/img_supp.o: ../../../../src/parsec/img_supp.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/vsdl_ogl.o: ../../../../src/parsec/vsdl_ogl.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/e_demo.o: ../../../../src/parsec/e_demo.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/obj_part.o: ../../../../src/parsec/obj_part.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/do_iter.o: ../../../../src/parsec/do_iter.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/img_tga.o: ../../../../src/parsec/img_tga.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/snd_wav.o: ../../../../src/parsec/snd_wav.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/net_conn.o: ../../../../src/parsec/net_conn.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/t_pack.o: ../../../../src/parsec/t_pack.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ro_perf.o: ../../../../src/parsec/ro_perf.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/e_events.o: ../../../../src/parsec/e_events.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/h_strmap.o: ../../../../src/parsec/h_strmap.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ro_poly.o: ../../../../src/parsec/ro_poly.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/inp_glob.o: ../../../../src/parsec/inp_glob.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/net_univ.o: ../../../../src/parsec/net_univ.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/m_button.o: ../../../../src/parsec/m_button.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/vid_supp.o: ../../../../src/parsec/vid_supp.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/con_aux.o: ../../../../src/parsec/con_aux.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/con_main.o: ../../../../src/parsec/con_main.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/con_say.o: ../../../../src/parsec/con_say.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/net_rmev.o: ../../../../src/parsec/net_rmev.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/net_peer.o: ../../../../src/parsec/net_peer.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/e_supp.o: ../../../../src/parsec/e_supp.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/h_text.o: ../../../../src/parsec/h_text.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/e_global.o: ../../../../src/parsec/e_global.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/obj_ctrl.o: ../../../../src/parsec/obj_ctrl.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/con_rc.o: ../../../../src/parsec/con_rc.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/con_conf.o: ../../../../src/parsec/con_conf.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/g_stars.o: ../../../../src/parsec/g_stars.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/img_api.o: ../../../../src/parsec/img_api.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/g_bot_cl.o: ../../../../src/parsec/g_bot_cl.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/con_info.o: ../../../../src/parsec/con_info.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/net_rmev_gmsv.o: ../../../../src/parsec/net_rmev_gmsv.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/e_color.o: ../../../../src/parsec/e_color.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/h_cockpt.o: ../../../../src/parsec/h_cockpt.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/img_jpg.o: ../../../../src/parsec/img_jpg.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/e_texani.o: ../../../../src/parsec/e_texani.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/e_shader.o: ../../../../src/parsec/e_shader.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/g_stgate.o: ../../../../src/parsec/g_stgate.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/g_vapor.o: ../../../../src/parsec/g_vapor.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/vsdl_inito.o: ../../../../src/parsec/vsdl_inito.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/sys_bind.o: ../../../../src/parsec/sys_bind.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/g_global.o: ../../../../src/parsec/g_global.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/vsdl_suppo.o: ../../../../src/parsec/vsdl_suppo.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/net_prediction.o: ../../../../src/parsec/net_prediction.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/isdl_supp.o: ../../../../src/parsec/isdl_supp.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/img_conv.o: ../../../../src/parsec/img_conv.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/inp_comm.o: ../../../../src/parsec/inp_comm.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/con_com.o: ../../../../src/parsec/con_com.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/net_rmev_peer.o: ../../../../src/parsec/net_rmev_peer.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/aud_supp.o: ../../../../src/parsec/aud_supp.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/aud_sdlmixer.o: ../../../../src/parsec/aud_sdlmixer.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/r_glob.o: ../../../../src/parsec/r_glob.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/con_int.o: ../../../../src/parsec/con_int.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/inp_init.o: ../../../../src/parsec/inp_init.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/con_tani.o: ../../../../src/parsec/con_tani.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/net_serv.o: ../../../../src/parsec/net_serv.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/isdl_joy.o: ../../../../src/parsec/isdl_joy.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/g_supp.o: ../../../../src/parsec/g_supp.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/g_wfx.o: ../../../../src/parsec/g_wfx.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/vid_plug.o: ../../../../src/parsec/vid_plug.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/obj_xtra.o: ../../../../src/parsec/obj_xtra.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/net_game_gmsv.o: ../../../../src/parsec/net_game_gmsv.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/e_loader.o: ../../../../src/parsec/e_loader.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/sys_conv.o: ../../../../src/parsec/sys_conv.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/g_explod.o: ../../../../src/parsec/g_explod.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/m_viewer.o: ../../../../src/parsec/m_viewer.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/ro_sfx.o: ../../../../src/parsec/ro_sfx.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/net_udp.o: ../../../../src/parsec/net_udp.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/nw_udp.o: ../../../../src/parsec/nw_udp.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/part_api.o: ../../../../src/parsec/part_api.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/nl_udp.o: ../../../../src/parsec/nl_udp.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/g_laser.o: ../../../../src/parsec/g_laser.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/g_gameloop.o: ../../../../src/parsec/g_gameloop.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/net_game.o: ../../../../src/parsec/net_game.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/do_misc.o: ../../../../src/parsec/do_misc.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/h_drwhud.o: ../../../../src/parsec/h_drwhud.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/obj_vani.o: ../../../../src/parsec/obj_vani.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/g_cloud.o: ../../../../src/parsec/g_cloud.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/g_shkwav.o: ../../../../src/parsec/g_shkwav.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/inp_user.o: ../../../../src/parsec/inp_user.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/part_def.o: ../../../../src/parsec/part_def.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/e_callbk.o: ../../../../src/parsec/e_callbk.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/obj_game.o: ../../../../src/parsec/obj_game.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/con_std.o: ../../../../src/parsec/con_std.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/e_level.o: ../../../../src/parsec/e_level.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/con_list.o: ../../../../src/parsec/con_list.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/g_telep.o: ../../../../src/libparsec/g_telep.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/sl_err.o: ../../../../src/parsec/sl_err.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/sl_main.o: ../../../../src/parsec/sl_main.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/d_glob.o: ../../../../src/parsec/d_glob.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/obj_iter.o: ../../../../src/parsec/obj_iter.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/con_load.o: ../../../../src/parsec/con_load.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/obj_ani.o: ../../../../src/parsec/obj_ani.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/net_game_peer.o: ../../../../src/parsec/net_game_peer.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/e_record.o: ../../../../src/parsec/e_record.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/part_sys.o: ../../../../src/parsec/part_sys.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/part_ani.o: ../../../../src/parsec/part_ani.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/h_radar.o: ../../../../src/parsec/h_radar.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/inp_sdl.o: ../../../../src/parsec/inp_sdl.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/g_camera.o: ../../../../src/parsec/g_camera.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/e_getopt.o: ../../../../src/parsec/e_getopt.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/h_global.o: ../../../../src/parsec/h_global.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/e_draw.o: ../../../../src/parsec/e_draw.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/sl_opt.o: ../../../../src/parsec/sl_opt.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/con_ext.o: ../../../../src/parsec/con_ext.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/con_path.o: ../../../../src/parsec/con_path.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/do_patch.o: ../../../../src/parsec/do_patch.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/do_bmap.o: ../../../../src/parsec/do_bmap.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/obj_coll.o: ../../../../src/parsec/obj_coll.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/con_act.o: ../../../../src/parsec/con_act.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/h_supp.o: ../../../../src/parsec/h_supp.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"
$(OBJDIR)/aud_comm.o: ../../../../src/parsec/aud_comm.cpp
	@echo $(notdir $<)
	$(SILENT) $(CXX) $(CXXFLAGS) -o "$@" -c "$<"

-include $(OBJECTS:%.o=%.d)
