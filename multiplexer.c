#include "multiplexer.h"

/**
 * multiplexer4x1 - multiplexer 4 to 1
 *
 * truth table
 * select_1 |    0    |    0    |    1    |    1    |
 * select_0 |    0    |    1    |    0    |    1    |
 * ---------+---------+---------+---------+---------+
 * output   | input_0 | input_1 | input_2 | input_3 |
 *
 * @input_[0..3] - 4 bit input data, 0 or 1
 * @select_[0..1] - 2 bit selector, 0 or 1
 *
 * Returns : output from selected input_[0..3], 0 or 1
 *
 */

u8 multiplexer4x1(
	u8 input_0
	, u8 input_1
	, u8 input_2
	, u8 input_3
	, u8 select_0
	, u8 select_1
	)
{
	return
	or_gate(
		or_gate(
			or_gate(
				and_gate(
					and_gate(input_0, not_gate(select_1))
					, not_gate(select_0)
				)
				, and_gate(
					and_gate(input_1, not_gate(select_1))
					, select_0)
			)
			, and_gate(
				and_gate(input_2, select_1)
				, not_gate(select_0)
			)
		)
		, and_gate(
			and_gate(input_3, select_0)
			, select_1
		)
	);
}
