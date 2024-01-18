#include "ap.h"



void apInit(void)
{  
}

void apMain(void)
{
  while(1)
  {
    ledToggle(0);
    ledToggle(1);
    ledToggle(2);
    delay(500);
  }
}

