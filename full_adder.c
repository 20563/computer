#include "full_adder.h"

/**
 * full_adder - full_adder adding two input bits and
 * carry from previous operation then
 * returns result separately for sum and carry
 *
 * truth table
 * input_A  | 0 | 0 | 0 | 0 | 1 | 1 | 1 | 1 |
 * input_B  | 0 | 0 | 1 | 1 | 0 | 0 | 1 | 1 |
 * carry_in | 0 | 1 | 0 | 1 | 0 | 1 | 0 | 1 |
 * ---------+---+---+---+---+---+---+---+---+
 * sum      | 0 | 1 | 1 | 0 | 1 | 0 | 0 | 1 |
 * carry    | 0 | 0 | 0 | 1 | 0 | 1 | 1 | 1 |
 *
 * @input_A: 0 or 1
 * @input_B: 0 or 1
 * @carry_in: 0 or 1
 *
 * Returns : struct adder with 1 bit sum and carry
 *
 */

struct adder full_adder(u8 input_A, u8 input_B, u8 carry_in)
{
	static struct adder a;
	u8 ha_carry;

	a = half_adder(input_A, input_B);
	ha_carry = a.carry;
	a = half_adder(a.sum, carry_in);
	a.carry = or_gate(ha_carry, a.carry);
	return a;
}
