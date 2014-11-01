#include "Interrupt.h"
#include "Clock.h"

void interrupt interruptSR(){
    timer0isr();
}