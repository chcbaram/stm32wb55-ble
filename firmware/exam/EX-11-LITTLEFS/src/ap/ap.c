#include "ap.h"



void ledISR(void *arg)
{
  ledToggle(HW_LED_CH_LED2);
}

void apInit(void)
{  
  #ifdef _USE_HW_CLI
  cliOpen(HW_UART_CH_CLI, 115200);
  cliLogo();
  #endif    

  swtimer_handle_t timer_ch;
  timer_ch = swtimerGetHandle();
  if (timer_ch >= 0)
  {
    swtimerSet(timer_ch, 100, LOOP_TIME, ledISR, NULL);
    swtimerStart(timer_ch);  
  }
}

void apMain(void)
{
  uint32_t pre_time;

  pre_time = millis();
  while(1)
  {
    if (millis()-pre_time >= 500)
    {
      pre_time = millis();
      ledToggle(HW_LED_CH_LED);
    }

    #ifdef _USE_HW_CLI
    cliMain();
    #endif
  }
}

