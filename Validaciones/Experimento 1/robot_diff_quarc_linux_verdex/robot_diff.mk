# Copyright 2011 Quanser, Inc.
#
# File    : quarc_linux_verdex.tmf   $Revision: 1.0.0.0 $
#
# Abstract:
#	Real-Time Workshop template makefile for building a Linux ARM-based
#	stand-alone real-time version of Simulink model using
#	generated C code.
#
# 	This makefile attempts to conform to the guidelines specified in the
# 	IEEE Std 1003.2-1992 (POSIX) standard. It is designed to be used
#       with GNU Make which is located in matlabroot/rtw/bin.
#
# 	Note that this template is automatically customized by the Real-Time
#	Workshop build procedure to create "<model>.mk"
#
#   The following defines can be used to modify the behavior of the build:
#     OPT_OPTS       - Optimization options. Default is -O. To enable
#                          debugging specify as OPT_OPTS=-g.
#                          Because of optimization problems in IBM_RS,
#                          default is no-optimization.
#     CPP_OPTS       - C++ compiler options.
#     OPTS           - User specific compile options.
#     USER_SRCS      - Additional user sources, such as files needed by
#                      S-functions.
#     USER_INCLUDES  - Additional include paths
#                      (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see quarc_linux_verdex.tlc

#------------------------ Macros read by make_rtw ------------------------------
#
# The following macros are read by the Real-Time Workshop build procedure:
#
#  MAKECMD          - This is the command used to invoke the make utility
#  MAKEFILE_FILESEP - Replaces all instances of the current file separator 
#                     with the given one. See help for updateFileSeparator.
#  HOST             - What platform this template makefile is targeted for
#                     (i.e. PC or UNIX)
#  BUILD            - Invoke make from the Real-Time Workshop build procedure
#                     (yes/no)?
#  SYS_TARGET_FILE  - Name of system target file.

MAKECMD          = make
MAKEFILE_FILESEP = /
HOST             = PC
BUILD            = yes
SYS_TARGET_FILE  = quarc_linux_verdex.tlc
BUILD_SUCCESS    = \#\#\# Created

#---------------------- Tokens expanded by make_rtw ----------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# Real-Time Workshop build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to were MATLAB is installed.
#  S_FUNCTIONS         - List of S-functions.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link.
#  SOLVER              - Solver source file name
#  NUMST               - Number of sample times
#  TID01EQ             - yes (1) or no (0): Are sampling rates of continuous task
#                        (tid=0) and 1st discrete task equal.
#  NCSTATES            - Number of continuous states
#  COMPUTER            - Computer type. See the MATLAB computer command.
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  EXT_MODE            - yes (1) or no (0): Build for external mode
#  TMW_EXTMODE_TESTING - yes (1) or no (0): Build ext_test.c for external mode
#                        testing.
#  EXTMODE_TRANSPORT   - Index of transport mechanism (e.g. tcpip, serial) for extmode
#  EXTMODE_STATIC      - yes (1) or no (0): Use static instead of dynamic mem alloc.
#  EXTMODE_STATIC_SIZE - Size of static memory allocation buffer.
#  GEN_MDLREF_SFCN     - (1/0): are we generating model reference wrapper s-function
#  TGT_FCN_LIB         - Target Funtion library to use
#  MODELREFS           - List of referenced models

MODEL                = robot_diff
MODULES              = robot_diff_data.c robot_diff_main.c rtGetInf.c rtGetNaN.c rt_nonfinite.c 
MAKEFILE             = robot_diff.mk
MATLAB_ROOT          = C:/Program Files/MATLAB/R2011b
ALT_MATLAB_ROOT      = C:/PROGRA~1/MATLAB/R2011b
MATLAB_BIN           = C:/Program Files/MATLAB/R2011b/bin
ALT_MATLAB_BIN       = C:/PROGRA~1/MATLAB/R2011b/bin
S_FUNCTIONS          = 
S_FUNCTIONS_LIB      = C:/PROGRA~1/Quanser/QUARC/lib/LINUX_~1/libhil.a C:/PROGRA~1/Quanser/QUARC/lib/LINUX_~1/LI5A2F~1.A C:/PROGRA~1/Quanser/QUARC/lib/LINUX_~1/LIBQUA~4.A C:/PROGRA~1/Quanser/QUARC/lib/LINUX_~1/LI5C03~1.A C:/PROGRA~1/Quanser/QUARC/lib/LINUX_~1/LIBQUA~3.A
SOLVER               = 
NUMST                = 2
TID01EQ              = 1
NCSTATES             = 0
COMPUTER             = PCWIN64
BUILDARGS            =  GENERATE_REPORT=0 MAT_FILE=0 DEBUG=0 DTE=0
MULTITASKING         = 0
EXT_MODE             = 1
TMW_EXTMODE_TESTING  = 0
EXTMODE_TRANSPORT    = 0
EXTMODE_STATIC       = 0
EXTMODE_STATIC_SIZE  = 1000000
RELEASE_VERSION      = R2011b
MEXEXT               = mexw64
TGT_FCN_LIB          = C89/C90 (ANSI)

