#include "transistor.h"

/**
 * transistor - simplified model of bipolar transistor NPN
 * Ic - Collector current,
 * Ib - Base current,
 * Ie - Emitter current
 *
 * @input: 1 or 0
 *
 * Returns : 1 if current flow "input = 1 (Ic = 1 and Ib = 1)", otherwise 0
 *
 */

/**
 * enable to simulate current latency in transistor
 */

const u8 transistor(const u8 input)
{
#if TRANSISTOR_LATENCY
	static struct timespec t;

	t.tv_sec = TRANSISTOR_TIMEOUT_SEC;
	t.tv_nsec = TRANSISTOR_TIMEOUT_NSEC;

	nanosleep(&t, NULL);
#endif /* TRANSISTOR_LATENCY */
	return input ? VCC : GND;
}
