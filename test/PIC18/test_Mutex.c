#include "unity.h"
#include "Mutex.h"

void setUp(void){}

void tearDown(void){}

void test_initMutex_should_initialize_mutex(void){
	Mutex mutex;
  
  initMutex(&mutex);
  
  TEST_ASSERT_EQUAL(1, mutex.count);
  TEST_ASSERT_NULL(mutex.owner);
  TEST_ASSERT_NULL(mutex.waitingQueue);
}
