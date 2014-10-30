#include "unity.h"
#include "Blinky.h"
#include "p18f4520.h"

void setUp(void) {}

void tearDown(void) {}

void test_configureLED_set_portc_pin0_as_output_OpenComport(void) {
  TRISBbits.RB0 = PIN_INPUT;
  configureLED();
  TEST_ASSERT_EQUAL(PIN_OUTPUT, TRISBbits.RB0);
}

void test_onLED_set_portc_pin0_to_high(void) {
  PORTBbits.RB0 = PIN_LOW;
  onLED();
  TEST_ASSERT_EQUAL(PIN_HIGH, PORTBbits.RB0);
}

void test_offLED_set_portc_pin0_to_high(void) {
  PORTBbits.RB0 = PIN_HIGH;
  offLED();
  TEST_ASSERT_EQUAL(PIN_LOW, PORTBbits.RB0);
}