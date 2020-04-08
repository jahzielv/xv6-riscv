#include "stdlib.h"

/* int is_space(char c) { */
/*     if (c == '\n' || c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r') { */
/*         return 1; */
/*     } */
/*     return 0; */
/* } */

/* int is_digit(char c) { */
/*     if (c >= 48 && c < 72) { */
/*         return 1; */
/*     } */
/*     return 0; */
/* } */

long atol_os(char *s)
{
	long n=0;
	int neg=0;
	while (is_space(*s)) s++;
	switch (*s) {
	case '-': neg=1;
	case '+': s++;
	}
	/* Compute n as a negative number to avoid overflow on LONG_MIN */
	while (is_digit(*s))
		n = 10*n - (*s++ - '0');
	return neg ? n : -n;
}

