#include "nor_gate.h"

/**
 * nand_gate
 *
 * truth table
 * input_A | 0 | 0 | 1 | 1 |
 * input_B | 0 | 1 | 0 | 1 |
 * --------+---+---+---+---+
 * output  | 1 | 0 | 0 | 0 |
 *
 * @input_A: 0 or 1
 * @input_B: 0 or 1
 *
 * Returns : 1 if input_A = 0 and input_B = 0, otherwise 0
 *
 */

const u8 nor_gate(u8 input_A, u8 input_B)
{
	u8 output;

	output = not_gate(input_A);
	if (output)
		output = not_gate(input_B);

	return output;
}
