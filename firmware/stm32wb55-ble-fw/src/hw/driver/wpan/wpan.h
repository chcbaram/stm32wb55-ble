#ifndef WPAN_H_
#define WPAN_H_


#ifdef __cplusplus
extern "C" {
#endif

#include "hw_def.h"

#ifdef _USE_HW_WPAN
#include "app_conf.h"
#include "interface\patterns\ble_thread\hw.h"


bool wpanInit(void);
bool wpanConfig(void);
bool wpanProcess(void);

#endif

#ifdef __cplusplus
}
#endif



#endif 