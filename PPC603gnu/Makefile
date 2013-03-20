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
PRJ_ROOT_DIR := $(WS_ROOT_DIR)/Rootbeer



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
PROJECT_TARGETS = Rootbeer/$(MODE_DIR)/Rootbeer.out \
	 Rootbeer_partialImage/$(MODE_DIR)/Rootbeer_partialImage.o


#Rules

# Rootbeer
ifeq ($(DEBUG_MODE),1)
Rootbeer/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
Rootbeer/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
Rootbeer/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
Rootbeer/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
Rootbeer/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
Rootbeer/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
Rootbeer/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
Rootbeer/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
Rootbeer/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
Rootbeer/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
Rootbeer/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
Rootbeer/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
Rootbeer/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
Rootbeer/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
Rootbeer/$(MODE_DIR)/% : IDE_DEFINES = 
Rootbeer/$(MODE_DIR)/% : PROJECT_TYPE = DKM
Rootbeer/$(MODE_DIR)/% : DEFINES = 
Rootbeer/$(MODE_DIR)/% : EXPAND_DBG = 0
Rootbeer/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
Rootbeer/$(MODE_DIR)/% : CPU = PPC603
Rootbeer/$(MODE_DIR)/% : TOOL_FAMILY = gnu
Rootbeer/$(MODE_DIR)/% : TOOL = gnu
Rootbeer/$(MODE_DIR)/% : TOOL_PATH = 
Rootbeer/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
Rootbeer/$(MODE_DIR)/% : LIBPATH = 
Rootbeer/$(MODE_DIR)/% : LIBS = 
Rootbeer/$(MODE_DIR)/% : OBJ_DIR := Rootbeer/$(MODE_DIR)

OBJECTS_Rootbeer = Rootbeer_partialImage/$(MODE_DIR)/Rootbeer_partialImage.o

Rootbeer/$(MODE_DIR)/Rootbeer.out : $(OBJECTS_Rootbeer)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@";rm -f "$@";nmppc $(OBJECTS_Rootbeer) $(IDE_LIBRARIES) | tclsh $(WIND_BASE)/host/resource/hutils/tcl/munch.tcl -c ppc > $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc $(DEBUGFLAGS_Linker) $(CC_ARCH_SPEC) -fdollars-in-identifiers -Wall $(ADDED_CFLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES)  -o $(OBJ_DIR)/ctdt.o -c $(OBJ_DIR)/ctdt.c; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X -T $(WIND_BASE)/target/h/tool/gnu/ldscripts/link.OUT -o "$@" $(OBJ_DIR)/ctdt.o $(OBJECTS_Rootbeer) $(IDE_LIBRARIES) $(LIBPATH) $(LIBS)  $(ADDED_LIBPATH) $(ADDED_LIBS) && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

Rootbeer/$(MODE_DIR)/Rootbeer_compile_file : $(FILE) ;

_clean :: Rootbeer/$(MODE_DIR)/Rootbeer_clean

Rootbeer/$(MODE_DIR)/Rootbeer_clean : 
	$(TRACE_FLAG)if [ -d "Rootbeer" ]; then cd "Rootbeer"; rm -rf $(MODE_DIR); fi


