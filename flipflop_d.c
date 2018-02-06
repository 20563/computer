#include "flipflop_d.h"

/**
 * flipflop_d - D flip flop (latch) to store 1 bit information
 * controled by clock @CLK, and input signals,
 * @D to set
 *
 * @D: set - store 1 bit
 * @CLK: clock - control set and reset on HIGH
 *
 * Returns :
 * set Q to 1 (NQ = 0) if S = 1 and CLK = 1,
 * reset Q to 0  (NQ = 1) if R = 1 and CLK = 1
 *
 */

struct latch flipflop_d(u8 D, u8 CLK)
{
	static struct latch l;

#ifdef FLIPFLOP_DBG
	printf("D = %d CLK = %d\n", D, CLK);
	printf("Q = %d NQ = %d\n", l.q, l.nq);
#endif

	l = flipflop_rs(D, not_gate(D), CLK);

#ifdef FLIPFLOP_DBG
	printf("Q = %d NQ = %d\n\n", l.q, l.nq);
#endif
	return l;
}
