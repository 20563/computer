#ifndef _LATCH_H_
#define _LATCH_H_

#include "nand_gate.h"

struct latch {
	u8 q:1;
	u8 nq:1;
};

struct latch latch(u8 S, u8 R);

#endif /* _LATCH_H_ */
