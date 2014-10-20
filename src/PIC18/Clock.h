#ifndef Clock_H
#define Clock_H

static unsigned long clock;

void initClock();
unsigned long getClock();
char isTimer0Overflowed();
void clearTimer0OverflowFlag();

#endif // Clock_H
