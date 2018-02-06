#include "tests.h"

#ifdef TRANSISTOR_ENABLE
void transistor_test(void)
{
	char output[2];

	sprintf(output, "%d", transistor(0));
	test("transistor", output, "0", NULL);
	sprintf(output, "%d", transistor(1));
	test("transistor", output, "1", NULL);
	printf("\n");
}
#endif /* TRANSISTOR_ENABLE */
