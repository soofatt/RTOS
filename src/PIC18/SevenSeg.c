#include "SevenSeg.h"
#include "Clock.h"
#include "../18c.h"

#if !(defined(__XC) || defined(__18CXX))
  #include "spi.h"
#endif // __18CXX

#pragma config OSC = INTIO67, DEBUG = ON, LVP = OFF, WDT = OFF, PWRT = ON

void  initSevenSeg(SevenSegData *data){
	TRISCbits.TRISC2 = 0;
	data->state = _7Seg_INIT;
}

void  turnOnSevenSeg(){
	PORTCbits.RC2 = 1;
}

void  turnOffSevenSeg(){
	PORTCbits.RC2 = 0;
}

void sevenSegSM(SevenSegData *data){
	switch(data->state){
		case _7Seg_INIT:
			data->counter = 0;
			data->currClock = getClock();
			WriteSPI(data->counter);
			data->state = _7Seg_WAITING;
			break;
		
		case _7Seg_WAITING:
			if(getClock() - data->currClock >= CLK_OV){
				data->currClock = getClock();
				WriteSPI(data->counter);
				data->counter++;
			}
			data->state = _7Seg_WAITING;
			break;
		
		default:
			break;
	}
}