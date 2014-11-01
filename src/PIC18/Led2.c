#include <stdio.h>
#include "Led2.h"
#include "Tasking.h"
#include "Blinky.h"
#include "../18c.h"

#define CLK_OV 488 //0.5s

void testingLed2SM(Led2Data *data){
	startTasking(data->state);
  printf("LED2_INIT\n");
  printf("before yield1\n");
  yield(data->state);
  printf("after yield1\n");
  if(data->ledStatus == 10){
    printf("before yield2\n");
    yield(data->state);
    printf("after yield 2\n");
  }else{
    printf("tak jadi yield2\n");
  }
  endTasking();
}

void led2SM(Led2Data *data){
  // static int i = 0;
  
  startTasking(data->state);
  data->ledStatus = LED2_ON;
  onLED();
  yield(data->state);
  while(1){
    while(getClock() - data->currentClock <= CLK_OV){
      yield(data->state);
    }
    offLED();
    data->currentClock = getClock();
    data->ledStatus = LED2_OFF;
    
    while(getClock() - data->currentClock <= CLK_OV){
      yield(data->state);
    }
    onLED();
    data->currentClock = getClock();
    data->ledStatus = LED2_ON;
  }
  endTasking();
}