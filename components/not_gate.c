#include "not_gate.h"

/**
 * not_gate - not gate is used to negate input signal
 * to negate input signal in not gate we will use transistor NPN
 * in normal state current flow form Collector directly to circuit
 * to control that, first we need to ground the Emitter,
 * then when we add current to Base, current flow from Collector
 * through Emitter directly to the groud.
 *
 * truth table
 * input  | 0 | 1 |
 * -------+---+---+
 * output | 1 | 0 |
 *
 * @input: 0 or 1
 *
 * Returns : 0 if current flow "input = 1 (Ic = 1 and Ib = 1)", otherwise 1
 *
 */

const u8 not_gate(u8 input)
{
	u8 output = VCC;

	if (transistor(input))
		output = GND;

	return output;
}
