#include "test_stdio.h"

int test_printf(void) {
    int d = 42;
    int x = 0x1BADB002;
    char c = 'Q';
    char *s = "This is a sample string";
    printf_os("PRINTF/VPRINTF TEST: %d %x %c %s\n", d, x, c, s);
    return 1;
}
