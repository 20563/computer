#include "tests.h"

#ifdef TEST_MODE
void test(const char *str, ...)
{
	va_list args;
	char **pair = malloc(3 * sizeof(*pair));
	int i = 0;

	va_start(args, str);
	while (str) {
		if (i != 3) {
			pair[i] = (char *)malloc(strlen(str) + 1);
			sprintf(pair[i], "%s", str);
			i++;
			if (i == 3) {
				printf("%s %s is [%s] expected [%s] ", pair[0]
					, (strcmp(pair[1], pair[2]) == 0)
						? "pass" : "fail"
					, pair[1], pair[2]);
				i = 0;
			}
		}
		str = va_arg(args, const char*);
	}
	i = 0;
	while (i == 3) {
		free(pair[i]);
		i++;
	}
	free(pair);
	va_end(args);
	printf("\n");
}

void tests(void)
{
#ifdef TRANSISTOR_ENABLE
	transistor_test();
#endif /* TRANSISTOR_ENABLE */

#ifdef AND_ENABLE
	and_gate_test();
#endif /* AND_ENABLE */

#ifdef OR_ENABLE
	or_gate_test();
#endif /* OR_ENABLE */

#ifdef NOT_ENABLE
	not_gate_test();
#endif /* NOT_ENABLE */

#ifdef NOR_ENABLE
	nor_gate_test();
#endif /* NOR_ENABLE */

#ifdef NAND_ENABLE
	nand_gate_test();
	nand_gate_multi_test();
#endif /* NAND_ENABLE */

#ifdef LATCH_ENABLE
	latch_test();
#endif /* LATCH_ENABLE */

#ifdef FLIPFLOP_ENABLE
	flipflop_rs_test();
#ifdef NOT_ENABLE
	flipflop_d_test();
#endif /* NOT_ENABLE */
#endif /* FLIPFLOP_ENABLE */

#ifdef XOR_ENABLE
	xor_gate_test();
#endif /* XOR_ENABLE */

#ifdef ADDER_ENABLE
	half_adder_test();
	full_adder_test();
	adder_8bit_test();
#endif /* ADDER_ENABLE */

#ifdef MULTIPLEXER_ENABLE
	multiplexer4x1_test();
#endif /* MULTIPLEXER_ENABLE */
}
#endif /* TEST_MODE */
