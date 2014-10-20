#include "LEDSM.h"
#include "Blinky.h"
#include "18c.h"

#define CLK_OV 488 //0.5s

void initLEDStateMachine(LEDData *data){
  data->state = LED_START;
  data->currentClock = 0;
  configureLED();
}

void LEDStateMachine(LEDData *data){
  switch(data->state){
    case LED_START:
      data->state = LED_OFF;
      data->currentClock = 0;
      break;
      
    case LED_OFF:
      if(getClock() - data->currentClock >= CLK_OV){
        data->currentClock = getClock();
        data->state = LED_ON;
        break;
      }
      break;
        
    case LED_ON:
      if(getClock() - data->currentClock >= CLK_OV){
        data->currentClock = getClock();
        data->state = LED_OFF;
        break;
      }
      break;
      
    default:
      break;
  }
}