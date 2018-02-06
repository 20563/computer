#include "adder_8bit.h"

/**
 * adder_8bit - 8 bit adder, to add two 8 bit numbers
 *
 * @carry_in: 0 or 1
 * @input_A[7..0]: 0 or 1
 * @input_B[7..0]: 0 or 1
 *
 * Returns : struct adder_8bit with 8 bit sum and carry
 *
 */

struct adder_8bit adder_8bit(u8 carry_in
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

	a8b.a[0] = full_adder(input_A0, input_B0, carry_in);
	a8b.a[1] = full_adder(input_A1, input_B1, a8b.a[0].carry);
	a8b.a[2] = full_adder(input_A2, input_B2, a8b.a[1].carry);
	a8b.a[3] = full_adder(input_A3, input_B3, a8b.a[2].carry);
	a8b.a[4] = full_adder(input_A4, input_B4, a8b.a[3].carry);
	a8b.a[5] = full_adder(input_A5, input_B5, a8b.a[4].carry);
	a8b.a[6] = full_adder(input_A6, input_B6, a8b.a[5].carry);
	a8b.a[7] = full_adder(input_A7, input_B7, a8b.a[6].carry);
	flags.c = a8b.a[7].carry;
	return a8b;
}
