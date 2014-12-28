#ifndef ReaderWriter_H
#define ReaderWriter_H

extern int readerCount;

void readerFunction(Mutex *memoryMutex, Semaphore *readerSemaphore);
void writerFunction(char data, Mutex *memoryMutex);
void registerForYield(int *listToYield, int numberToYield);

#endif // ReaderWriter_H
