#include "xor_gate.h"

/**
 * nand_gate
 *
 * truth table
 * input_A | 0 | 0 | 1 | 1 |
 * input_B | 0 | 1 | 0 | 1 |
 * --------+---+---+---+---+
 * output  | 0 | 1 | 1 | 0 |
 *
 * @input_A: 0 or 1
 * @input_B: 0 or 1
 *
 * Returns : 0 if input_A == input_B, otherwise 1
 *
 */

const u8 xor_gate(u8 input_A, u8 input_B)
{
	return
	and_gate(
		or_gate(input_A, input_B)
		, nand_gate(input_A, input_B)
	);
}
