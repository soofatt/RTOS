#include "p18f4520.h"

void delay(){
    int counter = 0;
    for(counter = 0; counter<10000; counter++){

    }
}

void main(void){
    TRISD = 0;
    while(1){
        PORTD = 1;
        delay();
        PORTD = 0;
        delay();
    }
}
