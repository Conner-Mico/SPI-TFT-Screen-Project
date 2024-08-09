cmake_minimum_required(VERSION 3.20)

set(CMAKE_BUILD_TYPE Debug)

option(USE_CONSOLE "Turn on console" ON)

set(CMAKE_TOOLCHAIN_FILE toolchain/cross/STM32L476RG.cmake)

if(NOT USE_CONSOLE)
  add_compile_definitions(NO_CONSOLE)
endif()

# This makes intellisense a breeze Just set c_cpp_properties to use
# compileCommands
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

project(
  TFT-Screen-Project
  VERSION 1.0
  DESCRIPTION "TFT Screen Project"
  LANGUAGES C ASM)

# Specify the language standard
set(CMAKE_C_STANDARD 23)

# Generate FreeRTOS static library freertos_config is an INTERFACE library that
# exports the include directory containing FreeRTOSConfig.h.
set(FREERTOS_PORT
    GCC_ARM_CM4F
    CACHE STRING \"\")
add_library(freertos_config INTERFACE)
target_include_directories(freertos_config
                           INTERFACE "${CMAKE_SOURCE_DIR}/src/app/config")

# Prefer .elf extension for the ELF file output by the linker. By default, CMake
# applies no extension for executable targets.
if(CMAKE_CROSSCOMPILING)
  set(CMAKE_EXECUTABLE_SUFFIX ".elf")
endif()

set(APP_NAME application)
set(APP_LIB_NAME applicationLib)
set(APP_SOURCE_DIR ${CMAKE_SOURCE_DIR}/src/app)

add_subdirectory(src/app)
add_subdirectory(src/debug)
add_subdirectory(drivers/HAL)
add_subdirectory(drivers/LL)
add_subdirectory(third-party/FreeRTOSv10_0_0/)



# Generate the memory map from the linker script
cmake_path(SET MEM_MAP_TOOL NORMALIZE
           ${CMAKE_CURRENT_LIST_DIR}/tools/generate_memory_map.py)

# Files Input files
cmake_path(SET MEMORY_MAP_LD NORMALIZE
           ${CMAKE_CURRENT_LIST_DIR}/ld/memory_map/memory_map.ld)
# Output files
cmake_path(SET MEMORY_MAP_H NORMALIZE
           ${CMAKE_CURRENT_LIST_DIR}/ld/memory_map/memory_map.h)
cmake_path(SET MEMORY_MAP_PY NORMALIZE
           ${CMAKE_CURRENT_LIST_DIR}/ld/memory_map/memory_map.py)
message(STATUS "GENERATING MEMORY MAP")
execute_process(COMMAND ${PYTHON_CMD} ${MEM_MAP_TOOL} --linker ${MEMORY_MAP_LD}
                        --header ${MEMORY_MAP_H} --python ${MEMORY_MAP_PY})
