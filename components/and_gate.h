#ifndef _AND_GATE_H_
#define _AND_GATE_H_

#include <stdarg.h>
#include "transistor.h"

u8 and_gate(u8 input_A, u8 input_B);
u8 and_gate_multi(u8 num, ...);

#endif /* _AND_GATE_H_ */
