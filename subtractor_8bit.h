#ifndef _SUBTRACTOR_8BIT_H_
#define _SUBTRACTOR_8BIT_H_

#include "adder_8bit.h"

struct adder_8bit subtractor_8bit(u8 selector
	, u8 input_A7
	, u8 input_A6
	, u8 input_A5
	, u8 input_A4
	, u8 input_A3
	, u8 input_A2
	, u8 input_A1
	, u8 input_A0
	, u8 input_B7
	, u8 input_B6
	, u8 input_B5
	, u8 input_B4
	, u8 input_B3
	, u8 input_B2
	, u8 input_B1
	, u8 input_B0);

#endif /* _SUBTRACTOR_8BIT_H_ */
