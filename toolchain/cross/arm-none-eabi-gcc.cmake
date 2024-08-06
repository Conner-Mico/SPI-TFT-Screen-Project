# ##############################################################################
# arm-none-eabi-gcc Base Toolchain #
# ##############################################################################
#
# To include this file as a base toolchain file, include it at the bottom of the
# derived toolchain file.
#
# You can define CPU_FLAGS that will be passed to CMAKE_*_FLAGS to select the
# CPU (and any other necessary CPU-specific flags) You can define VFP_FLAGS to
# select the desired floating-point configuration You can define LD_FLAGS to
# control linker flags for your target

# ##############################################################################
# System Config #
# ##############################################################################

set(CMAKE_SYSTEM_NAME Generic)
set(CMAKE_SYSTEM_PROCESSOR arm)
# Represents the name of the specific processor type, e.g. Cortex-M4
if(NOT CPU_NAME)
  set(CPU_NAME generic)
endif()

# ##############################################################################
# Toolchain Config #
# ##############################################################################

find_program(CROSS_GCC_PATH arm-none-eabi-gcc)
get_filename_component(TOOLCHAIN ${CROSS_GCC_PATH} DIRECTORY)

find_program(CCACHE_FOUND ccache)
if(CCACHE_FOUND)
  set_property(GLOBAL PROPERTY RULE_LAUNCH_COMPILE ccache)
endif()

set(CMAKE_C_COMPILER ${TOOLCHAIN}/arm-none-eabi-gcc)
set(CMAKE_CXX_COMPILER ${TOOLCHAIN}/arm-none-eabi-g++)
set(CMAKE_AS
    ${TOOLCHAIN}/arm-none-eabi-as
    CACHE STRING "arm-none-eabi-as")
set(CMAKE_AR
    ${TOOLCHAIN}/arm-none-eabi-ar
    CACHE STRING "arm-none-eabi-ar")
set(CMAKE_OBJCOPY
    ${TOOLCHAIN}/arm-none-eabi-objcopy
    CACHE STRING "arm-none-eabi-objcopy")
set(CMAKE_OBJDUMP
    ${TOOLCHAIN}/arm-none-eabi-objdump
    CACHE STRING "arm-none-eabi-objdump")
set(CMAKE_SIZE
    ${TOOLCHAIN}/arm-none-eabi-size
    CACHE STRING "arm-none-eabi-size")

# If set to ONLY, then only the roots in CMAKE_FIND_ROOT_PATH (i.e., the host
# machine) will be searched. If set to NEVER, then the roots in
# CMAKE_FIND_ROOT_PATH will be ignored and only the build machine root will be
# used.
set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)

# Test compiles will use static libraries, so we won't need to define linker
# flags and scripts for linking to succeed
set(CMAKE_TRY_COMPILE_TARGET_TYPE STATIC_LIBRARY)

# ##############################################################################
# Common Flags #
# ##############################################################################
# Note that CPU_FLAGS, LD_FLAGS, and VFP_FLAGS are set by other Toolchain files
# that include this file.
#
# See the CMake Manual for CMAKE_<LANG>_FLAGS_INIT:
# https://cmake.org/cmake/help/latest/variable/CMAKE_LANG_FLAGS_INIT.html
# -fstack-usage -fdump-ipa-cgraph

set(CMAKE_C_FLAGS_INIT
    "${CPU_FLAGS} ${VFP_FLAGS} -fdiagnostics-color=always -fdata-sections -ffunction-sections --specs=nano.specs"
    CACHE INTERNAL "Default C compiler flags.")
set(CMAKE_CXX_FLAGS_INIT
    "${CPU_FLAGS} ${VFP_FLAGS} -fdiagnostics-color=always -fdata-sections -ffunction-sections --specs=nano.specs"
    CACHE INTERNAL "Default C++ compiler flags.")
set(CMAKE_ASM_FLAGS_INIT
    "${CPU_FLAGS} -x assembler-with-cpp"
    CACHE INTERNAL "Default ASM compiler flags.")
set(CMAKE_EXE_LINKER_FLAGS_INIT
    "${LD_FLAGS} --specs=nosys.specs -Wl,--gc-sections -static -Wl,--start-group -lc -lm -Wl,--end-group -Wl,--print-memory-usage -Wl,-wrap=_read_r,-wrap=_write_r,-wrap=_close_r -Wl,-wrap=_fstat_r -Wl,-wrap=_getpid_r -Wl,-wrap=_isatty_r -Wl,-wrap=_kill_r -Wl,-wrap=_lseek_r"
    CACHE INTERNAL "Default linker flags.")

# Build configuration overrides are specified by setting
# CMAKE_USER_MAKE_RULES_OVERRIDE.
# https://cmake.org/cmake/help/v3.23/variable/CMAKE_USER_MAKE_RULES_OVERRIDE.html
set(CMAKE_USER_MAKE_RULES_OVERRIDE
    "${CMAKE_CURRENT_LIST_DIR}/../OverrideBuildTypeSettings.cmake")
