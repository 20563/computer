#ifndef _ALU_TESTS_H_
#define _ALU_TESTS_H_

#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include "nor_gate.h"
#include "multiplexer.h"
#include "adder_8bit.h"
#include "flipflop_d.h"

void test(const char *str, ...);

void transistor_test(void);
void not_gate_test(void);
void and_gate_test(void);
void nand_gate_test(void);
void nand_gate_multi_test(void);
void or_gate_test(void);
void nor_gate_test(void);
void xor_gate_test(void);
void half_adder_test(void);
void full_adder_test(void);
void multiplexer4x1_test(void);
void adder_8bit_test(void);
void latch_test(void);
void flipflop_rs_test(void);
void flipflop_d_test(void);

void tests(void);

#endif /* _ALU_TESTS_H_ */
