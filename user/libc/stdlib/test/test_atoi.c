#include "test_stdlib.h"

int test_atoi(void) {
    char *x = "10";
    int retval = atoi_os(x);
    if (retval != 10) {
        return 0;
    }
    return 1;
}
