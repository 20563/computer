#include "latch.h"

/**
 * latch - latch to store 1 bit information
 * controlled by input signals,
 * @S to set and @R to reset.
 * @S = 0 and @R = 0 at the same time are not allowed (invalid state)
 * @S = 1 and @R = 1 at the same time indeterminate (no change)
 *
 * @S: set - store 1 bit
 * @R: reset - remove 1 bit from storage
 *
 * | S | R | Q | NQ|
 * +---+---+---+---+
 * | 1 | 0 | 0 | 1 | set
 * | 1 | 1 | 0 | 1 | no change
 * +---+---+---+---+
 * | 0 | 1 | 1 | 0 | reset
 * | 1 | 1 | 1 | 0 | no change
 * +---+---+---+---+
 * | 0 | 0 | 1 | 1 | invalid state
 *
 * Returns :
 * on set: Q to 1 (NQ = 0) if R = 1,
 * on reset: Q to 0 (NQ = 1) if S = 1
 *
 */

struct latch latch(u8 S, u8 R)
{
	static struct latch l;

#ifdef LATCH_DBG
	printf("S = %d R = %d\n", S, R);
	printf("Q = %d NQ = %d\n", l.q, l.nq);
#endif

	if (S == 1) {
		l.nq = nand_gate(R, l.q);
		l.q = nand_gate(S, l.nq);
	} else {
		l.q = nand_gate(S, l.nq);
		l.nq = nand_gate(R, l.q);
	}

#ifdef LATCH_DBG
	printf("Q = %d NQ = %d\n\n", l.q, l.nq);
#endif
	return l;
}
