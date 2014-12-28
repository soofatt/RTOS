#include "unity.h"
#include "p18f4520.h"
#include "Mutex.h"
#include "Semaphore.h"
#include "ReaderWriter.h"
#include "PreemptiveOS.h"
#include "PriorityLinkedList.h"
#include "Tasking.h"

void setUp(void){
  readerCount = 0;
}

void tearDown(void){}

void test_writerFunction_should_acquire_mutex_and_block_other_task_read_or_write(void){
	Mutex memoryMutex;
  initMutex(&memoryMutex);
  Semaphore readerSemaphore;
  initCountingSemaphore(&readerSemaphore, 10);
  TCB writerTask = {0}, writerTask2 = {0}, readerTask = {0};
  int yieldOnThese[] = {2};
  
  registerForYield(yieldOnThese, 1);
  
  runningTCB = &writerTask;
  writerFunction('c', &memoryMutex);
  
  TEST_ASSERT_EQUAL(0, memoryMutex.count);
  TEST_ASSERT_EQUAL(&writerTask, memoryMutex.owner);
  TEST_ASSERT_EQUAL_PTR(NULL, memoryMutex.waitingQueue.head);
  TEST_ASSERT_EQUAL_PTR(NULL, memoryMutex.waitingQueue.tail);
  
  runningTCB = &readerTask;
  readerFunction(&memoryMutex, &readerSemaphore);
  
  TEST_ASSERT_EQUAL(0, memoryMutex.count);
  TEST_ASSERT_EQUAL(&writerTask, memoryMutex.owner);
  TEST_ASSERT_EQUAL_PTR(&readerTask, memoryMutex.waitingQueue.head);
  TEST_ASSERT_EQUAL_PTR(&readerTask, memoryMutex.waitingQueue.tail);
  
  runningTCB = &writerTask2;
  writerFunction('d', &memoryMutex);
  
  TEST_ASSERT_EQUAL(0, memoryMutex.count);
  TEST_ASSERT_EQUAL(&writerTask, memoryMutex.owner);
  TEST_ASSERT_EQUAL_PTR(&readerTask, memoryMutex.waitingQueue.head);
  TEST_ASSERT_EQUAL_PTR(&writerTask2, memoryMutex.waitingQueue.tail);
}

void test_readerFunction_should_allow_other_task_to_read(void){
	Mutex memoryMutex;
  initMutex(&memoryMutex);
  Semaphore readerSemaphore;
  initCountingSemaphore(&readerSemaphore, 10);
  TCB readerTask = {0}, readerTask2 = {0}, readerTask3 = {0};
  int yieldOnThese[] = {3, 3, 4};
  
  registerForYield(yieldOnThese, 3);
  
  runningTCB = &readerTask;
  readerFunction(&memoryMutex, &readerSemaphore);
  
  TEST_ASSERT_EQUAL(0, memoryMutex.count);
  TEST_ASSERT_EQUAL(&readerTask, memoryMutex.owner);
  TEST_ASSERT_EQUAL_PTR(NULL, memoryMutex.waitingQueue.head);
  TEST_ASSERT_EQUAL_PTR(NULL, memoryMutex.waitingQueue.tail);
  TEST_ASSERT_EQUAL(9, readerSemaphore.counter);
  
  runningTCB = &readerTask2;
  readerFunction(&memoryMutex, &readerSemaphore);
  
  TEST_ASSERT_EQUAL(0, memoryMutex.count);
  TEST_ASSERT_EQUAL(&readerTask, memoryMutex.owner);
  TEST_ASSERT_EQUAL_PTR(NULL, memoryMutex.waitingQueue.head);
  TEST_ASSERT_EQUAL_PTR(NULL, memoryMutex.waitingQueue.tail);
  TEST_ASSERT_EQUAL(8, readerSemaphore.counter);
  
  runningTCB = &readerTask3;
  readerFunction(&memoryMutex, &readerSemaphore);
  
  TEST_ASSERT_EQUAL(0, memoryMutex.count);
  TEST_ASSERT_EQUAL(&readerTask, memoryMutex.owner);
  TEST_ASSERT_EQUAL_PTR(NULL, memoryMutex.waitingQueue.head);
  TEST_ASSERT_EQUAL_PTR(NULL, memoryMutex.waitingQueue.tail);
  TEST_ASSERT_EQUAL(7, readerSemaphore.counter);
}