MODELREFS            = 
SHARED_SRC           = 
SHARED_SRC_DIR       = 
SHARED_BIN_DIR       = 
SHARED_LIB           = 
TARGET_LANG_EXT      = c

#--------------------------- Model and reference models -----------------------
MODELLIB                  = robot_difflib.a
MODELREF_LINK_LIBS        = 
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ..
# NONE: standalone, SIM: modelref sim, RTW: modelref rtw
MODELREF_TARGET_TYPE       = NONE

#--------------------------- Additional options -------------------------------

ASSERTACTION     = "Stop model with an error"
HAVESTDIO        =  1
COMPILER_OPTION  = "LLVM-GCC"
USE_LLVM_BITCODE =  0
STRIPSYMBOLS     =  0
SHOW_TIMES       =  0

PRINT_EXTERNALFNCONSTANTS = 0
PRINT_CALLGRAPH           = 0
PRINT_FUNCTION            = 0
PRINT_CALLGRAPH_SCCS      = 0
PRINT_CFG_SCCS            = 0
PRINT_DEBUGINFO           = 0
PRINT_DOM_INFO            = 0
PRINT_MODULE              = 0
PRINT_USED_TYPES          = 0
TIME_PASSES               = 0
MODULE_VERIFY             = 0
ALIAS_ANALYSIS            = 0
GLOBALS_ANALYSIS          = 0
CODEGENPREPARE            = 0
STRIPDEADDEBUGINFO        = 0
ADCE                      = 0
BLOCKPLACEMENT            = 0
CONSTMERGE                = 0
DCE                       = 0
DAE                       = 0
DIE                       = 0
DSE                       = 0
DFA                       = 0
DGE                       = 0
GLOBALVARIABLEOPTIMIZER   = 0
SIMPLIFY_LIBCALLS         = 0
LOOP_DEPENDENCE_ANALYSIS  = 0
LOOPS                     = 0
SCALAR_EVOLUTION_ANALYSIS = 0
SCALAR_EV_BASED_ANALYSIS  = 0
CANONICALIZE_INDUCTION    = 0
LOOP_CLOSED_SSA           = 0
LOOP_INV_CODE_MOTION      = 0
DEAD_LOOP_DELETION        = 0
LOOP_STRENGTH_REDUCTION   = 0
ROTATE_LOOPS              = 0
UNROLL_LOOPS              = 0
UNSWITCH_LOOPS            = 0
BASIC_ALIAS_ANALYSIS      = 0
LIBCALL_ALIAS_ANALYSIS    = 0
REGIONS_ANALYSIS          = 0
FUNCTION_ATTRIBUTES       = 0
INTERNAL_GLOBAL_SYMBOLS   = 0
LOWER_SET_JUMP            = 0
MERGE_FUNCTIONS           = 0
UNIFY_FUNCTIONS           = 0
PARTIAL_SPECIALIZATION    = 0
SPLIT_GEPS                = 0
SRET_PROMOTION            = 0
TAIL_CALL_ELIMINATION     = 0
ALWAYS_INLINE             = 0
FUNCTION_INLINE           = 0
PARTIAL_INLINE            = 0
DEBUG_AA                  = 0
INST_COUNT                = 0
INTERVALS                 = 0
IV_USERS                  = 0
LINT_CHECK                = 0
MEMORY_CHECK              = 0
MODULE_DEBUG              = 0
ARG_PROMOTION             = 0
CONSTANT_PROPAGATION      = 0
COMBINE_INSTRUCTIONS      = 0
JUMP_THREADING            = 0
LOWER_SWITCH              = 0
REASSOCIATE_EXPRESSIONS   = 0
CUSTOM_COMPILER_OPTIONS   = 
CUSTOM_OPTIMIZER_OPTIONS  = 

#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif
ifneq ($(MATLAB_BIN),$(ALT_MATLAB_BIN))
MATLAB_BIN = $(ALT_MATLAB_BIN)
endif

#--------------------------- Tool Specifications -------------------------------

TARGET_PROCESSOR = verdex
include $(QUARC)/include/linux_arm_tools.mk

#------------------------------ Include Path -----------------------------------

MATLAB_INCLUDES = \
	-I$(MATLAB_ROOT)/simulink/include \
	-I$(MATLAB_ROOT)/extern/include \
	-I$(MATLAB_ROOT)/rtw/c/src \
	-I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common