# Rootbeer_partialImage
ifeq ($(DEBUG_MODE),1)
Rootbeer_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -g
Rootbeer_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -g
Rootbeer_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -g
Rootbeer_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
Rootbeer_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
Rootbeer_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -g
else
Rootbeer_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C-Compiler = -O2 -fstrength-reduce -fno-builtin
Rootbeer_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_C++-Compiler = -O2 -fstrength-reduce -fno-builtin
Rootbeer_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Linker = -O2 -fstrength-reduce -fno-builtin
Rootbeer_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Partial-Image-Linker = 
Rootbeer_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Librarian = 
Rootbeer_partialImage/$(MODE_DIR)/% : DEBUGFLAGS_Assembler = -O2 -fstrength-reduce -fno-builtin
endif
Rootbeer_partialImage/$(MODE_DIR)/% : IDE_INCLUDES = -I$(WIND_BASE)/target/h -I$(WIND_BASE)/target/h/WPILib -I$(WIND_BASE)/target/h/wrn/coreip 
Rootbeer_partialImage/$(MODE_DIR)/% : IDE_LIBRARIES = $(WIND_BASE)/target/lib/WPILib.a 
Rootbeer_partialImage/$(MODE_DIR)/% : IDE_DEFINES = 
Rootbeer_partialImage/$(MODE_DIR)/% : PROJECT_TYPE = DKM
Rootbeer_partialImage/$(MODE_DIR)/% : DEFINES = 
Rootbeer_partialImage/$(MODE_DIR)/% : EXPAND_DBG = 0
Rootbeer_partialImage/$(MODE_DIR)/% : VX_CPU_FAMILY = ppc
Rootbeer_partialImage/$(MODE_DIR)/% : CPU = PPC603
Rootbeer_partialImage/$(MODE_DIR)/% : TOOL_FAMILY = gnu
Rootbeer_partialImage/$(MODE_DIR)/% : TOOL = gnu
Rootbeer_partialImage/$(MODE_DIR)/% : TOOL_PATH = 
Rootbeer_partialImage/$(MODE_DIR)/% : CC_ARCH_SPEC = -mcpu=603 -mstrict-align -mno-implicit-fp -mlongcall
Rootbeer_partialImage/$(MODE_DIR)/% : LIBPATH = 
Rootbeer_partialImage/$(MODE_DIR)/% : LIBS = 
Rootbeer_partialImage/$(MODE_DIR)/% : OBJ_DIR := Rootbeer_partialImage/$(MODE_DIR)

Rootbeer_partialImage/$(MODE_DIR)/Objects/Rootbeer/MyRobot.o : $(PRJ_ROOT_DIR)/MyRobot.cpp $(FORCE_FILE_BUILD)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc $(DEBUGFLAGS_C++-Compiler) $(CC_ARCH_SPEC) -ansi -Wall  -MD -MP -mlongcall $(ADDED_C++FLAGS) $(IDE_INCLUDES) $(ADDED_INCLUDES) -DCPU=$(CPU) -DTOOL_FAMILY=$(TOOL_FAMILY) -DTOOL=$(TOOL) -D_WRS_KERNEL   $(DEFINES) -o "$@" -c "$<"


OBJECTS_Rootbeer_partialImage = Rootbeer_partialImage/$(MODE_DIR)/Objects/Rootbeer/MyRobot.o

Rootbeer_partialImage/$(MODE_DIR)/Rootbeer_partialImage.o : $(OBJECTS_Rootbeer_partialImage)
	$(TRACE_FLAG)if [ ! -d "`dirname "$@"`" ]; then mkdir -p "`dirname "$@"`"; fi;echo "building $@"; $(TOOL_PATH)ccppc -r -nostdlib -Wl,-X  -o "$@" $(OBJECTS_Rootbeer_partialImage) $(LIBPATH) $(LIBS) $(ADDED_LIBPATH) $(ADDED_LIBS)  && if [ "$(EXPAND_DBG)" = "1" ]; then plink "$@";fi

Rootbeer_partialImage/$(MODE_DIR)/Rootbeer_partialImage_compile_file : $(FILE) ;

_clean :: Rootbeer_partialImage/$(MODE_DIR)/Rootbeer_partialImage_clean

Rootbeer_partialImage/$(MODE_DIR)/Rootbeer_partialImage_clean : 
	$(TRACE_FLAG)if [ -d "Rootbeer_partialImage" ]; then cd "Rootbeer_partialImage"; rm -rf $(MODE_DIR); fi

force : 

DEP_FILES := Rootbeer_partialImage/$(MODE_DIR)/Objects/Rootbeer/MyRobot.d
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
