#include "computer_clock.h"

static u8 computer_clk_lock;

/* extern computer_clock.h
 * In the absence of explicit initializations,
 * external and static variables are guaranteed
 * to be initialized to zero.
 */
u8 computer_clk;

/**
 * computer_clock - computer clock simulator
 *
 * @arg: unused pointer variable, NULL as default
 *
 * Returns : NULL
 *
 */

void *computer_clock(void *arg)
{
#ifdef COMPUTER_CLOCK_SPEED
	struct timespec t;

	t.tv_sec = CLOCK_STEP_SEC;
	t.tv_nsec = CLOCK_STEP_NSEC;
#endif /* COMPUTER_CLOCK_SPEED */
	computer_clk_lock = 1;
	while (computer_clk_lock) {
		computer_clk = !computer_clk;
#ifdef COMPUTER_CLOCK_DBG
		printf("clock %d\n", computer_clk);
#endif /* COMPUTER_CLOCK_DBG */
#ifdef COMPUTER_CLOCK_SPEED
		nanosleep(&t, NULL);
#endif /* COMPUTER_CLOCK_SPEED */
	}
	return NULL;
}

/**
 * clock_initialize - runs independent computer clock as thread
 */

void clock_initialize(void)
{
	pthread_t clock_thread;

	if (pthread_create(&clock_thread, NULL, computer_clock, NULL))
		printf("Error creating thread\n");
	else
		pthread_detach(clock_thread);
}

/**
 * clock_stop - interrupts computer clock loop
 */

void clock_stop(void)
{
	computer_clk_lock = 0;
}
