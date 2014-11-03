#include <stdio.h>
#include <stdlib.h>
//#include "../TCB.h"
#include "../18c.h"

TCB *runningTCB;
TCB TCBForTesting;

void initPreemptiveMultitasking(void) {
    runningTCB = &TCBForTesting;
}
