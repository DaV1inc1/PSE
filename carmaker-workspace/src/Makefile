#******************************************************************************
#*  CarMaker - Version 14.0.1
#*  Virtual Test Driving
#*
#*  Copyright ©1998-2025 IPG Automotive GmbH. All rights reserved.
#*  www.ipg-automotive.com
#******************************************************************************
#**
#**  Application Makefile
#**  Run with 'make V=1 ...' for a verbose build.
#**
#******************************************************************************

include /tools/carmaker/CM14/carmaker/linux64-14.0.1/include/MakeDefs.linux64

APP_VER =		"Car_Generic <insert.your.version.no>"
APP_NAME =		CarMaker.$(ARCH)$(EXE_EXT)

#OPT_CFLAGS =		-g -O1

LD_LIBS =		$(CAR_LIB) \
			$(CARMAKER_LIB) $(DRIVER_LIB) $(ROAD_LIB) $(TIRE_LIB) $(MIO_LIB)
OBJS =			CM_Main.o CM_Vehicle.o User.o IO.o

# Paths to ROS workspaces (relative from project directory)
ROS1_WS_DIR     ?= ros1_ws
ROS2_WS_DIR     ?= ros2_ws

# Uncomment to define your preferred ROS distro for each workspace,
# otherwise /opt/ros/ros1 or /opt/ros/ros2 is used
#ROS1_WS_ENV     ?= ROS_DISTRO=melodic
ROS2_WS_ENV     ?= ROS_DISTRO=humble

# CarMaker extension CMCppIF (provided by IPG)
APP_VER         := "$(subst ",,$(APP_VER)) with CMRosIF"
DEF_CFLAGS      += -DWITH_CMCPPIF
LD_LIBS_OS      += -lcmcppifloader-$(ARCH)
LDFLAGS         += -L./../lib/
LDFLAGS         += -Wl,-rpath,'$$ORIGIN/../lib/'
INC_CFLAGS      += -I../include
CFLAGS          += -rdynamic
CXXFLAGS        += -rdynamic

# Prepend local include/library directory to include path:
# PREINC_CFLAGS +=		-I../include -I../lib/$(ARCH) -I../lib

# Append local include/library directory to include path:
# INC_CFLAGS +=		-I../include -I../lib/$(ARCH) -I../lib


### Linking with RTW-built Simulink models

#MATSUPP_MATVER =	R2021b
#LD_LIBS +=		$(MATSUPP_LIB)


# @@PLUGIN-BEGIN-LIBS@@ - Automatically generated code - don't edit!
# @@PLUGIN-END@@

### END (Linking with RTW-built Simulink models)


default:	$(APP_NAME)
$(APP_NAME):	$(OBJS_$(ARCH)) $(OBJS) $(LD_LIBS_MK) app_tmp.o
	$(QECHO) " LD     $@"
	$Q $(CC) $(CFLAGS) $(LDFLAGS) -o $@ \
		$(OBJS_$(ARCH)) $(OBJS) $(LD_LIBS) $(LD_LIBS_OS) \
		app_tmp.o
	$(SET_EXE_PERMISSIONS) $@


install: $(APP_NAME)
	$(INSTALL_APP) $(APP_NAME) $(ARCH)

symlink-install: $(APP_NAME)
	$(QECHO) " LN     $(APP_NAME)"
	$Q mkdir -p ../bin
	$Q ln -rsf $(APP_NAME) ../bin/

clean:
	-rm -f 	*~ *% *.o core app_tmp.c .depend

app_tmp.c: Makefile $(OBJS_$(ARCH)) $(OBJS) $(LD_LIBS_MK)
	$(QECHO) " MK     $@"
	$Q $(CREATE_INFO_CMD)

depend .depend: Makefile
	$(QECHO) " MK     $@"
	@echo -n "" >.depend
ifneq ($(wildcard *.c),)
	$Q-$(CC)  $(CFLAGS)   $(DEPCFLAGS)   *.c   >>.depend 2>/dev/null
endif
ifneq ($(wildcard *.cpp),)
	$Q-$(CXX) $(CXXFLAGS) $(DEPCXXFLAGS) *.cpp >>.depend 2>/dev/null
endif
include .depend

cm-ros1: symlink-install ros1_ws ../CMStart.sh
cm-ros2: symlink-install ros2_ws ../CMStart.sh

XMAKER:=CM
ifneq (,$(findstring $(TRUCK_LIB),$(LD_LIBS)))
    XMAKER:=TM
else ifneq (,$(findstring $(MCYCLE_LIB),$(LD_LIBS)))
    XMAKER:=MM
endif

../CMStart.sh:
	@echo " CRT    $@"
	$Q if [ -e "$@" ]; then echo "'$@' already exists"; false; fi
	@( \
	echo "#!/bin/bash"; \
	echo "source ros_setup.bash \$${1:-$(patsubst cm-ros%,%,$(firstword $(filter cm-ros%,$(MAKECMDGOALS))))}"; \
	echo "$(XMAKER)_Office-$(CARMAKER_VER) . -apphost localhost -ext GUI/CMExt-CMRosIF.mod"; \
	) > $@
	$Q chmod +x $@

ADD_CMAKE_ARGS:=
CMAKE_ARGS:=-DCARMAKER_VER:STRING=${CARMAKER_VER} ${ADD_CMAKE_ARGS}

ros1_ws:
	$(QECHO) " MK     $@"
	$Q cd ./../${ROS1_WS_DIR} && $(ROS1_WS_ENV) ./build.sh '${CMAKE_ARGS}'

clean-ros1_ws:
	-rm -rf ./../${ROS1_WS_DIR}/build
	-rm -rf ./../${ROS1_WS_DIR}/devel
	-rm -rf ./../${ROS1_WS_DIR}/install

ros2_ws:
	$(QECHO) " MK     $@"
	$Q cd ./../${ROS2_WS_DIR} && \
	   $(ROS2_WS_ENV) ./build.sh '--cmake-args ${CMAKE_ARGS} --no-warn-unused-cli'

clean-ros2_ws:
	-rm -rf ./../${ROS2_WS_DIR}/build ./../${ROS2_WS_DIR}/install

.PHONY: default install clean depend ros1_ws ros2_ws clean-%
