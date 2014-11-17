#ifndef TCB_H
#define TCB_H

typedef char        int8;
typedef short int   int16;
typedef long        int32;
typedef unsigned char       uint8;
typedef unsigned short int  uint16;
typedef unsigned long       uint32;

typedef struct TCB TCB;
struct TCB{
  TCB *next;
  char priority;
  uint8 taskID;
  void (*task)(void);
  //char PC[3];
  uint16 stackPointer; //FSR1
  //uint16 framePointer; //FSR2
  //char status;
  //char bsr;
  //char workingRegister;
};

#endif // TCB_H