# Additional file include paths
ADD_INCLUDES = \
	-IC:/Users/Kazemiro/OneDrive/TESIS_~1/PROGRA~1/Qbot/PROGRA~1/VALIDA~1/EXPERI~1/robot_diff_quarc_linux_verdex \
	-IC:/Users/Kazemiro/OneDrive/TESIS_~1/PROGRA~1/Qbot/PROGRA~1/VALIDA~1/EXPERI~1 \
	-IC:/Users/Kazemiro/OneDrive/Tesis_Diego_Cardenas/Programas/Qbot \
	-IC:/PROGRA~1/Quanser/QUARC/include \


SHARED_INCLUDES =
ifneq ($(SHARED_SRC_DIR),)
SHARED_INCLUDES = -I$(SHARED_SRC_DIR) 
endif

QUARC_INCLUDES = $(QUARC)/include

INCLUDES = -I. -I$(RELATIVE_PATH_TO_ANCHOR) -I$(QUARC_INCLUDES) $(MATLAB_INCLUDES) $(ADD_INCLUDES) $(USER_INCLUDES) \
	$(INSTRUMENT_INCLUDES)  $(MODELREF_INC_PATH) $(SHARED_INCLUDES)

#----------------------------- External mode -----------------------------------
# Uncomment -DVERBOSE to have information printed to stdout
# To add a new transport layer, see the comments in
#   <matlabroot>/toolbox/simulink/simulink/extmode_transports.m
ifeq ($(EXT_MODE),1)
  EXT_CC_OPTS = -DEXT_MODE -D$(COMPUTER) -DMODEL_URI="$(MODEL_URI)" -DVERBOSE
  EXT_LIB     =
  EXT_SRC     =
  LINT_EXT_COMMON_SRC =
  LINT_EXT_TCPIP_SRC  =
  ifeq ($(EXTMODE_TRANSPORT),0) # quarc_comm
    EXT_SRC =
    EXT_LIB = -lextmode_quarc_r2009a -lquanser_communications
    LINT_EXT_COMMON_SRC = ext_svr_quarc.c updown.c ext_work.c
    LINT_EXT_TCPIP_SRC  = ext_svr_quarc_transport.c
  endif
  ifeq ($(TMW_EXTMODE_TESTING),1)
    EXT_SRC     += ext_test.c
    EXT_CC_OPTS += -DTMW_EXTMODE_TESTING
  endif
  ifeq ($(EXTMODE_STATIC),1)
    EXT_SRC             += mem_mgr.c
    LINT_EXT_COMMON_SRC += mem_mgr.c
    EXT_CC_OPTS         += -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=$(EXTMODE_STATIC_SIZE)
  endif
endif

#
# .mat File Logging
#
ifeq ($(MAT_FILE),1)
LOG_OPTS  = -DMAT_FILE
endif

#----------------------------- Real-Time Model ---------------------------------
RTM_CC_OPTS = -DUSE_RTMODEL

#-------------------------------- C Flags --------------------------------------

# Optimization Options. The DEFAULT_OPT_OPTS macro depends on the build configuration.
OPT_OPTS = $(DEFAULT_OPT_OPTS)

# General User Options
OPTS =

# Compiler options, etc:
CC_OPTS = $(OPT_OPTS) $(OPTS) $(EXT_CC_OPTS) $(RTM_CC_OPTS) -march=armv5te -mtune=xscale -Wa,-mcpu=xscale

ifeq ($(ASSERTACTION), "Ignore")
  ASSERT_DEFINES = -DASSERTIONS=0
else 
  ifeq ($(ASSERTACTION), "Stop model with an error")
    ASSERT_DEFINES = -DASSERTIONS=1 -DDOASSERTS
  else 
    ifeq ($(ASSERTACTION), "Print assertion")
      ASSERT_DEFINES = -DASSERTIONS=2 -DDOASSERTS
    endif
  endif
endif

ifeq ($(HAVESTDIO),1)
STDIO_DEFINES = -DHAVESTDIO
else
STDIO_DEFINES =
endif

CPP_REQ_DEFINES = -DMODEL=$(MODEL) -DRT -DNUMST=$(NUMST) \
                  -DTID01EQ=$(TID01EQ) -DNCSTATES=$(NCSTATES) \
                  -DMULTITASKING=$(MULTITASKING) $(STDIO_DEFINES) \
                  -DVXWORKS -DQUARC -DTARGET_TYPE=linux_verdex -D_GUMSTIX \
                  $(ASSERT_DEFINES) $(OPT_DEFINES)

CFLAGS   = $(SYSROOT) $(CC_OPTS) $(ANSI_OPTS) $(CPP_REQ_DEFINES) $(INCLUDES)
CPPFLAGS = $(CPP_OPTS) $(CC_OPTS) $(CPP_ANSI_OPTS) $(CPP_REQ_DEFINES) $(INCLUDES)
LDFLAGS := $(SYSROOT) $(LDFLAGS) -L$(QUARC)/lib/linux_verdex

