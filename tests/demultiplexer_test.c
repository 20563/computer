#include "tests.h"

#ifdef DEMULTIPLEXER_ENABLE
void demultiplexer1x4_test(void)
{
	struct demultiplexer d;
	char output[5];

	printf("demultiplexer1x4 D S0 S1  output [3210]\n");
	printf("=================================================\n");
	d = demultiplexer1x4(0, 0, 0);
	sprintf(output, "%d%d%d%d"
		, d.output_3, d.output_2, d.output_1, d.output_0);
	test("demultiplexer1x4 0  0  0", output, "0000", NULL);
	d = demultiplexer1x4(1, 0, 0);
	sprintf(output, "%d%d%d%d"
		, d.output_3, d.output_2, d.output_1, d.output_0);
	test("demultiplexer1x4 1  0  0", output, "0001", NULL);
	d = demultiplexer1x4(0, 0, 1);
	sprintf(output, "%d%d%d%d"
		, d.output_3, d.output_2, d.output_1, d.output_0);
	test("demultiplexer1x4 0  0  1", output, "0000", NULL);
	d = demultiplexer1x4(1, 0, 1);
	sprintf(output, "%d%d%d%d"
		, d.output_3, d.output_2, d.output_1, d.output_0);
	test("demultiplexer1x4 1  0  1", output, "0100", NULL);
	d = demultiplexer1x4(0, 1, 0);
	sprintf(output, "%d%d%d%d"
		, d.output_3, d.output_2, d.output_1, d.output_0);
	test("demultiplexer1x4 0  1  0", output, "0000", NULL);
	d = demultiplexer1x4(1, 1, 0);
	sprintf(output, "%d%d%d%d"
		, d.output_3, d.output_2, d.output_1, d.output_0);
	test("demultiplexer1x4 1  1  0", output, "0010", NULL);
	d = demultiplexer1x4(0, 1, 1);
	sprintf(output, "%d%d%d%d"
		, d.output_3, d.output_2, d.output_1, d.output_0);
	test("demultiplexer1x4 0  1  1", output, "0000", NULL);
	d = demultiplexer1x4(1, 1, 1);
	sprintf(output, "%d%d%d%d"
		, d.output_3, d.output_2, d.output_1, d.output_0);
	test("demultiplexer1x4 1  1  1", output, "1000", NULL);
	printf("\n");
}
#endif /* DEMULTIPLEXER_ENABLE */
