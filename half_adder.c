#include "half_adder.h"

/**
 * half_adder - half adder adding two bits then
 * returns result separately for sum and carry
 *
 * truth table
 * input_A | 0 | 0 | 1 | 1 |
 * input_B | 0 | 1 | 0 | 1 |
 * --------+---+---+---+---+
 * sum     | 0 | 1 | 1 | 0 |
 * carry   | 0 | 0 | 0 | 1 |
 *
 * @input_A: 0 or 1
 * @input_B: 0 or 1
 *
 * Returns : struct adder which storing
 * 1 bit sum and 1 bit carry
 *
 */

struct adder half_adder(u8 input_A, u8 input_B)
{
	static struct adder a;

	a.sum = xor_gate(input_A, input_B);
	a.carry = and_gate(input_A, input_B);
	return a;
}
