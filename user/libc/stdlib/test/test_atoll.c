#include "test_stdlib.h"

int test_atoll(void) {
    char *y = "9223372036854775807";
    long long y_long = atoll_os(y);
    if (y_long != 9223372036854775807) {
        return 0;
    }
    return 1;
}
