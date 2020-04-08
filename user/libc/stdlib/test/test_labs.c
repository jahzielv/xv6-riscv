#include "test_stdlib.h"

int test_labs(void) {
    long x = -1234;
    if (labs_os(x) != 1234) {
        return 0;
    }
    return 1;
}
