#include <stdio.h>
#include <stdlib.h>
#include "../18c.h"

#if !(defined(__XC) || defined(__18CXX))
  #include "usart.h"
#endif // __18CXX

#pragma config OSC = INTIO67, DEBUG = ON, LVP = OFF, WDT = OFF, PWRT = ON

void delay();

void delay(){
    int counter = 0;
    for(counter = 0; counter<25000; counter++){

    }
}

void configureLED() {
  TRISCbits.TRISC0 = 0;
}

void onLED() {
  PORTCbits.RC0 = 1;
}

void offLED() {
  PORTCbits.RC0 = 0;
}