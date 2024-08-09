# ##############################################################################
# Main Application CMake #
# ##############################################################################
# Application files only.

set(VERSION_ROOT "")

#include(git_version)

#set(TARGET_BASENAME ${FULL_VERSION}-${GIT_DESCRIBE_TAG})

set(TARGET_ELF ${TARGET_BASENAME}.elf)
set(TARGET_HEX ${TARGET_BASENAME}.hex)
set(TARGET_BIN ${TARGET_BASENAME}.bin)
set(TARGET_DISASSEMBLY ${TARGET_BASENAME}.dis)
set(TARGET_MD5 ${TARGET_BIN}.md5)
set(TARGET_SYM ${TARGET_BASENAME}.sym)
set(TARGET_LSS ${TARGET_BASENAME}.lss)
set(TARGET_HEADER ${TARGET_BASENAME}.image_hdr)

# Define variables that can be used in other CMakeLists.txt files to find the
# application target
set(APP_ELF
    ${TARGET_NAME}
    PARENT_SCOPE)
set(APP_HEX
    ${TARGET_HEX}
    PARENT_SCOPE)

add_executable(${APP_NAME})

target_compile_options(
  ${APP_NAME}
  PRIVATE -Wall
          -Wextra
          -Wno-missing-field-initializers
          -Wno-unused-variable
          -Wno-unused-parameter
          -Wno-unused-function
          -Wno-unused-but-set-variable
          -funsigned-char)

target_link_libraries(
  ${APP_NAME}
  m
  freertos_kernel
  HAL
  LL
)

target_sources(
  ${APP_NAME}
  PRIVATE ../../startup/startup_stm32l476xx.s
          ../../system/system_stm32l4xx.c
          utility/utility.c
          utility/assert.c
          main.c
          system/clock/clock.c
          application/application.c
          LED/LED.c
)

target_link_options(
  ${APP_NAME} PRIVATE
  -T../ld/STM32L476RGTx_FLASH.ld
  -mthumb
  -mcpu=cortex-m4
)

target_include_directories(
  ${APP_NAME}
  PRIVATE
    config/
    utility/
    gpio/
    system/clock/
    application/
    LED/
)
