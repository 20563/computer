#ifndef _TRANSISTOR_H_
#define _TRANSISTOR_H_

#include <time.h>
#include "alu_lib.h"

#define TRANSISTOR_TIMEOUT_SEC 0
#define TRANSISTOR_TIMEOUT_NSEC 5000000

const u8 transistor(const u8 input);

#endif /* _TRANSISTOR_H_ */
