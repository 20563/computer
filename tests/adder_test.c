#include "tests.h"

#ifdef ADDER_ENABLE
void half_adder_test(void)
{
	static struct adder a;
	static char sum[2];
	static char carry[2];

	a = half_adder(0, 0);
	sprintf(sum, "%d", a.sum);
	sprintf(carry, "%d", a.carry);
	test("half_adder sum", sum, "0", "carry", carry, "0", NULL);
	a = half_adder(0, 1);
	sprintf(sum, "%d", a.sum);
	sprintf(carry, "%d", a.carry);
	test("half_adder sum", sum, "1", "carry", carry, "0", NULL);
	a = half_adder(1, 0);
	sprintf(sum, "%d", a.sum);
	sprintf(carry, "%d", a.carry);
	test("half_adder sum", sum, "1", "carry", carry, "0", NULL);
	a = half_adder(1, 1);
	sprintf(sum, "%d", a.sum);
	sprintf(carry, "%d", a.carry);
	test("half_adder sum", sum, "0", "carry", carry, "1", NULL);
	printf("\n");
}

void full_adder_test(void)
{
	static struct adder a;
	static char sum[2];
	static char carry[2];

	a = full_adder(0, 0, 0);
	sprintf(sum, "%d", a.sum);
	sprintf(carry, "%d", a.carry);
	test("full_adder sum", sum, "0", "carry", carry, "0", NULL);
	a = full_adder(0, 0, 1);
	sprintf(sum, "%d", a.sum);
	sprintf(carry, "%d", a.carry);
	test("full_adder sum", sum, "1", "carry", carry, "0", NULL);
	a = full_adder(0, 1, 0);
	sprintf(sum, "%d", a.sum);
	sprintf(carry, "%d", a.carry);
	test("full_adder sum", sum, "1", "carry", carry, "0", NULL);
	a = full_adder(0, 1, 1);
	sprintf(sum, "%d", a.sum);
	sprintf(carry, "%d", a.carry);
	test("full_adder sum", sum, "0", "carry", carry, "1", NULL);
	a = full_adder(1, 0, 0);
	sprintf(sum, "%d", a.sum);
	sprintf(carry, "%d", a.carry);
	test("full_adder sum", sum, "1", "carry", carry, "0", NULL);
	a = full_adder(1, 0, 1);
	sprintf(sum, "%d", a.sum);
	sprintf(carry, "%d", a.carry);
	test("full_adder sum", sum, "0", "carry", carry, "1", NULL);
	a = full_adder(1, 1, 0);
	sprintf(sum, "%d", a.sum);
	sprintf(carry, "%d", a.carry);
	test("full_adder sum", sum, "0", "carry", carry, "1", NULL);
	a = full_adder(1, 1, 1);
	sprintf(sum, "%d", a.sum);
	sprintf(carry, "%d", a.carry);
	test("full_adder sum", sum, "1", "carry", carry, "1", NULL);
	printf("\n");
}

void adder_8bit_test(void)
{
	static struct adder_8bit a8b;
	static char sum[9];
	static char carry[2];

	a8b = adder_8bit(0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("adder_8bit", sum, "00000001", "carry", carry, "0", NULL);
	a8b = adder_8bit(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("adder_8bit", sum, "00000000", "carry", carry, "0", NULL);
	a8b = adder_8bit(0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("adder_8bit", sum, "11111110", "carry", carry, "1", NULL);
	a8b = adder_8bit(1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("adder_8bit", sum, "00000001", "carry", carry, "0", NULL);
	a8b = adder_8bit(1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("adder_8bit", sum, "00000010", "carry", carry, "0", NULL);
	a8b = adder_8bit(0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("adder_8bit", sum, "11111111", "carry", carry, "0", NULL);
	a8b = adder_8bit(1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("adder_8bit", sum, "00000000", "carry", carry, "1", NULL);
	a8b = adder_8bit(0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("adder_8bit", sum, "00000000", "carry", carry, "1", NULL);
	a8b = adder_8bit(1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("adder_8bit", sum, "00000001", "carry", carry, "1", NULL);
	printf("\n");
}
#endif /* ADDER_ENABLE */
