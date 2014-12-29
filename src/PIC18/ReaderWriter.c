#include "Mutex.h"
#include "Semaphore.h"
#include "ReaderWriter.h"
#include "PreemptiveOS.h"
#include "Tasking.h"
// ignore yield for MPLAB
#if !(defined(__XC) || defined(__18CXX))
  #define yieldOn(lineNumber, x) if(yieldPointer[i] == x && i < maxYield) {i++; yield(lineNumber); } else;
#else
  #define yieldOn(lineNumber, x);
  #define startTasking(x);
  #define endTasking();
#endif // __18CXX

char memory[5] = {'H', 'E', 'L', 'L', 'O'};
int readerCount;

int i; // yield counter
int maxYield;
int *yieldPointer;
void registerForYield(int *listToYield, int numberToYield){
  i = 0;
  maxYield = numberToYield;
  yieldPointer = listToYield;
}

void readerFunction(Mutex *memoryMutex, Semaphore *readerSemaphore){
  char readMem;
  startTasking(runningTCB->task);
  
  if(downSemaphore(readerSemaphore)){
  
    yieldOn(runningTCB->task, 1);
    
    readerCount++;
    if(readerCount == 1)        //first reader
      acquireMutex(memoryMutex);//to block writer
    
    yieldOn(runningTCB->task, 3);
    
    readMem = memory[0];
    
    yieldOn(runningTCB->task, 4);
    
    upSemaphore(readerSemaphore);
    readerCount--;
    if(readerCount == 0)        //last reader
      releaseMutex(memoryMutex);//allow writer to acquire
  }
  
  yieldOn(runningTCB->task, 5);
  
  endTasking();
}

void writerFunction(char data, Mutex *memoryMutex){
  startTasking(runningTCB->task);

  if(acquireMutex(memoryMutex)){
  
    yieldOn(runningTCB->task, 2);
    
    memory[0] = data;
    
    releaseMutex(memoryMutex);
  }
  endTasking();
}