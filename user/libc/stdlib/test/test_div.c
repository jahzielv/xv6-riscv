#include "test_stdlib.h"

int test_div(void) {
    div_t result;
    result = div_os(27, 3);
    if (result.quot != 9 || result.rem != 0) {
        return 0;
    }
    return 1;
}
