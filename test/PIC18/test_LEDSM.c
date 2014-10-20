#include "unity.h"
#include "LEDSM.h"
#include "Blinky.h"
#include "p18f4520.h"
#include "mock_Clock.h"

void setUp(void){}

void tearDown(void){}

void test_initStateMachine_should_init_to_LED_START(void){
  LEDData data = {.state = LED_START, .currentClock = 0};
  
  initLEDStateMachine(&data);
  
  TEST_ASSERT_EQUAL(LED_START, data.state);
}

void test_LED_StateMachine_given_state_LED_START_should_init_to_LED_OFF(void){
  LEDData data = {.state = LED_START, .currentClock = 0};
  
  LEDStateMachine(&data);
  
  TEST_ASSERT_EQUAL(LED_OFF, data.state);
  TEST_ASSERT_EQUAL(0, data.currentClock);
}

void test_LED_StateMachine_given_state_LED_OFF_less_than_overflow_should_stay_in_state(void){
  LEDData data = {.state = LED_OFF, .currentClock = 0};
  
  getClock_ExpectAndReturn(100);
  
  LEDStateMachine(&data);
  
  TEST_ASSERT_EQUAL(LED_OFF, data.state);
  TEST_ASSERT_EQUAL(0, data.currentClock);
}

void test_LED_StateMachine_given_state_LED_OFF_more_than_overflow_should_change_to_LED_ON(void){
  LEDData data = {.state = LED_OFF, .currentClock = 0};
  
  getClock_ExpectAndReturn(489);
  getClock_ExpectAndReturn(489);
  
  LEDStateMachine(&data);
  
  TEST_ASSERT_EQUAL(LED_ON, data.state);
  TEST_ASSERT_EQUAL(489, data.currentClock);
}

void test_LED_StateMachine_given_state_LED_ON_less_than_overflow_should_stay_in_state(void){
  LEDData data = {.state = LED_ON, .currentClock = 0};
  
  getClock_ExpectAndReturn(100);
  
  LEDStateMachine(&data);
  
  TEST_ASSERT_EQUAL(LED_ON, data.state);
  TEST_ASSERT_EQUAL(0, data.currentClock);
}

void test_LED_StateMachine_given_state_LED_ON_more_than_overflow_should_change_to_LED_OFF(void){
  LEDData data = {.state = LED_ON, .currentClock = 0};
  
  getClock_ExpectAndReturn(489);
  getClock_ExpectAndReturn(489);
  
  LEDStateMachine(&data);
  
  TEST_ASSERT_EQUAL(LED_OFF, data.state);
  TEST_ASSERT_EQUAL(489, data.currentClock);
}
