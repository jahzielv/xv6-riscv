#include "string.h"

char *strchr_os(char *s, int c) {
    char *curr = s;
    while (*curr != '\0') {
        if (*curr == (char)c) {
            return curr;
        }
        curr++;
    }
    return 0;
}
