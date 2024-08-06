# ##############################################################################
# Cortex-M4F #
# ##############################################################################

# CMake includes the toolchain file multiple times when configuring the build,
# which causes errors for some flags (e.g., --specs=nano.specs). We prevent this
# with an include guard.
if(ARM_CORTEX_M4F_TOOLCHAIN_INCLUDED)
  return()
endif()

set(ARM_CORTEX_M4FS_TOOLCHAIN_INCLUDED true)

set(CPU_NAME cortex-m4)
set(CPU_FLAGS "-mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mthumb ${CPU_FLAGS}")
set(VFP_FLAGS "-mfloat-abi=softfp")
set(FREERTOS_PORT GCC_ARM_CM4F)

include(${CMAKE_CURRENT_LIST_DIR}/arm-none-eabi-gcc.cmake)
