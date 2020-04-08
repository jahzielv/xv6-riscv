#include "test_stdio.h"

int test_fputs(void) {
    char *str = "This is an fputs string\n";
    fputs(str, stdout);
    return 1;
}
