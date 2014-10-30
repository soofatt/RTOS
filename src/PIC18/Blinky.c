#include <stdio.h>
#include <stdlib.h>
#include "../18c.h"


void delay();

void delay(){
    int counter = 0;
    for(counter = 0; counter<5000; counter++){

    }
}

void configureLED() {
  TRISBbits.TRISB0 = 0;
}

void onLED() {
  PORTBbits.RB0 = 1;
}

void offLED() {
  PORTBbits.RB0 = 0;
}