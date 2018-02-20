#ifndef _DEMULTIPLEXER_H_
#define _DEMULTIPLEXER_H_

#include "and_gate.h"
#include "not_gate.h"

struct demultiplexer {
	u8 output_0:1;
	u8 output_1:1;
	u8 output_2:1;
	u8 output_3:1;
};

struct demultiplexer demultiplexer1x4(
	u8 data
	, u8 select_0
	, u8 select_1
	);

#endif /* _DEMULTIPLEXER_H_ */
