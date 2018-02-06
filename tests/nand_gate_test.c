#include "tests.h"

#ifdef NAND_ENABLE
void nand_gate_test(void)
{
	char output[2];

	sprintf(output, "%d", nand_gate(0, 0));
	test("nand_gate", output, "1", NULL);
	sprintf(output, "%d", nand_gate(0, 1));
	test("nand_gate", output, "1", NULL);
	sprintf(output, "%d", nand_gate(1, 0));
	test("nand_gate", output, "1", NULL);
	sprintf(output, "%d", nand_gate(1, 1));
	test("nand_gate", output, "0", NULL);
	printf("\n");
}

void nand_gate_multi_test(void)
{
	char output[2];

	sprintf(output, "%d", nand_gate_multi(4, 0, 0, 0, 0));
	test("nand_gate_multi 0000", output, "1", NULL);
	sprintf(output, "%d", nand_gate_multi(4, 1, 1, 1, 1));
	test("nand_gate_multi 1111", output, "0", NULL);

	sprintf(output, "%d", nand_gate_multi(6, 1, 0, 1, 1, 0, 1));
	test("nand_gate_multi 101101", output, "1", NULL);

	sprintf(output, "%d", nand_gate_multi(6, 1, 0, 0, 1, 0, 1));
	test("nand_gate_multi 100101", output, "1", NULL);

	sprintf(output, "%d", nand_gate_multi(6, 1, 0, 0, 0, 0, 1));
	test("nand_gate_multi 100001", output, "1", NULL);

	sprintf(output, "%d", nand_gate_multi(6, 0, 0, 0, 0, 0, 1));
	test("nand_gate_multi 000001", output, "1", NULL);

	sprintf(output, "%d", nand_gate_multi(6, 1, 0, 0, 0, 0, 0));
	test("nand_gate_multi 100000", output, "1", NULL);

	sprintf(output, "%d", nand_gate_multi(6, 0, 0, 0, 0, 0, 0));
	test("nand_gate_multi 000000", output, "1", NULL);

	sprintf(output, "%d", nand_gate_multi(6, 1, 1, 1, 0, 1, 1));
	test("nand_gate_multi 111011", output, "1", NULL);

	sprintf(output, "%d", nand_gate_multi(6, 1, 1, 1, 1, 1, 1));
	test("nand_gate_multi 111111", output, "0", NULL);

	sprintf(output, "%d", nand_gate_multi(7, 1, 1, 1, 1, 1, 1, 1));
	test("nand_gate_multi 1111111", output, "0", NULL);

	sprintf(output, "%d", nand_gate_multi(2, 0, 0));
	test("nand_gate_multi 00", output, "1", NULL);
	sprintf(output, "%d", nand_gate_multi(2, 0, 1));
	test("nand_gate_multi 01", output, "1", NULL);
	sprintf(output, "%d", nand_gate_multi(2, 1, 0));
	test("nand_gate_multi 10", output, "1", NULL);
	sprintf(output, "%d", nand_gate_multi(2, 1, 1));
	test("nand_gate_multi 11", output, "0", NULL);

	printf("\n");
}
#endif /* NAND_ENABLE */