LLC_FLAGS   += $(CUSTOM_COMPILER_OPTIONS)
LLOPT_FLAGS += $(CUSTOM_OPTIMIZER_OPTIONS)

#-------------------------- Additional Libraries ------------------------------

# rtwmakecfg mechanism appears to fail for the Linux ARM target since the S_FUNCTIONS_LIB
# macro is not generated correctly. This shortcoming appears to be a bug in RTW.
# Hence, add additional libraries required here.

QUARC_LIBS = \
	-lquanser_runtime \
	-lquanser_common

SYSLIBS = $(EXT_LIB) $(QUARC_LIBS) -lrt -lpthread -ldl -lm

LIBS =
 

# See rtwmakecfg.m documentation

LIBS += $(S_FUNCTIONS_LIB) $(INSTRUMENT_LIBS)

#----------------------------- Source Files ------------------------------------

USER_SRCS =

USER_OBJS       = $(addsuffix .o, $(basename $(USER_SRCS)))
LOCAL_USER_OBJS = $(notdir $(USER_OBJS))

SRCS = $(MODULES) $(S_FUNCTIONS)

ifeq ($(MODELREF_TARGET_TYPE), NONE)
    PRODUCT            = $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL)$(TARGET_EXT)
    BIN_SETTING        = $(LD) $(LDFLAGS) -o $(PRODUCT)
    BUILD_PRODUCT_TYPE = "executable"
    SRCS              += $(MODEL).$(TARGET_LANG_EXT) $(MODEL)_main.c rt_sim.c $(EXT_SRC) $(SOLVER)
else
    # Model reference rtw target
    PRODUCT            = $(MODELLIB)
    BUILD_PRODUCT_TYPE = "library"
endif

ifneq ($(findstring .cpp,$(suffix $(SRCS), $(USER_SRCS))),)
  LD = $(CPP)
  SYSLIBS += $(CPP_SYS_LIBS) 
endif

OBJS      = $(addsuffix .o, $(basename $(SRCS))) $(USER_OBJS)
LINK_OBJS = $(sort $(addsuffix .o, $(basename $(SRCS))) $(LOCAL_USER_OBJS))

SHARED_SRC := $(wildcard $(SHARED_SRC))
SHARED_OBJS = $(addsuffix .o, $(basename $(SHARED_SRC)))

#------------- Test Compile using gcc -Wall to look for warnings ---------------
#
# DO_GCC_TEST=1 runs gcc with compiler warning flags on all the source files
# used in this build. This includes the generated code, and any user source
# files needed for the build and placed in this directory.
#
# See $(QUARC)/include/linux_arm_tools.mk for the definition of GCC_WARN_OPTS
GCC_TEST_CMD  := echo
GCC_TEST_OUT  := > nul:
ifeq ($(DO_GCC_TEST), 1)
  GCC_TEST := gcc -c -o nul: $(GCC_WARN_OPTS_MAX) $(CPP_REQ_DEFINES) \
                                     $(INCLUDES)
  GCC_TEST_CMD := echo; echo "\#\#\# GCC_TEST $(GCC_TEST) $<"; $(GCC_TEST)
  GCC_TEST_OUT := ; echo
endif

#----------------------------- Lint (sol2 only) --------------------------------

LINT_SRCS = $(MODEL)_main.c $(MATLAB_ROOT)/rtw/c/src/rt_sim.c
ifneq ($(SOLVER), )
  LINT_SRCS += $(MATLAB_ROOT)/rtw/c/src/$(SOLVER)
endif
ifneq ($(LINT_EXT_COMMON_SRC), )
  LINT_SRCS += $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/$(LINT_EXT_COMMON_SRC)
endif
ifneq ($(LINT_EXT_TCPIP_SRC), )
  LINT_SRCS += $(MATLAB_ROOT)/rtw/c/src/ext_mode/tcpip/$(LINT_EXT_TCPIP_SRC)
endif
LINT_SRCS += $(MODEL).$(TARGET_LANG_EXT) $(MODULES) $(USER_SRCS) $(S_FUNCTIONS)
LINTOPTSFILE = $(MODEL).lintopts

LINT_ERROFF1 = E_NAME_DEF_NOT_USED2,E_NAME_DECL_NOT_USED_DEF2
LINT_ERROFF2 = $(LINT_ERROFF1),E_FUNC_ARG_UNUSED
LINT_ERROFF  = $(LINT_ERROFF2),E_INDISTING_FROM_TRUNC2,E_NAME_USED_NOT_DEF2

