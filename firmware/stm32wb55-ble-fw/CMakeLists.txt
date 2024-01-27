cmake_minimum_required(VERSION 3.13)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE INTERNAL "")
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/tools")
include(arm-none-eabi-gcc)


# 프로젝트 이름은 최종 출력 파일 이름으로 사용된다.
#
set(PRJ_NAME stm32wb55-ble-fw)


project(${PRJ_NAME}
  LANGUAGES ASM C CXX
)

set(EXECUTABLE ${PRJ_NAME}.elf)


# 지정한 폴더에 있는 파일만 포함한다.
#
file(GLOB SRC_FILES CONFIGURE_DEPENDS
  src/*.cpp
  src/*.c
  src/bsp/*.c
  src/bsp/device/*.c

  # LittleFS
  src/lib/littlefs/*.c  

  # USB
  src/lib/ST/STM32_USB_Device_Library/Core/Src/*.c  

  # WPAN
  # src/lib/ST/STM32_WPAN/ble/core/auto/*.c
  # src/lib/ST/STM32_WPAN/ble/core/template/*.c
  # src/lib/ST/STM32_WPAN/ble/svc/*.c
  # src/lib/ST/STM32_WPAN/ble/svc/Src/*.c
  # src/lib/ST/STM32_WPAN/interface/patterns/ble_thread/shci/*.c
  # src/lib/ST/STM32_WPAN/interface/patterns/ble_thread/tl/*.csrc/lib/ST/STM32_WPAN/ble/svc/Src/*.c  
  # src/lib/ST/STM32_WPAN/utilities/*.c  

  # src/lib/ST/Utilities/sequencer/*.c
  # src/lib/ST/Utilities/lpm/tiny_lpm/*.c
  
)

# 하위폴더에 있는 파일까지 포함한다.
#
file(GLOB_RECURSE SRC_FILES_RECURSE CONFIGURE_DEPENDS
  src/ap/*.c
  src/bsp/*.s
  src/common/*.c
  src/hw/*.c
  src/lib/ST/STM32WBxx_HAL_Driver/Src/*.c

  # WPAN
  src/lib/ST/STM32_WPAN/*.c
  src/lib/ST/Utilities/*.c
)

# 특정 폴더를 빌드에서 제외한다.
#
set(EXCLUDE_PATHS 
)

foreach(TMP_PATH ${SRC_FILES_RECURSE}) 
  foreach(EXCLUDE_PATH ${EXCLUDE_PATHS}) 
    string(FIND ${TMP_PATH} ${EXCLUDE_PATH} RESULT) 
    if(NOT ${RESULT} EQUAL -1) 
      list(REMOVE_ITEM SRC_FILES_RECURSE ${TMP_PATH}) 
    endif() 
  endforeach(EXCLUDE_PATH) 
endforeach(TMP_PATH)


add_executable(${EXECUTABLE} 
  ${SRC_FILES}
  ${SRC_FILES_RECURSE}
)


target_include_directories(${EXECUTABLE} PRIVATE 
  src  
  src/ap
  src/ap/thread
  src/bsp
  src/bsp/device
  src/common 
  src/common/core
  src/common/hw/include 
  src/hw
  src/hw/driver
  src/hw/driver/usb
  src/hw/driver/usb/usb_cdc  
  src/hw/driver/eeprom
  src/lib

  src/lib/ST/CMSIS/Include
  src/lib/ST/CMSIS/Device/ST/STM32WBxx/Include
  src/lib/ST/STM32WBxx_HAL_Driver/Inc

  # USB
  src/hw/driver/usb
  src/hw/driver/usb/usb_cdc
  src/hw/driver/usb/usb_msc
  src/lib/ST/STM32_USB_Device_Library/Core/Inc

  # WPAN
  src/hw/driver/wpan
  src/hw/driver/wpan/app/include
  src/hw/driver/wpan/core/include

  src/lib/ST/STM32_WPAN
  src/lib/ST/STM32_WPAN/ble
  src/lib/ST/STM32_WPAN/utilities
  src/lib/ST/STM32_WPAN/interface/patterns/ble_thread/tl
  src/lib/ST/STM32_WPAN/interface/patterns/ble_thread/shci
  src/lib/ST/STM32_WPAN/ble/core
  src/lib/ST/STM32_WPAN/ble/core/template
  
  src/lib/ST/Utilities/sequencer
  src/lib/ST/Utilities/lpm/tiny_lpm
  
  )

target_compile_definitions(${EXECUTABLE} PRIVATE
  -DUSE_HAL_DRIVER
  -DSTM32WB55xx
  )

target_compile_options(${EXECUTABLE} PRIVATE
  -mcpu=cortex-m4
  -mthumb
  -mfpu=fpv4-sp-d16
  -mfloat-abi=hard

  -fdata-sections
  -ffunction-sections

  -Wall
  -g3
  -Og
  )

target_link_options(${EXECUTABLE} PRIVATE
  -T../src/bsp/ldscript/STM32WB55RG_FLASH.ld
  # -T../src/bsp/ldscript/STM32WB55RG_EXTEND.ld
  -mcpu=cortex-m4
  -mthumb
  -mfpu=fpv4-sp-d16
  -mfloat-abi=hard
  -specs=nano.specs
  -lc
  -lm
  -lstdc++
  -lsupc++
  # -lnosys

  -u _printf_float
  
  -Wl,-Map=${PRJ_NAME}.map,--cref
  -Wl,--gc-sections
  -Xlinker -print-memory-usage -Xlinker
  )

add_custom_command(TARGET ${EXECUTABLE} 
  POST_BUILD
  COMMAND ${CMAKE_OBJCOPY} ARGS -O binary ${EXECUTABLE} ${PROJECT_NAME}.bin
  COMMENT "Invoking: Make Binary"
  )  