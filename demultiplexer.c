#include "demultiplexer.h"

/**
 * demultiplexer1x4 - demultiplexer 1 to 4
 * redirecting input data on selected output
 *
 * truth table
 * data     |    1    |    1    |    1    |    1    |
 * select_0 |    0    |    1    |    0    |    1    |
 * select_1 |    0    |    0    |    1    |    1    |
 * ---------+---------+---------+---------+---------+
 * output   | input_0 | input_1 | input_2 | input_3 |
 *
 * @data - 1 bit input data, 0 or 1
 * @select_[0..1] - 2 bit selector, 0 or 1
 *
 * Returns : struct demultiplexer, which storing selected output
 *
 */

struct demultiplexer demultiplexer1x4(
	const u8 data
	, const u8 select_0
	, const u8 select_1
	)
{
	struct demultiplexer d;
	u8 n_select_0 = not_gate(select_0);
	u8 n_select_1 = not_gate(select_1);

	d.output_0 = and_gate_multi(3, data, n_select_0, n_select_1);
	d.output_1 = and_gate_multi(3, data, select_0, n_select_1);
	d.output_2 = and_gate_multi(3, data, n_select_0, select_1);
	d.output_3 = and_gate_multi(3, data, select_0, select_1);

	return d;
}
