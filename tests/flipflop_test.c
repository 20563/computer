#include "tests.h"

#ifdef FLIPFLOP_ENABLE
void flipflop_rs_test(void)
{
	static struct latch l;
	static char q[2];
	static char nq[2];

	printf("flipflop_rs SRC state (Set Reset Clock)\n");
	printf("=================================================\n");
	/**
	 * SRC 111 indeterminate not allowed
	 */

	l = flipflop_rs(0, 0, 0);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_rs 000 no change     Q", q, "0", "NQ", nq, "1", NULL);
	l = flipflop_rs(1, 0, 0);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_rs 100 no change     Q", q, "0", "NQ", nq, "1", NULL);
	l = flipflop_rs(1, 0, 1);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_rs 101 set           Q", q, "1", "NQ", nq, "0", NULL);
	l = flipflop_rs(0, 0, 1);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_rs 001 no change     Q", q, "1", "NQ", nq, "0", NULL);
	l = flipflop_rs(0, 1, 1);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_rs 011 reset         Q", q, "0", "NQ", nq, "1", NULL);
	l = flipflop_rs(0, 1, 0);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_rs 010 no change     Q", q, "0", "NQ", nq, "1", NULL);
	l = flipflop_rs(0, 0, 0);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_rs 000 no change     Q", q, "0", "NQ", nq, "1", NULL);
	l = flipflop_rs(0, 0, 1);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_rs 001 no change     Q", q, "0", "NQ", nq, "1", NULL);
	l = flipflop_rs(1, 0, 1);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_rs 101 set           Q", q, "1", "NQ", nq, "0", NULL);
	l = flipflop_rs(1, 0, 0);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_rs 100 no change     Q", q, "1", "NQ", nq, "0", NULL);
	l = flipflop_rs(0, 0, 0);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_rs 000 no change     Q", q, "1", "NQ", nq, "0", NULL);
	l = flipflop_rs(0, 1, 0);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_rs 010 no change     Q", q, "1", "NQ", nq, "0", NULL);
	l = flipflop_rs(0, 1, 1);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_rs 011 reset         Q", q, "0", "NQ", nq, "1", NULL);
	l = flipflop_rs(0, 1, 0);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_rs 010 no change     Q", q, "0", "NQ", nq, "1", NULL);
	l = flipflop_rs(0, 0, 0);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_rs 000 no change     Q", q, "0", "NQ", nq, "1", NULL);
//  indeterminate not allowed
//	l = flipflop_rs(1, 1, 1);
//	sprintf(q, "%d", l.q);
//	sprintf(nq, "%d", l.nq);
//	test("flipflop_rs 111 indeterminate Q", q, "1", "NQ", nq, "1", NULL);
	printf("\n");
}

#ifdef NOT_ENABLE
void flipflop_d_test(void)
{
	static struct latch l;
	static char q[2];
	static char nq[2];

	printf("flipflop_d DC state (Data Clock)\n");
	printf("=================================================\n");
	l = flipflop_d(0, 0);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_d 00 no change     Q", q, "0", "NQ", nq, "1", NULL);
	l = flipflop_d(0, 1);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_d 01 reset         Q", q, "0", "NQ", nq, "1", NULL);
	l = flipflop_d(1, 1);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_d 11 set           Q", q, "1", "NQ", nq, "0", NULL);
	l = flipflop_d(1, 0);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_d 10 no change     Q", q, "1", "NQ", nq, "0", NULL);
	l = flipflop_d(0, 0);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_d 00 no change     Q", q, "1", "NQ", nq, "0", NULL);
	l = flipflop_d(1, 0);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_d 10 no change     Q", q, "1", "NQ", nq, "0", NULL);
	l = flipflop_d(1, 1);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_d 11 set           Q", q, "1", "NQ", nq, "0", NULL);
	l = flipflop_d(0, 1);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_d 01 reset         Q", q, "0", "NQ", nq, "1", NULL);
	l = flipflop_d(1, 1);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_d 11 set           Q", q, "1", "NQ", nq, "0", NULL);
	l = flipflop_d(1, 0);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_d 10 no change     Q", q, "1", "NQ", nq, "0", NULL);
	l = flipflop_d(0, 0);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_d 00 no change     Q", q, "1", "NQ", nq, "0", NULL);
	l = flipflop_d(1, 1);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_d 11 set           Q", q, "1", "NQ", nq, "0", NULL);
	l = flipflop_d(0, 1);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_d 01 reset         Q", q, "0", "NQ", nq, "1", NULL);
	l = flipflop_d(1, 0);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("flipflop_d 10 no change     Q", q, "0", "NQ", nq, "1", NULL);
	printf("\n");
}
#endif /* NOT_ENABLE */
#endif /* FLIPFLOP_ENABLE */
