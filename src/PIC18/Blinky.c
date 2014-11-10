#include <stdio.h>
#include <stdlib.h>
#include "../18c.h"


void delay(void);

void delay(void){
    int counter = 0;
    for(counter = 0; counter<5000; counter++){

    }
}

void configureLED(void) {
  TRISBbits.TRISB0 = 0;
}

void onLED(void) {
  PORTBbits.RB0 = 1;
}

void offLED(void) {
  PORTBbits.RB0 = 0;
}