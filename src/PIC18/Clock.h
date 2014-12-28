#ifndef Clock_H
#define Clock_H

extern int blockStatus;

void initClock(void);
unsigned long getClock(void);
char isTimer0Overflowed(void);
void clearTimer0OverflowFlag(void);
void timer0isr(void);

#endif // Clock_H
