#ifndef HW_DEF_H_
#define HW_DEF_H_



#include "bsp.h"


#define _DEF_FIRMWATRE_VERSION    "V240118R1"
#define _DEF_BOARD_NAME           "STM32WB55-BLE-FW"




#define _USE_HW_LED
#define      HW_LED_MAX_CH          3
#define      HW_LED_CH_LED          _DEF_LED1
#define      HW_LED_CH_LED2         _DEF_LED2
#define      HW_LED_CH_BLE          _DEF_LED3

#define _USE_HW_UART                
#define      HW_UART_MAX_CH         1
#define      HW_UART_CH_SWD         _DEF_UART1

#define _USE_HW_LOG
#define      HW_LOG_CH              HW_UART_CH_SWD

#endif