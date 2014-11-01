#include "unity.h"
#include "Led2.h"
#include "Tasking.h"
#include "Blinky.h"
#include "p18f4520.h"
#include "mock_Clock.h"

void setUp(void){}

void tearDown(void){}

void xtest_testingLed2SM_(void){
	Led2Data led2Data = {.state = 0, .ledStatus = 1};
	
  printf("1\n");
	testingLed2SM(&led2Data);
  // TEST_ASSERT_EQUAL(LED2_ON, led2Data.state);
  printf("2\n");
  testingLed2SM(&led2Data);
  // TEST_ASSERT_EQUAL(LED2_ON, led2Data.state);
  printf("3\n");
}

void test_initTasking_should_init_to_state_0(){
  Led2Data led2Data = {.currentClock = 0};
  
  initTasking(&led2Data);
  
  TEST_ASSERT_EQUAL(0, led2Data.state);
  TEST_ASSERT_EQUAL(0, led2Data.currentClock);
}

void test_led2SM(){
  Led2Data led2Data = {.ledStatus = LED2_UNKNOWNSTATE, .currentClock = 0};
  
  initTasking(&led2Data);
  
  led2SM(&led2Data);
  TEST_ASSERT_EQUAL(LED2_ON, led2Data.ledStatus);
  //Progress time but not expiring ON state
  
  getClock_ExpectAndReturn(100);
  
  led2SM(&led2Data);
  TEST_ASSERT_EQUAL(LED2_ON, led2Data.ledStatus);
  //Progress time and expiring ON state
  
  getClock_ExpectAndReturn(500);
  getClock_ExpectAndReturn(500);
  getClock_ExpectAndReturn(500);
  
  led2SM(&led2Data);
  TEST_ASSERT_EQUAL(LED2_OFF, led2Data.ledStatus);
  //Progress time but not expiring OFF state
  
  getClock_ExpectAndReturn(600);
  
  led2SM(&led2Data);
  TEST_ASSERT_EQUAL(LED2_OFF, led2Data.ledStatus);
  //Progress time but expiring OFF state
  
  getClock_ExpectAndReturn(1000);
  getClock_ExpectAndReturn(1000);
  getClock_ExpectAndReturn(1000);
  
  led2SM(&led2Data);
  TEST_ASSERT_EQUAL(LED2_ON, led2Data.ledStatus);
}
