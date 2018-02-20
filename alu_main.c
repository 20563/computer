#include "tests.h"
#include "computer_clock.h"

int main(void)
{
	clock_initialize();
#ifdef TEST_MODE
	tests();
#endif
	clock_stop();
	return 0;
}
