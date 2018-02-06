#include "tests.h"

int main(void)
{
#ifdef TEST_MODE
	tests();
#endif
	return 0;
}