void test_readerFunction_should_block_writer_task(void){
	Mutex memoryMutex;
  initMutex(&memoryMutex);
  Semaphore readerSemaphore;
  initCountingSemaphore(&readerSemaphore, 10);
  TCB readerTask = {0}, writerTask = {0};
  int yieldOnThese[] = {3};
  
  registerForYield(yieldOnThese, 1);
  
  runningTCB = &readerTask;
  readerFunction(&memoryMutex, &readerSemaphore);
  
  TEST_ASSERT_EQUAL(0, memoryMutex.count);
  TEST_ASSERT_EQUAL(&readerTask, memoryMutex.owner);
  TEST_ASSERT_EQUAL_PTR(NULL, memoryMutex.waitingQueue.head);
  TEST_ASSERT_EQUAL_PTR(NULL, memoryMutex.waitingQueue.tail);
  TEST_ASSERT_EQUAL(9, readerSemaphore.counter);
  
  runningTCB = &writerTask;
  writerFunction('c', &memoryMutex);
  
  TEST_ASSERT_EQUAL(0, memoryMutex.count);
  TEST_ASSERT_EQUAL(&readerTask, memoryMutex.owner);
  TEST_ASSERT_EQUAL_PTR(&writerTask, memoryMutex.waitingQueue.head);
  TEST_ASSERT_EQUAL_PTR(&writerTask, memoryMutex.waitingQueue.tail);
  TEST_ASSERT_EQUAL(9, readerSemaphore.counter);
  
}

void test_readerFunction_two_reader_second_reader_interrupt_and_acquire_should_block_writer(void){
	Mutex memoryMutex;
  initMutex(&memoryMutex);
  Semaphore readerSemaphore;
  initCountingSemaphore(&readerSemaphore, 10);
  TCB readerTask = {0}, readerTask2 = {0}, writerTask = {0};
  int yieldOnThese[] = {1, 3};
  
  registerForYield(yieldOnThese, 2);
  
  runningTCB = &readerTask;
  readerFunction(&memoryMutex, &readerSemaphore);
  
  TEST_ASSERT_EQUAL(1, memoryMutex.count);
  TEST_ASSERT_EQUAL_PTR(NULL, memoryMutex.owner);
  TEST_ASSERT_EQUAL_PTR(NULL, memoryMutex.waitingQueue.head);
  TEST_ASSERT_EQUAL_PTR(NULL, memoryMutex.waitingQueue.tail);
  TEST_ASSERT_EQUAL(9, readerSemaphore.counter);
  
  runningTCB = &readerTask2;
  readerFunction(&memoryMutex, &readerSemaphore);
  
  TEST_ASSERT_EQUAL(0, memoryMutex.count);
  TEST_ASSERT_EQUAL(&readerTask2, memoryMutex.owner);
  TEST_ASSERT_EQUAL_PTR(NULL, memoryMutex.waitingQueue.head);
  TEST_ASSERT_EQUAL_PTR(NULL, memoryMutex.waitingQueue.tail);
  TEST_ASSERT_EQUAL(8, readerSemaphore.counter);
  
  runningTCB = &writerTask;
  writerFunction('c', &memoryMutex);
  
  TEST_ASSERT_EQUAL(0, memoryMutex.count);
  TEST_ASSERT_EQUAL(&readerTask2, memoryMutex.owner);
  TEST_ASSERT_EQUAL_PTR(&writerTask, memoryMutex.waitingQueue.head);
  TEST_ASSERT_EQUAL_PTR(&writerTask, memoryMutex.waitingQueue.tail);
  TEST_ASSERT_EQUAL(8, readerSemaphore.counter);
  
}

void test_readerFunction_reader_released_mutex_writer_should_be_able_to_acquire(void){
	Mutex memoryMutex;
  initMutex(&memoryMutex);
  Semaphore readerSemaphore;
  initCountingSemaphore(&readerSemaphore, 10);
  TCB readerTask = {0}, writerTask = {0};
  int yieldOnThese[] = {5, 2};
  
  registerForYield(yieldOnThese, 2);
  
  runningTCB = &readerTask;
  readerFunction(&memoryMutex, &readerSemaphore);
  
  TEST_ASSERT_EQUAL(1, memoryMutex.count);
  TEST_ASSERT_EQUAL_PTR(NULL, memoryMutex.owner);
  TEST_ASSERT_EQUAL_PTR(NULL, memoryMutex.waitingQueue.head);
  TEST_ASSERT_EQUAL_PTR(NULL, memoryMutex.waitingQueue.tail);
  TEST_ASSERT_EQUAL(10, readerSemaphore.counter);
  
  runningTCB = &writerTask;
  writerFunction('c', &memoryMutex);
  
  TEST_ASSERT_EQUAL(0, memoryMutex.count);
  TEST_ASSERT_EQUAL(&writerTask, memoryMutex.owner);
  TEST_ASSERT_EQUAL_PTR(NULL, memoryMutex.waitingQueue.head);
  TEST_ASSERT_EQUAL_PTR(NULL, memoryMutex.waitingQueue.tail);
  TEST_ASSERT_EQUAL(10, readerSemaphore.counter);
  
}