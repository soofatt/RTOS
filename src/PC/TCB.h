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
  struct TCB *next;
  char priority;
  char PC[3];
  unsigned int *stackPointer; //FSR1
  unsigned int *framePointer; //FSR2
  char status;
  char bsr;
  char workingRegister;
};

#endif // TCB_H
