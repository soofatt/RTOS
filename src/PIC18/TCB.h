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
  //char PC[3];
  uint16 stackPointer; //FSR1
  //uint16 framePointer; //FSR2
  //char status;
  //char bsr;
  //char workingRegister;
};

#endif // TCB_H
