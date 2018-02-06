#include "tests.h"

#ifdef XOR_ENABLE
void xor_gate_test(void)
{
	char output[2];

	sprintf(output, "%d", xor_gate(0, 0));
	test("xor_gate", output, "0", NULL);
	sprintf(output, "%d", xor_gate(0, 1));
	test("xor_gate", output, "1", NULL);
	sprintf(output, "%d", xor_gate(1, 0));
	test("xor_gate", output, "1", NULL);
	sprintf(output, "%d", xor_gate(1, 1));
	test("xor_gate", output, "0", NULL);
	printf("\n");
}
#endif /* XOR_ENABLE */
