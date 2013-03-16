# Wind River Workbench generated Makefile.
# Do not edit!!!
#
# The file ".wrmakefile" is the template used by the Wind River Workbench to
# generate the makefiles of this project. Add user-specific build targets and
# make rules only(!) in this project's ".wrmakefile" file. These will then be
# automatically dumped into the makefiles.

WIND_HOME := $(subst \,/,$(WIND_HOME))
WIND_BASE := $(subst \,/,$(WIND_BASE))
WIND_USR := $(subst \,/,$(WIND_USR))

all : pre_build main_all post_build

_clean ::
	@echo "make: removing targets and objects of `pwd`"

TRACE=0
TRACEON=$(TRACE:0=@)
TRACE_FLAG=$(TRACEON:1=)

MAKEFILE := Makefile

FLEXIBLE_BUILD := 1

BUILD_SPEC = PPC603gnu
DEBUG_MODE = 1
ifeq ($(DEBUG_MODE),1)
MODE_DIR := Debug
else
MODE_DIR := NonDebug
endif
OBJ_DIR := .
WS_ROOT_DIR := C:/Users/Vargoal/Documents/GitHub
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/JeffBase



#Global Build Macros
PROJECT_TYPE = DKM
DEFINES = 
EXPAND_DBG = 0


#BuildSpec specific Build Macros
VX_CPU_FAMILY = ppc
CPU = PPC603
TOOL_FAMILY = gnu
TOOL = gnu
TOOL_PATH = 
CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
LIBPATH = 
LIBS = 

IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 

IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 

IDE_DEFINES = 



#BuildTool flags
ifeq ($(DEBUG_MODE),1)
DEBUGFLAGS_C-Compiler = -g
DEBUGFLAGS_C++-Compiler = -g
DEBUGFLAGS_Linker = -g
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -g
else
DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
DEBUGFLAGS_Partial-Image-Linker = 
DEBUGFLAGS_Librarian = 
DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif


#Project Targets
PROJECT_TARGETS = JeffBase/$(MODE_DIR)/JeffBase.out \
	 JeffBase_partialImage/$(MODE_DIR)/JeffBase_partialImage.o


#Rules

# JeffBase
ifeq ($(DEBUG_MODE),1)
JeffBase/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
JeffBase/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
JeffBase/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
JeffBase/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
JeffBase/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
JeffBase/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
JeffBase/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
JeffBase/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
JeffBase/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
JeffBase/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
JeffBase/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
JeffBase/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
JeffBase/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
JeffBase/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
JeffBase/$(MODE_DIR)/% : IDE_DEFINES = 
JeffBase/$(MODE_DIR)/% : PROJECT_TYPE = DKM
JeffBase/$(MODE_DIR)/% : DEFINES = 
JeffBase/$(MODE_DIR)/% : EXPAND_DBG = 0
JeffBase/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
JeffBase/$(MODE_DIR)/% : CPU = PPC603
JeffBase/$(MODE_DIR)/% : TOOL_FAMILY = gnu
JeffBase/$(MODE_DIR)/% : TOOL = gnu
JeffBase/$(MODE_DIR)/% : TOOL_PATH = 
JeffBase/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
JeffBase/$(MODE_DIR)/% : LIBPATH = 
JeffBase/$(MODE_DIR)/% : LIBS = 
JeffBase/$(MODE_DIR)/% : OBJ_DIR := JeffBase/$(MODE_DIR)

OBJECTS_JeffBase = JeffBase_partialImage/$(MODE_DIR)/JeffBase_partialImage.o

JeffBase/$(MODE_DIR)/JeffBase.out : $(OBJECTS_JeffBase)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_JeffBase) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_JeffBase) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

JeffBase/$(MODE_DIR)/JeffBase_compile_file : $(FILE) ;

_clean :: JeffBase/$(MODE_DIR)/JeffBase_clean

JeffBase/$(MODE_DIR)/JeffBase_clean : 
	$(TRACE_FLAG)if [ -d "JeffBase" ]; then cd "JeffBase"; rm -rf $(MODE_DIR); fi


