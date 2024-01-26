#ifndef HW_H_
#define HW_H_

#ifdef __cplusplus
extern "C" {
#endif

#include "hw_def.h"

#include "led.h"
#include "uart.h"
#include "log.h"
#include "cli.h"
#include "cli_gui.h"
#include "flash.h"
#include "i2c.h"
#include "eeprom.h"
#include "swtimer.h"
#include "button.h"
#include "qspi.h"
#include "fs.h"
#include "nvs.h"
#include "usb.h"
#include "cdc.h"
#include "wpan.h"

bool hwInit(void);


#ifdef __cplusplus
}
#endif

#endif