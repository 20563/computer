#include "tests.h"

#ifdef AND_ENABLE
void and_gate_test(void)
{
	static char output[2];

	sprintf(output, "%d", and_gate(0, 0));
	test("and_gate", output, "0", NULL);
	sprintf(output, "%d", and_gate(0, 1));
	test("and_gate", output, "0", NULL);
	sprintf(output, "%d", and_gate(1, 0));
	test("and_gate", output, "0", NULL);
	sprintf(output, "%d", and_gate(1, 1));
	test("and_gate", output, "1", NULL);
	printf("\n");
}

void and_gate_multi_test(void)
{
	static char output[2];

	sprintf(output, "%d", and_gate_multi(2, 0, 0));
	test("and_gate_multi", output, "0", NULL);
	sprintf(output, "%d", and_gate_multi(2, 0, 1));
	test("and_gate_multi", output, "0", NULL);
	sprintf(output, "%d", and_gate_multi(2, 1, 0));
	test("and_gate_multi", output, "0", NULL);
	sprintf(output, "%d", and_gate_multi(2, 1, 1));
	test("and_gate_multi", output, "1", NULL);
	sprintf(output, "%d", and_gate_multi(6, 1, 1, 1, 1, 1, 1));
	test("and_gate_multi", output, "1", NULL);
	sprintf(output, "%d", and_gate_multi(6, 1, 1, 0, 1, 1, 1));
	test("and_gate_multi", output, "0", NULL);
	sprintf(output, "%d", and_gate_multi(4, 1, 1, 0, 1));
	test("and_gate_multi", output, "0", NULL);
	sprintf(output, "%d", and_gate_multi(7, 0, 0, 0, 0, 0, 0, 0));
	test("and_gate_multi", output, "0", NULL);
	sprintf(output, "%d", and_gate_multi(7, 1, 1, 1, 1, 1, 1, 1));
	test("and_gate_multi", output, "1", NULL);
	printf("\n");
}
#endif /* AND_ENABLE */
