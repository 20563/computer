#include "tests.h"

#ifdef NOT_ENABLE
void not_gate_test(void)
{
	char output[2];

	sprintf(output, "%d", not_gate(0));
	test("not_gate", output, "1", NULL);
	sprintf(output, "%d", not_gate(1));
	test("not_gate", output, "0", NULL);
	printf("\n");
}
#endif /* NOT_ENABLE */
