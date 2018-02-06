#include "tests.h"

#ifdef AND_ENABLE
void and_gate_test(void)
{
	char output[2];

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
#endif /* AND_ENABLE */
