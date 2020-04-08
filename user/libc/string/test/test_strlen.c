#include "test_string.h"

int test_strlen(void) {
    char *str = "Hello";
    size_t len = strlen_os(str);
    if (len != 5) {
        return 0;
    }
    return 1;
}
