#include "tests.h"

#ifdef OR_ENABLE
void or_gate_test(void)
{
	char output[2];

	sprintf(output, "%d", or_gate(0, 0));
	test("or_gate", output, "0", NULL);
	sprintf(output, "%d", or_gate(0, 1));
	test("or_gate", output, "1", NULL);
	sprintf(output, "%d", or_gate(1, 0));
	test("or_gate", output, "1", NULL);
	sprintf(output, "%d", or_gate(1, 1));
	test("or_gate", output, "1", NULL);
	printf("\n");
}
#endif /* OR_ENABLE */
