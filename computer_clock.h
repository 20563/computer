#ifndef _COMPUTER_CLOCK_H_
#define _COMPUTER_CLOCK_H_

#include <pthread.h>
#include <time.h>
#include "alu_lib.h"

#define CLOCK_STEP_SEC 1
#define CLOCK_STEP_NSEC 0

extern u8 computer_clk;

void *computer_clock(void *arg);
void clock_initialize(void);
void clock_stop(void);

#endif /* _COMPUTER_CLOCK_H_ */
