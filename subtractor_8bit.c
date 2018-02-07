#include "subtractor_8bit.h"

/**
 * subtractor_8bit - 8 bit subtractor/adder, to subtract/add two 8 bit numbers
 *
 * @selector: 0 or 1
 * @input_A[7..0]: 0 or 1
 * @input_B[7..0]: 0 or 1
 *
 * Returns : struct adder_8bit with 8 bit sum and carry
 *
 */

struct adder_8bit subtractor_8bit(u8 selector
	, u8 input_A7
	, u8 input_A6
	, u8 input_A5
	, u8 input_A4
	, u8 input_A3
	, u8 input_A2
	, u8 input_A1
	, u8 input_A0
	, u8 input_B7
	, u8 input_B6
	, u8 input_B5
	, u8 input_B4
	, u8 input_B3
	, u8 input_B2
	, u8 input_B1
	, u8 input_B0)
{
	static struct adder_8bit a8b;

	a8b = adder_8bit(xor_gate(0, selector)
		, input_A7, input_A6, input_A5, input_A4
		, input_A3, input_A2, input_A1, input_A0
		, xor_gate(input_B7, selector), xor_gate(input_B6, selector)
		, xor_gate(input_B5, selector), xor_gate(input_B4, selector)
		, xor_gate(input_B3, selector), xor_gate(input_B2, selector)
		, xor_gate(input_B1, selector), xor_gate(input_B0, selector));
	flags.c = xor_gate(a8b.a[7].carry, selector);

	return a8b;
}
