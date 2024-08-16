# ##############################################################################
# STM32L476RG (Cortex-M4)  #
# ##############################################################################
# ---------------------------------------------------------------- INCLUDE GUARD
# CMake includes the toolchain file multiple times when configuring the build,
# which causes errors for some flags (e.g., --specs=nano.specs). We prevent this
# with an include guard.
if(STM32L476RG_TOOLCHAIN_INCLUDED)
  return()
endif()

set(STM32L476RG_TOOLCHAIN_INCLUDED true)

# ------------------------------------------------ STM32L476RG SPECIFIC SETTINGS
# Global compilation flag, added to every compilation unit
set(CPU_FLAGS "-DSTM32L476xx")

# ---------------------------------------------------- CHAIN NEXT TOOLCHAIN FILE
include(${CMAKE_CURRENT_LIST_DIR}/cortex-m4f.cmake)
