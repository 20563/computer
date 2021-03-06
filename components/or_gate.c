#include "or_gate.h"

/**
 * or_gate
 *
 * truth table
 * input_A | 0 | 0 | 1 | 1 |
 * input_B | 0 | 1 | 0 | 1 |
 * --------+---+---+---+---+
 * output  | 0 | 1 | 1 | 1 |
 *
 * @input_A: 0 or 1
 * @input_B: 0 or 1
 *
 * Returns : 1 if input_A = 1 or input_B = 1, otherwise 0
 *
 */

const u8 or_gate(u8 input_A, u8 input_B)
{
	static u8 output;

	output = transistor(input_A);
	if (!output)
		output = transistor(input_B);

	return output;
}
