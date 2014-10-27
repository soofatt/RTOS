#ifndef Clock_H
#define Clock_H

#define CLK_OV 488 //0.5s

static unsigned long clock;

void initClock();
unsigned long getClock();
char isTimer0Overflowed();
void clearTimer0OverflowFlag();

#endif // Clock_H
