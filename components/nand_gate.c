#include "nand_gate.h"

/**
 * nand_gate
 *
 * truth table
 * input_A | 0 | 0 | 1 | 1 |
 * input_B | 0 | 1 | 0 | 1 |
 * --------+---+---+---+---+
 * output  | 1 | 1 | 1 | 0 |
 *
 * @input_A: 0 or 1
 * @input_B: 0 or 1
 *
 * Returns : 0 if input_A = 1 and input_B = 1, otherwise 1
 *
 */

const u8 nand_gate(u8 input_A, u8 input_B)
{
	u8 output = VCC;

	if (transistor(input_A))
		if (transistor(input_B))
			output = GND;

	return output;
}

/** nand_gate_multi - now we have nand_gate model
 * so we can reuse this model and make multiple input nand_gate
 *
 * @num: number of inputs, at least 2 input are required
 * @...: input bits list depends on @num
 *
 * Returns: 0 if all inputs are 1, otherwise 1
 */

const u8 nand_gate_multi(u8 num, ...)
{
	static va_list args;
	static u8 state;
	static u8 output;

	if (num > 1) {
		va_start(args, num);
		state = va_arg(args, int);
		output = state;
#ifdef NAND_DBG
		printf("i %d state %d, output %d\n", num, state, output);
#endif
		while (num-- != 1) {
			state = va_arg(args, int);

/* with and_gate we do not require excessive gates
 * and we save on compute time
 */

#ifdef AND_ENABLE
			output = and_gate(output, state);
			if (num == 1)
#else
			output = nand_gate(output, state);
			if (num != 1)
#endif
				output = nand_gate(output, output);
#ifdef NAND_DBG
			printf("i %d state %d, output %d\n",
				num, state, output);
#endif
		}
	}
	va_end(args);

	return output;
}
