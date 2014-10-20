#include "unity.h"
#include "LEDSM.h"
#include "mock_Clock.h"

void setUp(void){}

void tearDown(void){}

void test_LED_StateMachine_given_state_LED_OFF_less_than_overflow_should_stay_in_state(void){
  LEDState state = LED_OFF;
  
  getClock_ExpectAndReturn(100);
  
  LEDStateMachine(&state);
  
  TEST_ASSERT_EQUAL(LED_OFF, state);
}

void test_LED_StateMachine_given_state_LED_OFF_more_than_overflow_should_change_to_LED_ON(void){
  LEDState state = LED_OFF;
  
  getClock_ExpectAndReturn(489);
  
  LEDStateMachine(&state);
  
  TEST_ASSERT_EQUAL(LED_ON, state);
}

void test_LED_StateMachine_given_state_LED_ON_less_than_overflow_should_stay_in_state(void){
  LEDState state = LED_ON;
  
  getClock_ExpectAndReturn(100);
  
  LEDStateMachine(&state);
  
  TEST_ASSERT_EQUAL(LED_ON, state);
}

void test_LED_StateMachine_given_state_LED_ON_more_than_overflow_should_change_to_LED_OFF(void){
  LEDState state = LED_ON;
  
  getClock_ExpectAndReturn(489);
  
  LEDStateMachine(&state);
  
  TEST_ASSERT_EQUAL(LED_OFF, state);
}
