#include "unity.h"
#include "p18f4520.h"
#include "Semaphore.h"
#include "PriorityLinkedList.h"
#include "PreemptiveOS.h"

void setUp(void){}

void tearDown(void){}

void test_initSemaphore_should_init_semaphore(void){
	Semaphore semaphore;
  
  initCountingSemaphore(&semaphore, 3);
  
  TEST_ASSERT_EQUAL(3, semaphore.counter);
  TEST_ASSERT_EQUAL(3, semaphore.maxCounter);
  TEST_ASSERT_NULL(semaphore.waitingQueue.head);
  TEST_ASSERT_NULL(semaphore.waitingQueue.tail);
}

void test_initBinarySemaphore_should_init_semaphore(void){
	Semaphore semaphore;
  
  initBinarySemaphore(&semaphore);
  
  TEST_ASSERT_EQUAL(1, semaphore.counter);
  TEST_ASSERT_EQUAL(1, semaphore.maxCounter);
  TEST_ASSERT_NULL(semaphore.waitingQueue.head);
  TEST_ASSERT_NULL(semaphore.waitingQueue.tail);
}

void test_downSemaphore_given_maxCount_2_should_reduce_counter_to_1(void){
	Semaphore semaphore;
  TCB TCB1 = {0};
  initCountingSemaphore(&semaphore, 2);
  runningTCB = &TCB1;
  
  downSemaphore(&semaphore);
  
  TEST_ASSERT_EQUAL(1, semaphore.counter);
  TEST_ASSERT_EQUAL(2, semaphore.maxCounter);
  TEST_ASSERT_NULL(semaphore.waitingQueue.head);
  TEST_ASSERT_NULL(semaphore.waitingQueue.tail);
}

void test_downSemaphore_given_maxCount_2_down_twice_should_reduce_counter_to_0(void){
	Semaphore semaphore;
  TCB TCB1 = {0};
  initCountingSemaphore(&semaphore, 2);
  runningTCB = &TCB1;
  
  downSemaphore(&semaphore);
  
  TEST_ASSERT_EQUAL(1, semaphore.counter);
  TEST_ASSERT_EQUAL(2, semaphore.maxCounter);
  TEST_ASSERT_NULL(semaphore.waitingQueue.head);
  TEST_ASSERT_NULL(semaphore.waitingQueue.tail);
  
  downSemaphore(&semaphore);
  
  TEST_ASSERT_EQUAL(0, semaphore.counter);
  TEST_ASSERT_EQUAL(2, semaphore.maxCounter);
  TEST_ASSERT_NULL(semaphore.waitingQueue.head);
  TEST_ASSERT_NULL(semaphore.waitingQueue.tail);
}

void test_downSemaphore_given_maxCount_2_down_three_times_should_put_TCB2_into_waitingQueue(void){
	Semaphore semaphore;
  TCB TCB1 = {0}, TCB2 = {0};
  initCountingSemaphore(&semaphore, 2);
  runningTCB = &TCB1;
  
  downSemaphore(&semaphore);
  
  TEST_ASSERT_EQUAL(1, semaphore.counter);
  TEST_ASSERT_EQUAL(2, semaphore.maxCounter);
  TEST_ASSERT_NULL(semaphore.waitingQueue.head);
  TEST_ASSERT_NULL(semaphore.waitingQueue.tail);
  
  downSemaphore(&semaphore);
  
  TEST_ASSERT_EQUAL(0, semaphore.counter);
  TEST_ASSERT_EQUAL(2, semaphore.maxCounter);
  TEST_ASSERT_NULL(semaphore.waitingQueue.head);
  TEST_ASSERT_NULL(semaphore.waitingQueue.tail);
  
  runningTCB = &TCB2;
  downSemaphore(&semaphore);
  
  TEST_ASSERT_EQUAL(0, semaphore.counter);
  TEST_ASSERT_EQUAL(2, semaphore.maxCounter);
  TEST_ASSERT_EQUAL(&TCB2, semaphore.waitingQueue.head);
  TEST_ASSERT_EQUAL(&TCB2, semaphore.waitingQueue.tail);
}

