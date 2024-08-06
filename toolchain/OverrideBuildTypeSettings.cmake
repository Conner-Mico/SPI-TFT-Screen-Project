# ##############################################################################
# Default Build Configuration Flags #
# ##############################################################################
# ------------------------------------------------------------------ EXPLANATION
# These flags will get picked up by setting CMAKE_BUILD_TYPE when invoking CMake
# (either on the command line or using an environment variable).
#
# See the CMake Manual for Default and Custom Configurations
# https://cmake.org/cmake/help/latest/manual/cmake-buildsystem.7.html#default-and-custom-configurations
#
# See the CMake Manual for CMAKE_<LANG>_FLAGS_<CONFIG>_INIT:
# https://cmake.org/cmake/help/latest/variable/CMAKE_LANG_FLAGS_CONFIG_INIT.html

# ------------------------------------------------------------ DEBUG BUILD FLAGS
set(CMAKE_C_FLAGS_DEBUG_INIT
    "-O0 -g3 -DDEBUG"
    CACHE INTERNAL "Default C compiler debug build flags.")
set(CMAKE_CXX_FLAGS_DEBUG_INIT
    "-O0 -g3 -DDEBUG"
    CACHE INTERNAL "Default C++ compiler debug build flags.")
set(CMAKE_ASM_FLAGS_DEBUG_INIT
    "-O0 -g3 -DDEBUG"
    CACHE INTERNAL "Default assembly compiler debug build flags")

# ---------------------------------------------------------- RELEASE BUILD FLAGS
set(CMAKE_C_FLAGS_RELEASE_INIT
    "-Os -g3"
    CACHE INTERNAL "Default C compiler release build flags.")
set(CMAKE_CXX_FLAGS_RELEASE_INIT
    "-Os -g3"
    CACHE INTERNAL "Default C++ compiler release build flags.")
set(CMAKE_ASM_FLAGS_RELEASE_INIT
    "-Os -g3"
    CACHE INTERNAL "Default asm compiler release build flags.")
