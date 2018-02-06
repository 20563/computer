#ifndef _MULTIPLEXER_H_
#define _MULTIPLEXER_H_

#include "or_gate.h"
#include "and_gate.h"
#include "not_gate.h"

u8 multiplexer4x1(
	u8 input_0
	, u8 input_1
	, u8 input_2
	, u8 input_3
	, u8 select_0
	, u8 select_1
	);

#endif /* _MULTIPLEXER_H_ */
