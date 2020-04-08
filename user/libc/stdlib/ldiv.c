#include "stdlib.h"

ldiv_t ldiv_os(long num, long den)
{
	return (ldiv_t){ num/den, num%den };
}
