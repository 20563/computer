#include "flipflop_rs.h"

/**
 * flipflop_rs - RS flip flop (latch) to store 1 bit information
 * controlled by clock @CLK, and input signals,
 * @S to set and @R to reset
 *
 * @S: set - store 1 bit
 * @R: reset - remove 1 bit from storage
 * @CLK: clock - control set and reset on HIGH
 *
 * Returns :
 * set Q to 1 (NQ = 0) if S = 1 and CLK = 1,
 * reset Q to 0  (NQ = 1) if R = 1 and CLK = 1
 *
 */

struct latch flipflop_rs(u8 S, u8 R, u8 CLK)
{
	static struct latch l;

#ifdef FLIPFLOP_DBG
	printf("S = %d R = %d CLK = %d\n", S, R, CLK);
	printf("Q = %d NQ = %d\n", l.q, l.nq);
#endif

	/**
	 * TODO need to resolve concurrency,
	 * with Q and NQ, model should be without
	 * conditional if(S == 1)
	 *
	 * Problem is that, we don't know
	 * current state of Q and NQ,
	 * before we don't compute them.
	 * Because their state depends each others.
	 *
	 * Probably the most closest model will be
	 * if S == 1, then first compute Q then NQ,
	 * otherwise compute at first NQ then Q,
	 * which is resolved bellow
	 *
	 */
	l = latch(nand_gate(S, CLK), nand_gate(R, CLK));

#ifdef FLIPFLOP_DBG
	printf("Q = %d NQ = %d\n\n", l.q, l.nq);
#endif
	return l;
}
