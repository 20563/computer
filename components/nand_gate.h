#ifndef _NAND_GATE_H_
#define _NAND_GATE_H_

#include <stdarg.h>

#ifdef AND_ENABLE
#include "and_gate.h"
#else
#include "transistor.h"
#endif

const u8 nand_gate(u8 input_A, u8 input_B);
const u8 nand_gate_multi(u8 input, ...);

#endif /* _NAND_GATE_H_ */
