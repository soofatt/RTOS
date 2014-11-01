#ifndef Clock_H
#define Clock_H

volatile unsigned long clock;

void initClock();
unsigned long getClock();
char isTimer0Overflowed();
void clearTimer0OverflowFlag();
void timer0isr();

#endif // Clock_H
