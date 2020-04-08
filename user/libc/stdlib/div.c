#include "stdlib.h"

div_t div_os(int num, int den)
{
	return (div_t){ num/den, num%den };
}

