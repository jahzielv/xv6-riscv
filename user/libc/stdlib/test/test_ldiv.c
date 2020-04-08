#include "test_stdlib.h"

int test_ldiv(void) {
    ldiv_t result;
    result = ldiv_os(27, 3);
    if (result.quot != 9 || result.rem != 0) {
        return 0;
    }
    return 1;
}
