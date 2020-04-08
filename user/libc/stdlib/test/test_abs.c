#include "test_stdlib.h"

// hello
int test_abs(void) {
    int neg = -4;
    int retval = abs_os(neg);
    if (retval != 4) {
        return 0;
    }
    return 1;

}
