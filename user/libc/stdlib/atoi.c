#include "stdlib.h"
int atoi_os(char *str) {
    int n = 0;
    while (*str > 47 && *str < 58)
        n = 10*n + (*str++ - '0');
    return n;
}
