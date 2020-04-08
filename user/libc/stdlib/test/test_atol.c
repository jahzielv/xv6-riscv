#include "test_stdlib.h"

int test_atol(void) {
    char *y = "2147483647";
    long y_long = atol_os(y);
    if (y_long != 2147483647) {
        return 0;
    }
    return 1;
}
