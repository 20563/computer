#include "tests.h"

#ifdef SUBTRACTOR_ENABLE

void subtractor_8bit_test(void)
{
	static struct adder_8bit a8b;
	static char sum[9];
	static char carry[2];

	printf("subtraction\n");
	printf("=================================================\n");
	a8b = subtractor_8bit(1, 0, 0, 0, 0, 0, 0, 0, 1
		, 0, 0, 0, 0, 0, 0, 0, 0);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("subtractor_8bit   1 -   0 =    1"
		, sum, "00000001", "carry", carry, "0", NULL);
	a8b = subtractor_8bit(1, 0, 0, 0, 0, 0, 0, 0, 0
		, 0, 0, 0, 0, 0, 0, 0, 0);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("subtractor_8bit   0 -   0 =    0"
		, sum, "00000000", "carry", carry, "0", NULL);
	a8b = subtractor_8bit(1, 1, 1, 1, 1, 1, 1, 1, 1
		, 1, 1, 1, 1, 1, 1, 1, 1);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("subtractor_8bit 255 - 255 =    0"
		, sum, "00000000", "carry", carry, "0", NULL);
	a8b = subtractor_8bit(1, 1, 0, 0, 0, 0, 0, 0, 0
		, 1, 1, 1, 1, 1, 1, 1, 1);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("subtractor_8bit 128 - 255 = -127"
		, sum, "10000001", "carry", carry, "1", NULL);
	a8b = subtractor_8bit(1, 1, 0, 1, 0, 1, 0, 1, 0
		, 0, 1, 0, 1, 0, 1, 0, 1);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("subtractor_8bit 170 -  85 =   85"
		, sum, "01010101", "carry", carry, "0", NULL);
	a8b = subtractor_8bit(1, 0, 1, 0, 1, 0, 1, 0, 1
		, 1, 0, 1, 0, 1, 0, 1, 0);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("subtractor_8bit  85 - 170 =  -85"
		, sum, "10101011", "carry", carry, "1", NULL);
	a8b = subtractor_8bit(1, 0, 0, 1, 0, 1, 0, 1, 0
		, 1, 0, 1, 0, 1, 0, 1, 0);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("subtractor_8bit  42 - 170 = -128"
		, sum, "10000000", "carry", carry, "1", NULL);
	a8b = subtractor_8bit(1, 0, 0, 0, 0, 0, 0, 0, 0
		, 1, 1, 1, 1, 1, 1, 1, 1);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("subtractor_8bit   0 - 255 = -255"
		, sum, "00000001", "carry", carry, "1", NULL);
	a8b = subtractor_8bit(1, 1, 1, 1, 1, 1, 1, 1, 1
		, 0, 0, 0, 0, 0, 0, 0, 1);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("subtractor_8bit 255 -   1 =  254"
		, sum, "11111110", "carry", carry, "0", NULL);
	printf("\n");

	printf("addition\n");
	printf("=================================================\n");
	a8b = subtractor_8bit(0, 1, 1, 1, 1, 1, 1, 1, 1
		, 1, 1, 1, 1, 1, 1, 1, 1);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("subtractor_8bit 255 + 255 =  510"
		, sum, "11111110", "carry", carry, "1", NULL);
	a8b = subtractor_8bit(0, 1, 0, 0, 0, 0, 0, 0, 0
		, 1, 1, 1, 1, 1, 1, 1, 1);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("subtractor_8bit 128 + 255 =  383"
		, sum, "01111111", "carry", carry, "1", NULL);
	a8b = subtractor_8bit(0, 1, 0, 1, 0, 1, 0, 1, 0
		, 0, 1, 0, 1, 0, 1, 0, 1);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("subtractor_8bit 170 +  85 =  255"
		, sum, "11111111", "carry", carry, "0", NULL);
	a8b = subtractor_8bit(0, 0, 0, 1, 0, 1, 0, 1, 0
		, 1, 0, 1, 0, 1, 0, 1, 0);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("subtractor_8bit  42 + 170 =  212"
		, sum, "11010100", "carry", carry, "0", NULL);
	a8b = subtractor_8bit(0, 1, 1, 1, 1, 1, 1, 1, 1
		, 0, 0, 0, 0, 0, 0, 0, 0);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("subtractor_8bit 255 +   0 =  255"
		, sum, "11111111", "carry", carry, "0", NULL);
	a8b = subtractor_8bit(0, 0, 0, 0, 0, 0, 0, 0, 0
		, 1, 1, 1, 1, 1, 1, 1, 1);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("subtractor_8bit   0 + 255 =  255"
		, sum, "11111111", "carry", carry, "0", NULL);
	a8b = subtractor_8bit(0, 1, 1, 1, 1, 1, 1, 1, 1
		, 0, 0, 0, 0, 0, 0, 0, 1);
	sprintf(sum, "%d%d%d%d%d%d%d%d", a8b.a[7].sum, a8b.a[6].sum
		, a8b.a[5].sum, a8b.a[4].sum, a8b.a[3].sum
		, a8b.a[2].sum, a8b.a[1].sum, a8b.a[0].sum);
	sprintf(carry, "%d", flags.c);
	test("subtractor_8bit 255 +   1 =  256"
		, sum, "00000000", "carry", carry, "1", NULL);
	printf("\n");
}
#endif /* SUBTRACTOR_ENABLE */
