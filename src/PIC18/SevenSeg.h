#ifndef SevenSeg_H
#define SevenSeg_H

typedef enum{
	_7Seg_INIT,
	_7Seg_WAITING
} _7SegState;

typedef struct SevenSegData SevenSegData;
struct SevenSegData{
	_7SegState state;
	int counter;
	unsigned long currClock;
};

void  initSevenSeg(SevenSegData *data);
void  turnOnSevenSeg(void);
void  turnOffSevenSeg(void);
void sevenSegSM(SevenSegData *data);

#endif // SevenSeg_H

