#include "tests.h"

#ifdef MULTIPLEXER_ENABLE
void multiplexer4x1_test(void)
{
	char output[2];

	sprintf(output, "%d", multiplexer4x1(0, 0, 0, 0, 0, 0));
	test("multiplexer4x1 input_0 = 0", output, "0", NULL);
	sprintf(output, "%d", multiplexer4x1(1, 0, 0, 0, 0, 0));
	test("multiplexer4x1 input_0 = 1", output, "1", NULL);
	sprintf(output, "%d", multiplexer4x1(0, 0, 0, 0, 1, 0));
	test("multiplexer4x1 input_1 = 0", output, "0", NULL);
	sprintf(output, "%d", multiplexer4x1(0, 1, 0, 0, 1, 0));
	test("multiplexer4x1 input_1 = 1", output, "1", NULL);
	sprintf(output, "%d", multiplexer4x1(0, 0, 0, 0, 0, 1));
	test("multiplexer4x1 input_2 = 0", output, "0", NULL);
	sprintf(output, "%d", multiplexer4x1(0, 0, 1, 0, 0, 1));
	test("multiplexer4x1 input_2 = 1", output, "1", NULL);
	sprintf(output, "%d", multiplexer4x1(0, 0, 0, 0, 1, 1));
	test("multiplexer4x1 input_3 = 0", output, "0", NULL);
	sprintf(output, "%d", multiplexer4x1(0, 0, 0, 1, 1, 1));
	test("multiplexer4x1 input_3 = 1", output, "1", NULL);
	printf("\n");
}
#endif /* MULTIPLEXER_ENABLE */
