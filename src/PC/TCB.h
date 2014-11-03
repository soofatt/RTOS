#ifndef TCB_H
#define TCB_H

typedef struct TCB TCB;
struct TCB{
  struct TCB *next;
  char priority;
  char PC[3];
  int dataStack;
  char status;
};

#endif // TCB_H
