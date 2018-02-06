#include "tests.h"

#ifdef NOR_ENABLE
void nor_gate_test(void)
{
	char output[2];

	sprintf(output, "%d", nor_gate(0, 0));
	test("nor_gate", output, "1", NULL);
	sprintf(output, "%d", nor_gate(0, 1));
	test("nor_gate", output, "0", NULL);
	sprintf(output, "%d", nor_gate(1, 0));
	test("nor_gate", output, "0", NULL);
	sprintf(output, "%d", nor_gate(1, 1));
	test("nor_gate", output, "0", NULL);
	printf("\n");
}
#endif /* NOR_ENABLE */
