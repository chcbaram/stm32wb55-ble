#include "wpan.h"


#ifdef _USE_HW_WPAN
#include "app_conf.h"
#include "app_entry.h"
#include "app_common.h"

#include "rng.h"
#include "ipcc.h"
#include "rf.h"
#include "rtc_stm.h"




bool wpanInit(void)
{
  MX_IPCC_Init();
  MX_RTC_Init();
  MX_RNG_Init();
  MX_RF_Init();
  MX_APPE_Init();
  return true;
}

bool wpanConfig(void)
{
  MX_APPE_Config();
  return true;
}

bool wpanProcess(void)
{
  MX_APPE_Process();
  return true;
}

void RTC_WKUP_IRQHandler(void)
{
  HAL_RTCEx_WakeUpTimerIRQHandler(&hrtc);
}

void IPCC_C1_RX_IRQHandler(void)
{
  HAL_IPCC_RX_IRQHandler(&hipcc);
}

void IPCC_C1_TX_IRQHandler(void)
{
  HAL_IPCC_TX_IRQHandler(&hipcc);
}

void HSEM_IRQHandler(void)
{
  HAL_HSEM_IRQHandler();
}
#endif