# Define a BUILD_SUCCESS macro that accounts for the difference in escape
# characters between make and the shell.
BUILD_SUCCESS_EX := \$(BUILD_SUCCESS)

#--------------------------------- Rules ---------------------------------------
ifeq ($(MODELREF_TARGET_TYPE),NONE)
$(PRODUCT) : start_report $(OBJS) $(SHARED_LIB) $(LIBS) $(MODELREF_LINK_LIBS) show_report
	$(BIN_SETTING) $(LINK_OBJS) $(MODELREF_LINK_LIBS) $(SHARED_LIB) $(LIBS) $(SYSLIBS)
ifeq ($(STRIPSYMBOLS),1)
	$(STRIP) --strip-debug --strip-unneeded $(PRODUCT)
endif
	@echo $(BUILD_SUCCESS_EX) $(BUILD_PRODUCT_TYPE) $(MODEL)$(TARGET_EXT)
else
$(PRODUCT) : $(OBJS) $(SHARED_LIB)
	@rm -f $(MODELLIB)
	$(AR) ruvs $(MODELLIB) $(LINK_OBJS)
	@echo $(BUILD_SUCCESS_EX) $(MODELLIB)
	@echo $(BUILD_SUCCESS_EX) $(BUILD_PRODUCT_TYPE) $(MODEL)$(TARGET_EXT)
endif

