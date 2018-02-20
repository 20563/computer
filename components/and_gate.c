#include "and_gate.h"
/**
 * and_gate
 *
 * truth table
 * input_A | 0 | 0 | 1 | 1 |
 * input_B | 0 | 1 | 0 | 1 |
 * --------+---+---+---+---+
 * output  | 0 | 0 | 0 | 1 |
 *
 * @input_A: 0 or 1
 * @input_B: 0 or 1
 *
 * Returns : 1 if input_A = 1 and input_B = 1, otherwise 0
 *
 */

u8 and_gate(const u8 input_A, const u8 input_B)
{
	u8 output;

	output = transistor(input_A);
	if (output)
		output = transistor(input_B);

	return output;
}


/** and_gate_multi - now we have and_gate model
 * so we can reuse this model and make multiple input and_gate
 *
 * @num: number of inputs, at least 2 input are required
 * @...: input bits list depends on @num
 *
 * Returns: 1 if all inputs are 1, otherwise 0
 */

u8 and_gate_multi(u8 num, ...)
{
	va_list args;
	u8 state;
	u8 output;

	if (num > 1) {
		va_start(args, num);
		state = va_arg(args, int);
		output = state;
#ifdef AND_DBG
		printf("i %d state %d, output %d\n", num, state, output);
#endif
		while (num-- != 1) {
			state = va_arg(args, int);
			output = and_gate(output, state);
#ifdef AND_DBG
			printf("i %d state %d, output %d\n",
				num, state, output);
#endif
		}
	}
	va_end(args);

	return output;
}