# JeffBase_partialImage
ifeq ($(DEBUG_MODE),1)
JeffBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
JeffBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
JeffBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
JeffBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
JeffBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
JeffBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
JeffBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
JeffBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
JeffBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
JeffBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
JeffBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
JeffBase_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
JeffBase_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
JeffBase_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
JeffBase_partialImage/$(MODE_DIR)/% : IDE_DEFINES = 
JeffBase_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
JeffBase_partialImage/$(MODE_DIR)/% : DEFINES = 
JeffBase_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
JeffBase_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
JeffBase_partialImage/$(MODE_DIR)/% : CPU = PPC603
JeffBase_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
JeffBase_partialImage/$(MODE_DIR)/% : TOOL = gnu
JeffBase_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
JeffBase_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
JeffBase_partialImage/$(MODE_DIR)/% : LIBPATH = 
JeffBase_partialImage/$(MODE_DIR)/% : LIBS = 
JeffBase_partialImage/$(MODE_DIR)/% : OBJ_DIR := JeffBase_partialImage/$(MODE_DIR)

JeffBase_partialImage/$(MODE_DIR)/Objects/JeffBase/EnhancedJoystick.o : $(PRJ_ROOT_DIR)/EnhancedJoystick.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


JeffBase_partialImage/$(MODE_DIR)/Objects/JeffBase/EnhancedRobotDrive.o : $(PRJ_ROOT_DIR)/EnhancedRobotDrive.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


JeffBase_partialImage/$(MODE_DIR)/Objects/JeffBase/EnhancedShooter.o : $(PRJ_ROOT_DIR)/EnhancedShooter.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


JeffBase_partialImage/$(MODE_DIR)/Objects/JeffBase/autonomous.o : $(PRJ_ROOT_DIR)/autonomous.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


JeffBase_partialImage/$(MODE_DIR)/Objects/JeffBase/main.o : $(PRJ_ROOT_DIR)/main.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


JeffBase_partialImage/$(MODE_DIR)/Objects/JeffBase/updateRegistry.o : $(PRJ_ROOT_DIR)/updateRegistry.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_JeffBase_partialImage = JeffBase_partialImage/$(MODE_DIR)/Objects/JeffBase/EnhancedJoystick.o \
	 JeffBase_partialImage/$(MODE_DIR)/Objects/JeffBase/EnhancedRobotDrive.o \
	 JeffBase_partialImage/$(MODE_DIR)/Objects/JeffBase/EnhancedShooter.o \
	 JeffBase_partialImage/$(MODE_DIR)/Objects/JeffBase/autonomous.o \
	 JeffBase_partialImage/$(MODE_DIR)/Objects/JeffBase/main.o \
	 JeffBase_partialImage/$(MODE_DIR)/Objects/JeffBase/updateRegistry.o

JeffBase_partialImage/$(MODE_DIR)/JeffBase_partialImage.o : $(OBJECTS_JeffBase_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_JeffBase_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

JeffBase_partialImage/$(MODE_DIR)/JeffBase_partialImage_compile_file : $(FILE) ;

_clean :: JeffBase_partialImage/$(MODE_DIR)/JeffBase_partialImage_clean

JeffBase_partialImage/$(MODE_DIR)/JeffBase_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "JeffBase_partialImage" ]; then cd "JeffBase_partialImage"; rm -rf $(MODE_DIR); fi

force : 

DEP_FILES := JeffBase_partialImage/$(MODE_DIR)/Objects/JeffBase/EnhancedJoystick.d JeffBase_partialImage/$(MODE_DIR)/Objects/JeffBase/EnhancedRobotDrive.d JeffBase_partialImage/$(MODE_DIR)/Objects/JeffBase/EnhancedShooter.d \
	 JeffBase_partialImage/$(MODE_DIR)/Objects/JeffBase/autonomous.d JeffBase_partialImage/$(MODE_DIR)/Objects/JeffBase/main.d JeffBase_partialImage/$(MODE_DIR)/Objects/JeffBase/updateRegistry.d
-include $(DEP_FILES)



-include $(PRJ_ROOT_DIR)/*.makefile

-include *.makefile

main_all : external_build $(PROJECT_TARGETS)
	@echo "make: built targets of `pwd`"

# entry point for extending the build
external_build ::
	@echo ""

# main entry point for pre processing prior to the build
pre_build :: $(PRE_BUILD_STEP) generate_sources
	@echo ""

# entry point for generating sources prior to the build
generate_sources ::
	@echo ""

# main entry point for post processing after the build
post_build :: $(POST_BUILD_STEP) deploy_output
	@echo ""

# entry point for deploying output after the build
deploy_output ::
	@echo ""

clean :: external_clean $(CLEAN_STEP) _clean

# entry point for extending the build clean
external_clean ::
	@echo ""
