#include "tests.h"

#ifdef LATCH_ENABLE
void latch_test(void)
{
	static struct latch l;
	static char q[2];
	static char nq[2];

	printf("latch SR state (SET RESET)\n");
	printf("=================================================\n");

	/**
	 * not allowed 0 0 (invalid state)
	 */

	l = latch(0, 1);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("latch 01 reset     Q", q, "1", "NQ", nq, "0", NULL);
	l = latch(1, 0);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("latch 10 set       Q", q, "0", "NQ", nq, "1", NULL);
	l = latch(1, 0);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("latch 10 set       Q", q, "0", "NQ", nq, "1", NULL);
	l = latch(0, 1);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("latch 01 reset     Q", q, "1", "NQ", nq, "0", NULL);
	l = latch(1, 1);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("latch 11 no change Q", q, "1", "NQ", nq, "0", NULL);
	l = latch(1, 1);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("latch 11 no change Q", q, "1", "NQ", nq, "0", NULL);
	l = latch(1, 0);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("latch 10 set       Q", q, "0", "NQ", nq, "1", NULL);
	l = latch(1, 0);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("latch 10 set       Q", q, "0", "NQ", nq, "1", NULL);
	l = latch(1, 0);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("latch 10 set       Q", q, "0", "NQ", nq, "1", NULL);
	l = latch(0, 1);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("latch 01 reset     Q", q, "1", "NQ", nq, "0", NULL);
	l = latch(1, 0);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("latch 10 set       Q", q, "0", "NQ", nq, "1", NULL);
	l = latch(1, 1);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("latch 11 no change Q", q, "0", "NQ", nq, "1", NULL);
	l = latch(1, 1);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("latch 11 no change Q", q, "0", "NQ", nq, "1", NULL);
	l = latch(1, 1);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("latch 11 no change Q", q, "0", "NQ", nq, "1", NULL);
	l = latch(1, 1);
	sprintf(q, "%d", l.q);
	sprintf(nq, "%d", l.nq);
	test("latch 11 no change Q", q, "0", "NQ", nq, "1", NULL);
	printf("\n");
}
#endif /* LATCH_ENABLE */
