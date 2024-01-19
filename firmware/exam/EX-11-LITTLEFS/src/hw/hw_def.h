#ifndef HW_DEF_H_
#define HW_DEF_H_



#include "bsp.h"


#define _DEF_FIRMWATRE_VERSION    "V240118R1"
#define _DEF_BOARD_NAME           "STM32WB55-BLE-FW"



#define _USE_HW_FLASH

#define _USE_HW_LED
#define      HW_LED_MAX_CH          3
#define      HW_LED_CH_LED          _DEF_LED1
#define      HW_LED_CH_LED2         _DEF_LED2
#define      HW_LED_CH_BLE          _DEF_LED3

#define _USE_HW_UART                
#define      HW_UART_MAX_CH         1
#define      HW_UART_CH_SWD         _DEF_UART1
#define      HW_UART_CH_CLI         _DEF_UART1

#define _USE_HW_LOG
#define      HW_LOG_CH              HW_UART_CH_SWD

#define _USE_HW_CLI
#define      HW_CLI_CMD_LIST_MAX    32
#define      HW_CLI_CMD_NAME_MAX    16
#define      HW_CLI_LINE_HIS_MAX    8
#define      HW_CLI_LINE_BUF_MAX    64

#define _USE_HW_I2C
#define      HW_I2C_MAX_CH          1
#define      HW_I2C_CH_EEPROM       _DEF_I2C1

#define _USE_HW_EEPROM
#define      HW_EEPROM_MAX_SIZE     (512)

#define _USE_HW_SWTIMER
#define      HW_SWTIMER_MAX_CH      8

#define _USE_HW_BUTTON
#define      HW_BUTTON_MAX_CH       2 

#define _USE_HW_QSPI
#define      HW_QSPI_FLASH_ADDR     0x90000000

#define _USE_HW_FS
#define      HW_FS_MAX_SIZE         (8*1024*1024)



//-- USE CLI
//
#define _USE_CLI_HW_LED             1
#define _USE_CLI_HW_FLASH           1
#define _USE_CLI_HW_I2C             1
#define _USE_CLI_HW_EEPROM          1
#define _USE_CLI_HW_BUTTON          1
#define _USE_CLI_HW_QSPI            1
#define _USE_CLI_HW_FS              1


#endif