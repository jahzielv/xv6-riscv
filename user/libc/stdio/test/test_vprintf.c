#include "test_stdio.h"

int test_vprintf(int firstarg, ...) {
    va_list list;
    va_start(list, firstarg);
    vprintf("VPRINTF TEST: %d %x %c %s\n", list);
    va_end(list);
    return 1;
}