void test_upSemaphore_given_maxCount_2_and_nothing_in_queue_should_incrase_counter_to_2(void){
	Semaphore semaphore;
  TCB TCB1 = {0};
  initCountingSemaphore(&semaphore, 2);
  runningTCB = &TCB1;
  
  downSemaphore(&semaphore);
  
  TEST_ASSERT_EQUAL(1, semaphore.counter);
  TEST_ASSERT_EQUAL(2, semaphore.maxCounter);
  TEST_ASSERT_NULL(semaphore.waitingQueue.head);
  TEST_ASSERT_NULL(semaphore.waitingQueue.tail);
  
  upSemaphore(&semaphore);
  
  TEST_ASSERT_EQUAL(2, semaphore.counter);
  TEST_ASSERT_NULL(semaphore.waitingQueue.head);
  TEST_ASSERT_NULL(semaphore.waitingQueue.tail);
}

void test_upSemaphore_given_one_TCB_in_queue_should_put_TCB2_into_readyQueue(void){
	Semaphore semaphore;
  TCB TCB1 = {0}, TCB2 = {0};
  initCountingSemaphore(&semaphore, 2);
  runningTCB = &TCB1;
  
  downSemaphore(&semaphore);
  
  TEST_ASSERT_EQUAL(1, semaphore.counter);
  TEST_ASSERT_EQUAL(2, semaphore.maxCounter);
  TEST_ASSERT_NULL(semaphore.waitingQueue.head);
  TEST_ASSERT_NULL(semaphore.waitingQueue.tail);
  
  downSemaphore(&semaphore);
  
  TEST_ASSERT_EQUAL(0, semaphore.counter);
  TEST_ASSERT_EQUAL(2, semaphore.maxCounter);
  TEST_ASSERT_NULL(semaphore.waitingQueue.head);
  TEST_ASSERT_NULL(semaphore.waitingQueue.tail);
  
  runningTCB = &TCB2;
  downSemaphore(&semaphore);
  
  TEST_ASSERT_EQUAL(0, semaphore.counter);
  TEST_ASSERT_EQUAL(2, semaphore.maxCounter);
  TEST_ASSERT_EQUAL_PTR(&TCB2, semaphore.waitingQueue.head);
  TEST_ASSERT_EQUAL_PTR(&TCB2, semaphore.waitingQueue.tail);
  
  runningTCB = &TCB1;
  upSemaphore(&semaphore);
  
  TEST_ASSERT_EQUAL(0, semaphore.counter);
  TEST_ASSERT_NULL(semaphore.waitingQueue.head);
  TEST_ASSERT_NULL(semaphore.waitingQueue.tail);
  TEST_ASSERT_EQUAL(&TCB2, readyQueue.head);
  TEST_ASSERT_EQUAL(&TCB2, readyQueue.tail);
}

void test_upSemaphore_given_one_TCB_in_queue_should_put_TCB2_into_readyQueue_case_2(void){
	Semaphore semaphore;
  TCB TCB1 = {0}, TCB2 = {0};
  initCountingSemaphore(&semaphore, 2);
  runningTCB = &TCB1;
  
  downSemaphore(&semaphore);
  
  TEST_ASSERT_EQUAL(1, semaphore.counter);
  TEST_ASSERT_EQUAL(2, semaphore.maxCounter);
  TEST_ASSERT_NULL(semaphore.waitingQueue.head);
  TEST_ASSERT_NULL(semaphore.waitingQueue.tail);
  
  downSemaphore(&semaphore);
  
  TEST_ASSERT_EQUAL(0, semaphore.counter);
  TEST_ASSERT_EQUAL(2, semaphore.maxCounter);
  TEST_ASSERT_NULL(semaphore.waitingQueue.head);
  TEST_ASSERT_NULL(semaphore.waitingQueue.tail);
  
  runningTCB = &TCB2;
  downSemaphore(&semaphore);
  
  TEST_ASSERT_EQUAL(0, semaphore.counter);
  TEST_ASSERT_EQUAL(2, semaphore.maxCounter);
  TEST_ASSERT_EQUAL_PTR(&TCB2, semaphore.waitingQueue.head);
  TEST_ASSERT_EQUAL_PTR(&TCB2, semaphore.waitingQueue.tail);
  
  runningTCB = &TCB1;
  upSemaphore(&semaphore);
  
  TEST_ASSERT_EQUAL(0, semaphore.counter);
  TEST_ASSERT_NULL(semaphore.waitingQueue.head);
  TEST_ASSERT_NULL(semaphore.waitingQueue.tail);
  TEST_ASSERT_EQUAL(&TCB2, readyQueue.head);
  TEST_ASSERT_EQUAL(&TCB2, readyQueue.tail);
  
  upSemaphore(&semaphore);
  
  TEST_ASSERT_EQUAL(1, semaphore.counter);
  TEST_ASSERT_NULL(semaphore.waitingQueue.head);
  TEST_ASSERT_NULL(semaphore.waitingQueue.tail);
}