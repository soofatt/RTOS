#include "SevenSeg.h"
#include "../18c.h"

#define CLK_OV 488 //0.5s

char hexPatterns[] = {
						0x77,  //0
						0x14,  //1
						0xb3,  //2
						0xb6,  //3
						0xd4,  //4
						0xe6,  //5
						0xe7,  //6
						0x34,  //7
						0xf7,  //8
						0xf6,  //9
						0xf5,  //A
						0xc7,  //B
						0x83,  //C
						0x97,  //D
						0xe3,  //E
						0xe1   //F
};

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
			WriteSPI(hexPatterns[data->counter]);
			data->state = _7Seg_WAITING;
			break;
		
		case _7Seg_WAITING:
			if(getClock() - data->currClock >= 488){
				data->currClock = getClock();
				WriteSPI(hexPatterns[data->counter]);
				data->counter++;
			}
                        if(data->counter == 16)
                            data->counter = 0;
                        
			data->state = _7Seg_WAITING;
			break;
		
		default:
			break;
	}
}