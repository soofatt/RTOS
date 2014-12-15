#ifndef TCB_H
#define TCB_H
#include "Types.h"
typedef struct TCB TCB;
struct TCB{
  TCB *next;
  char priority;
  uint8 taskID;
  //void (*task)(void);
  uint16 task;//TOS
  uint16 stackPointer; //FSR1
  // uint8 framePointer; //FSR2
};

#endif // TCB_H