ifneq ($(SHARED_SRC_DIR),)
$(SHARED_BIN_DIR)/%.o : $(SHARED_SRC_DIR)/%.c
	cd $(SHARED_BIN_DIR) && $(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $(notdir $?)

$(SHARED_BIN_DIR)/%.o : $(SHARED_SRC_DIR)/%.cpp
	cd $(SHARED_BIN_DIR) && $(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) $(notdir $?)
endif

ifeq ($(USE_LLVM_BITCODE),1)

LLVM_REPORT = 0
ifeq ($(PRINT_EXTERNALFNCONSTANTS),1)
    LLOPT_FLAGS += -print-externalfnconstants
    LLVM_REPORT = 1
endif
ifeq ($(PRINT_CALLGRAPH),1)
    LLOPT_FLAGS += -print-callgraph
    LLVM_REPORT = 1
endif
ifeq ($(PRINT_FUNCTION),1)
    LLOPT_FLAGS += -print-function
    LLVM_REPORT = 1
endif
ifeq ($(PRINT_CALLGRAPH_SCCS),1)
    LLOPT_FLAGS += -print-callgraph-sccs
    LLVM_REPORT = 1
endif
ifeq ($(PRINT_CFG_SCCS),1)
    LLOPT_FLAGS += -print-cfg-sccs
    LLVM_REPORT = 1
endif
ifeq ($(PRINT_DEBUGINFO),1)
    LLOPT_FLAGS += -print-dbginfo
    LLVM_REPORT = 1
endif
ifeq ($(PRINT_DOM_INFO),1)
    LLOPT_FLAGS += -print-dom-info
    LLVM_REPORT = 1
endif
ifeq ($(PRINT_MODULE),1)
    LLOPT_FLAGS += -print-module
    LLVM_REPORT = 1
endif
ifeq ($(PRINT_USED_TYPES),1)
    LLOPT_FLAGS += -print-used-types
    LLVM_REPORT = 1
endif
ifeq ($(TIME_PASSES),1)
    LLOPT_FLAGS += -time-passes
    LLVM_REPORT = 1
endif
ifeq ($(MODULE_VERIFY),1)
    LLOPT_FLAGS += -verify
    LLVM_REPORT = 1
endif
ifeq ($(ALIAS_ANALYSIS),1)
    LLOPT_FLAGS += -aa-eval
    LLVM_REPORT = 1
endif
ifeq ($(GLOBALS_ANALYSIS),1)
    LLOPT_FLAGS += -globalsmodref-aa
    LLVM_REPORT = 1
endif

ifeq ($(CODEGENPREPARE),1)
    LLOPT_FLAGS += -codegenprepare
    LLVM_REPORT = 1
endif

ifeq ($(STRIPDEADDEBUGINFO),1)
    LLOPT_FLAGS += -strip-dead-debug-info
    LLVM_REPORT = 1
endif

ifeq ($(ADCE),1)
    LLOPT_FLAGS += -adce
    LLVM_REPORT = 1
endif

ifeq ($(BLOCKPLACEMENT),1)
    LLOPT_FLAGS += -block-placement
    LLVM_REPORT = 1
endif
ifeq ($(CONSTMERGE),1)
    LLOPT_FLAGS += -constmerge
    LLVM_REPORT = 1
endif

ifeq ($(DCE),1)
    LLOPT_FLAGS += -dce
    LLVM_REPORT = 1
endif

ifeq ($(DAE),1)
    LLOPT_FLAGS += -deadargelim
    LLVM_REPORT = 1
endif

ifeq ($(DTE),1)
    LLOPT_FLAGS += -deadtypeelim
    LLVM_REPORT = 1
endif
ifeq ($(DIE),1)
    LLOPT_FLAGS += -die
    LLVM_REPORT = 1
endif
ifeq ($(DSE),1)
    LLOPT_FLAGS += -dse
    LLVM_REPORT = 1
endif
ifeq ($(DFA),1)
    LLOPT_FLAGS += -functionattrs
    LLVM_REPORT = 1
endif
ifeq ($(DGE),1)
    LLOPT_FLAGS += -globaldce
    LLVM_REPORT = 1
endif
ifeq ($(GLOBALVARIABLEOPTIMIZER),1)
    LLOPT_FLAGS += -globalopt
    LLVM_REPORT = 1
endif
ifeq ($(SIMPLIFY_LIBCALLS),1)
    LLOPT_FLAGS += -simplify-libcalls
    LLVM_REPORT = 1
endif
ifeq ($(LOOP_DEPENDENCE_ANALYSIS),1)
    LLOPT_FLAGS += -lda
    LLVM_REPORT = 1
endif
ifeq ($(LOOPS),1)
    LLOPT_FLAGS += -loops
    LLVM_REPORT = 1
endif
ifeq ($(SCALAR_EVOLUTION_ANALYSIS),1)
    LLOPT_FLAGS += -scalar-evolution
    LLVM_REPORT = 1
endif
ifeq ($(SCALAR_EV_BASED_ANALYSIS),1)
    LLOPT_FLAGS += -scev-aa
    LLVM_REPORT = 1
endif
ifeq ($(CANONICALIZE_INDUCTION),1)
    LLOPT_FLAGS += -indvars
    LLVM_REPORT = 1
endif
ifeq ($(LOOP_CLOSED_SSA),1)
    LLOPT_FLAGS += -lcssa
    LLVM_REPORT = 1
endif
ifeq ($(LOOP_INV_CODE_MOTION),1)
    LLOPT_FLAGS += -licm
    LLVM_REPORT = 1
endif
ifeq ($(LOOP_STRENGTH_REDUCTION),1)
    LLOPT_FLAGS += -loop-reduce
    LLVM_REPORT = 1
endif
ifeq ($(DEAD_LOOP_DELETION),1)
    LLOPT_FLAGS += -loop-deletion
    LLVM_REPORT = 1
endif
ifeq ($(ROTATE_LOOPS),1)
    LLOPT_FLAGS += -loop-rotate
    LLVM_REPORT = 1
endif
ifeq ($(UNROLL_LOOPS),1)
    LLOPT_FLAGS += -loop-unroll
    LLVM_REPORT = 1
endif
ifeq ($(UNSWITCH_LOOPS),1)
    LLOPT_FLAGS += -loop-unswitch
    LLVM_REPORT = 1
endif
ifeq ($(BASIC_ALIAS_ANALYSIS),1)
    LLOPT_FLAGS += -basicaa
    LLVM_REPORT = 1
endif
ifeq ($(LIBCALL_ALIAS_ANALYSIS),1)
    LLOPT_FLAGS += -libcall-aa
    LLVM_REPORT = 1
endif
ifeq ($(REGIONS_ANALYSIS),1)
    LLOPT_FLAGS += -regions
    LLVM_REPORT = 1
endif
ifeq ($(FUNCTION_ATTRIBUTES),1)
    LLOPT_FLAGS += -functionattrs
    LLVM_REPORT = 1
endif
ifeq ($(INTERNAL_GLOBAL_SYMBOLS),1)
    LLOPT_FLAGS += -internalize
    LLVM_REPORT = 1
endif
ifeq ($(LOWER_SET_JUMP),1)
    LLOPT_FLAGS += -lowersetjmp
    LLVM_REPORT = 1
endif
ifeq ($(MERGE_FUNCTIONS),1)
    LLOPT_FLAGS += -mergefunc
    LLVM_REPORT = 1
endif
ifeq ($(UNIFY_FUNCTIONS),1)
    LLOPT_FLAGS += -mergereturn
    LLVM_REPORT = 1
endif
ifeq ($(PARTIAL_SPECIALIZATION),1)
    LLOPT_FLAGS += -partialspecialization
    LLVM_REPORT = 1
endif
ifeq ($(SPLIT_GEPS),1)
    LLOPT_FLAGS += -split-geps
    LLVM_REPORT = 1
endif
ifeq ($(SRET_PROMOTION),1)
    LLOPT_FLAGS += -sretpromotion
    LLVM_REPORT = 1
endif
ifeq ($(TAIL_CALL_ELIMINATION),1)
    LLOPT_FLAGS += -tailcallelim
    LLVM_REPORT = 1
endif
ifeq ($(ALWAYS_INLINE),1)
    LLOPT_FLAGS += -always-inline
    LLVM_REPORT = 1
endif
ifeq ($(FUNCTION_INLINE),1)
    LLOPT_FLAGS += -inline
    LLVM_REPORT = 1
endif
ifeq ($(PARTIAL_INLINE),1)
    LLOPT_FLAGS += -partial-inliner
    LLVM_REPORT = 1
endif
ifeq ($(DEBUG_AA),1)
    LLOPT_FLAGS += -debug-aa
    LLVM_REPORT = 1
endif
ifeq ($(INST_COUNT),1)
    LLOPT_FLAGS += -instcount
    LLVM_REPORT = 1
endif
ifeq ($(INTERVALS),1)
    LLOPT_FLAGS += -intervals
    LLVM_REPORT = 1
endif
ifeq ($(IV_USERS),1)
    LLOPT_FLAGS += -iv-users
    LLVM_REPORT = 1
endif
ifeq ($(LINT_CHECK),1)
    LLOPT_FLAGS += -lint
    LLVM_REPORT = 1
endif
ifeq ($(MEMORY_CHECK),1)
    LLOPT_FLAGS += -memdep
    LLVM_REPORT = 1
endif
ifeq ($(MODULE_DEBUG),1)
    LLOPT_FLAGS += -module-debuginfo
    LLVM_REPORT = 1
endif
ifeq ($(ARG_PROMOTION),1)
    LLOPT_FLAGS += -argpromotion
    LLVM_REPORT = 1
endif
ifeq ($(CONSTANT_PROPAGATION),1)
    LLOPT_FLAGS += -constprop
    LLVM_REPORT = 1
endif
ifeq ($(COMBINE_INSTRUCTIONS),1)
    LLOPT_FLAGS += -instcombine
    LLVM_REPORT = 1
endif
ifeq ($(JUMP_THREADING),1)
    LLOPT_FLAGS += -jump-threading
    LLVM_REPORT = 1
endif
ifeq ($(LOWER_SWITCH),1)
    LLOPT_FLAGS += -lowerswitch
    LLVM_REPORT = 1
endif
ifeq ($(REASSOCIATE_EXPRESSIONS),1)
    LLOPT_FLAGS += -reassociate
    LLVM_REPORT = 1
endif

ifeq ($(LLVM_REPORT),1)

start_report:
	@(echo \<html\>) > $(MODEL)_analysis.html
	@(echo \<body\>) >> $(MODEL)_analysis.html
	@(echo \<h1\>LLVM Optimization Reports for $(MODEL)\</h1\>) >> $(MODEL)_analysis.html
	@(echo \<p\>This report shows the output of the LLVM optimization phase for each source file processed. The flags passed to opt were:\</p\>) >> $(MODEL)_analysis.html
	@(echo \<ul\>) >> $(MODEL)_analysis.html
	@for opt in $(LLOPT_FLAGS); do (echo \<li\>\<p\>$$opt\</p\>\</li\>) >> $(MODEL)_analysis.html; done
	@(echo \</ul\>) >> $(MODEL)_analysis.html

show_report:
	@(echo \</body\>) >> $(MODEL)_analysis.html
	@(echo \</html\>) >> $(MODEL)_analysis.html
	$(COMSPEC) /c $(MODEL)_analysis.html

else

start_report:
show_report:

endif

.PRECIOUS: %.bc %.bcopt

%.o : %.c

%.bc : %.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c -emit-llvm $(CFLAGS) $(GCC_WALL_FLAG) $< -o $@

%.bcopt : %.bc
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
ifeq ($(LLVM_REPORT),1)
	@(echo \<h2\>Report for $(@)\</h2\>) >> $(MODEL)_analysis.html
	@(echo \<pre\>) >> $(MODEL)_analysis.html
	$(LLOPT) $(LLOPT_FLAGS) $< -o=$@ 2>> $(MODEL)_analysis.html
	@(echo \</pre\>) >> $(MODEL)_analysis.html
else
	$(LLOPT) $(LLOPT_FLAGS) $< -o=$@
endif

%.s : %.bcopt
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(LLC) $(LLC_FLAGS) $< -o=$@ > $(@F).

%.o : %.s
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG) $<

