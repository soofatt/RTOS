#include "unity.h"
#include "Clock.h"
#include "p18f4520.h"

void setUp(void){}

void tearDown(void){}

void test_isTimer0Overflowed_given_not_yet_overflowed_should_return_0(void){
  
  TEST_ASSERT_FALSE(isTimer0Overflowed());
}

void test_isTimer0Overflowed_given_overflowed_should_return_1(void){
  
  TEST_ASSERT_FALSE(isTimer0Overflowed());
}

void test_clearTimer0OverflowFlag_should_clear_overflow_flag(void){
  INTCONbits.TMR0IF = 1;
  
  clearTimer0OverflowFlag();
  
  TEST_ASSERT_FALSE(INTCONbits.TMR0IF);
}

void test_getClock_given_no_overflow_clock_should_stay_same(void){
  INTCONbits.TMR0IF = 0;
  
  clock = getClock();
  
  TEST_ASSERT_EQUAL(0, clock);
  TEST_ASSERT_FALSE(INTCONbits.TMR0IF);
}

void test_getClock_given_overflow_clock_should_increment_by_1(void){
  INTCONbits.TMR0IF = 1;
  
  clock = getClock();
  
  TEST_ASSERT_EQUAL(1, clock);
  TEST_ASSERT_FALSE(INTCONbits.TMR0IF);
}