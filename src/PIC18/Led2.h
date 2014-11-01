#ifndef Led2_H
#define Led2_H

typedef enum {
  LED2_UNKNOWNSTATE,
  LED2_ON,
  LED2_OFF
}LedStatus;

typedef struct Led2Data Led2Data;

struct Led2Data{
	int state;
	LedStatus ledStatus;
  unsigned long currentClock;
};

void testingLed2SM(Led2Data *data);
void led2SM(Led2Data *data);

#endif // Led2_H