%.bc : %.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c -emit-llvm $(CPPFLAGS) $(GCC_WALL_FLAG) $< -o $@

%.bc : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c -emit-llvm $(CFLAGS) $(GCC_WALL_FLAG) $< -o $@

%.bc : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c -emit-llvm $(CPPFLAGS) $< -o $@

%.bc : $(MATLAB_ROOT)/rtw/c/src/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c -emit-llvm $(CFLAGS) $(GCC_WALL_FLAG_MAX) $< -o $@

%.bc : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c -emit-llvm $(CFLAGS) $(GCC_WALL_FLAG_MAX) $< -o $@

%.bc : $(MATLAB_ROOT)/rtw/c/src/ext_mode/tcpip/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c -emit-llvm $(CFLAGS) $(GCC_WALL_FLAG_MAX) $< -o $@

%.bc : $(MATLAB_ROOT)/rtw/c/src/ext_mode/custom/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c -emit-llvm $(CFLAGS) $(GCC_WALL_FLAG_MAX) $< -o $@

%.bc : $(QUARC)/src/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c -emit-llvm $(CFLAGS) $(GCC_WALL_FLAG_MAX) $< -o $@

%.bc : $(MATLAB_ROOT)/rtw/c/src/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c -emit-llvm $(CFLAGS) $(GCC_WALL_FLAG_MAX) $< -o $@

