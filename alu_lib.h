#ifndef _ALU_LIB_H_
#define _ALU_LIB_H_

#include <stdio.h>
#ifdef CONFIG_USE_STDINT
#endif

#include "computer_types.h"

struct flags;
struct adder;

enum {
	GND = 0,
	VCC = 1
};

/**
 * flags - ALU Arithmetic logic unit
 *
 * @V: Overflow has occurred
 * @N: Negative Result
 * @Z: Zero Result
 * @C: Carry
 *
 */

struct flags {
	u8 v:1;
	u8 n:1;
	u8 z:1;
	u8 c:1;
} flags; /* global access through flags declaration */

/**
 * adder - store two bits sum and carry
 *
 * @sum: store sum
 * @carry: store sum carry
 *
 */

struct adder {
	u8 sum:1;
	u8 carry:1;
};

#endif /* _ALU_LIB_H_ */
