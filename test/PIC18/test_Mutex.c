#include "unity.h"
#include "p18f4520.h"
#include "Mutex.h"
#include "PriorityLinkedList.h"
#include "PreemptiveOS.h"

void setUp(void){}

void tearDown(void){}

void test_initMutex_should_initialize_mutex(void){
	Mutex mutex;
  
  initMutex(&mutex);
  
  TEST_ASSERT_EQUAL(1, mutex.count);
  TEST_ASSERT_NULL(mutex.owner);
  TEST_ASSERT_NULL(mutex.waitingQueue.head);
  TEST_ASSERT_NULL(mutex.waitingQueue.tail);
}

void test_acquireMutex_should_set_owner_to_runningTCB_and_decrease_count_to_0(void){
	Mutex mutex;
  TCB TCB1;
  int result;
  
  initMutex(&mutex);
  runningTCB = &TCB1;
  
  result = acquireMutex(&mutex);
  
  TEST_ASSERT_EQUAL(0, mutex.count);
  TEST_ASSERT_EQUAL(&TCB1, mutex.owner);
  TEST_ASSERT_EQUAL(1, result);
}

void test_acquireMutex_given_same_owner_acquire_again_should_reduce_count(void){
	Mutex mutex;
  TCB TCB1;
  int result;
  
  initMutex(&mutex);
  runningTCB = &TCB1;
  
  result = acquireMutex(&mutex);
  
  TEST_ASSERT_EQUAL(0, mutex.count);
  TEST_ASSERT_EQUAL(&TCB1, mutex.owner);
  TEST_ASSERT_EQUAL(1, result);
  
  result = acquireMutex(&mutex);
  
  TEST_ASSERT_EQUAL(-1, mutex.count);
  TEST_ASSERT_EQUAL(&TCB1, mutex.owner);
  TEST_ASSERT_EQUAL(1, result);
}

void test_acquireMutex_given_different_TCB_acquire_should_add_to_waitingQueue_and_return_0(void){
	Mutex mutex;
  TCB TCB1, TCB2;
  int result;
  
  initMutex(&mutex);
  runningTCB = &TCB1;
  
  result = acquireMutex(&mutex);
  
  TEST_ASSERT_EQUAL(0, mutex.count);
  TEST_ASSERT_EQUAL(&TCB1, mutex.owner);
  TEST_ASSERT_EQUAL(1, result);
  
  runningTCB = &TCB2;
  result = acquireMutex(&mutex);
  
  TEST_ASSERT_EQUAL(0, mutex.count);
  TEST_ASSERT_EQUAL(&TCB1, mutex.owner);
  TEST_ASSERT_EQUAL(&TCB2, mutex.waitingQueue.head);
  TEST_ASSERT_EQUAL(&TCB2, mutex.waitingQueue.tail);
  TEST_ASSERT_EQUAL(0, result);
}

void test_acquireMutex_given_same_TCB_acquire_twice_diff_TCB_acquire_once_should_not_change_count(void){
	Mutex mutex;
  TCB TCB1, TCB2;
  int result;
  
  initMutex(&mutex);
  runningTCB = &TCB1;
  
  result = acquireMutex(&mutex);
  
  TEST_ASSERT_EQUAL(0, mutex.count);
  TEST_ASSERT_EQUAL(&TCB1, mutex.owner);
  TEST_ASSERT_EQUAL(1, result);
  
  result = acquireMutex(&mutex);
  
  TEST_ASSERT_EQUAL(-1, mutex.count);
  TEST_ASSERT_EQUAL(&TCB1, mutex.owner);
  TEST_ASSERT_EQUAL(1, result);
  
  runningTCB = &TCB2;
  result = acquireMutex(&mutex);
  
  TEST_ASSERT_EQUAL(-1, mutex.count);
  TEST_ASSERT_EQUAL(&TCB1, mutex.owner);
  TEST_ASSERT_EQUAL(&TCB2, mutex.waitingQueue.head);
  TEST_ASSERT_EQUAL(&TCB2, mutex.waitingQueue.tail);
  TEST_ASSERT_EQUAL(0, result);
}

void test_releaseMutex_should_increase_count_to_1_and_set_owner_to_NULL(void){
	Mutex mutex;
  TCB TCB1;
  int result;
  
  initMutex(&mutex);
  runningTCB = &TCB1;
  
  result = acquireMutex(&mutex);
  
  TEST_ASSERT_EQUAL(0, mutex.count);
  TEST_ASSERT_EQUAL(&TCB1, mutex.owner);
  TEST_ASSERT_EQUAL(1, result);
  
  releaseMutex(&mutex);
  
  TEST_ASSERT_EQUAL(1, mutex.count);
  TEST_ASSERT_NULL(mutex.owner);
}

void test_releaseMutex_given_same_TCB_acquired_twice_should_need_to_release_twice(void){
	Mutex mutex;
  TCB TCB1;
  int result;
  
  initMutex(&mutex);
  runningTCB = &TCB1;
  
  result = acquireMutex(&mutex);
  
  TEST_ASSERT_EQUAL(0, mutex.count);
  TEST_ASSERT_EQUAL(&TCB1, mutex.owner);
  TEST_ASSERT_EQUAL(1, result);
  
  result = acquireMutex(&mutex);
  
  TEST_ASSERT_EQUAL(-1, mutex.count);
  TEST_ASSERT_EQUAL(&TCB1, mutex.owner);
  TEST_ASSERT_EQUAL(1, result);
  
  releaseMutex(&mutex);
  
  TEST_ASSERT_EQUAL(0, mutex.count);
  TEST_ASSERT_EQUAL(&TCB1, mutex.owner);
  
  releaseMutex(&mutex);
  
  TEST_ASSERT_EQUAL(1, mutex.count);
  TEST_ASSERT_NULL(mutex.owner);
}

void test_releaseMutex_given_a_TCB_in_waitingQueue_should_set_owner_to_next_in_line(void){
	Mutex mutex;
  TCB TCB1, TCB2;
  int result;
  
  initMutex(&mutex);
  runningTCB = &TCB1;
  
  result = acquireMutex(&mutex);
  
  TEST_ASSERT_EQUAL(0, mutex.count);
  TEST_ASSERT_EQUAL(&TCB1, mutex.owner);
  TEST_ASSERT_EQUAL(1, result);
  
  runningTCB = &TCB2;
  result = acquireMutex(&mutex);
  
  TEST_ASSERT_EQUAL(0, mutex.count);
  TEST_ASSERT_EQUAL(&TCB1, mutex.owner);
  TEST_ASSERT_EQUAL(0, result);
  
  runningTCB = &TCB1;
  releaseMutex(&mutex);
  
  TEST_ASSERT_EQUAL(1, mutex.count);
  TEST_ASSERT_EQUAL(&TCB2, mutex.owner);
  TEST_ASSERT_EQUAL(&TCB2, readyQueue.head);
  TEST_ASSERT_EQUAL(&TCB2, readyQueue.tail);
}