%.bc : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c -emit-llvm $(CFLAGS) $(GCC_WALL_FLAG_MAX) $< -o $@

%.bc : $(MATLAB_ROOT)/rtw/c/src/rtiostream/rtiostreamtcpip/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c -emit-llvm $(CFLAGS) $(GCC_WALL_FLAG_MAX) $< -o $@



%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c -emit-llvm $(CPPFLAGS) $< -o $@
%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c -emit-llvm $(CPPFLAGS) $< -o $@
%.o : $(MATLAB_ROOT)/rtw/c/src/rtiostream/rtiostreamtcpip/%.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c -emit-llvm $(CPPFLAGS) $< -o $@


%.bc : $(MATLAB_ROOT)/simulink/src/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c -emit-llvm $(CFLAGS) $(GCC_WALL_FLAG_MAX) $< -o $@

%.bc : $(MATLAB_ROOT)/simulink/src/%.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c -emit-llvm $(CPPFLAGS) $< -o $@

else

%.o : %.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG) $<

%.o : %.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG) $<

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG) $<

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c $(CPPFLAGS) $<

%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/tcpip/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/custom/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(QUARC)/src/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(MATLAB_ROOT)/rtw/c/src/rtiostream/rtiostreamtcpip/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<



%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c $(CPPFLAGS) $<
%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c $(CPPFLAGS) $<
%.o : $(MATLAB_ROOT)/rtw/c/src/rtiostream/rtiostreamtcpip/%.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c $(CPPFLAGS) $<


%.o : $(MATLAB_ROOT)/simulink/src/%.c
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) $<

%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	@$(GCC_TEST_CMD) $< $(GCC_TEST_OUT)
	$(CPP) -c $(CPPFLAGS) $<

start_report:
show_report:

endif

#------------------------------- Libraries -------------------------------------





#----------------------------- Dependencies ------------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

$(SHARED_LIB) : $(SHARED_OBJS)
	@echo \#\#\# Creating $@
	$(AR) ruvs $@ $(SHARED_OBJS)
	@echo \#\#\# $@ Created


#--------- Miscellaneous rules to purge, clean and lint (sol2 only) ------------

purge : clean
	@echo \#\#\# Deleting the generated source code for $(MODEL)
	@del /q $(MODEL).c $(MODEL).h $(MODEL)_types.h $(MODEL)_data.c \
	        $(MODEL)_private.h $(MODEL).rtw $(MODULES) rtw_proj.tmw $(MAKEFILE)

clean :
	@echo \#\#\# Deleting the objects and $(PRODUCT)
	@del /q $(LINK_OBJS) $(PRODUCT)

lint  : rtwlib.ln
	@lint -errchk -errhdr=%user -errtags=yes -F -L. -lrtwlib -x -Xc \
	      -erroff=$(LINT_ERROFF) \
	      -D_POSIX_C_SOURCE $(CFLAGS) $(LINT_SRCS)
	@del /q $(LINTOPTSFILE)
	@echo
	@echo \#\#\# Created lint output only, no executable
	@echo

rtwlib.ln : $(MAKEFILE) rtw_proj.tmw
	@echo
	@echo \#\#\# Linting ...
	@echo
	@del /q llib-lrtwlib.ln $(LINTOPTSFILE)
	@echo "-dirout=. -errchk -errhdr=%user " >> $(LINTOPTSFILE)
	@echo "-errtags -F -ortwlib -x -Xc " >> $(LINTOPTSFILE)
	@echo "-erroff=$(LINT_ERROFF) " >> $(LINTOPTSFILE)
	@echo "-D_POSIX_C_SOURCE $(CFLAGS) " >> $(LINTOPTSFILE)
	@for %%file in ($(MATLAB_ROOT)/rtw/c/libsrc/*.c) do echo "%file " >> $(LINTOPTSFILE);
	lint -flagsrc=$(LINTOPTSFILE)

# EOF: quarc_linux_verdex.tmf
