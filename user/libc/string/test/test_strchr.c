#include "test_string.h"
int test_strchr(void) {
    char *string = "Hello";
    char target = 'l';
    if (strchr_os(string, (int)target) == (string + 2)) {
        return 1;
    }
    return 0;
}
