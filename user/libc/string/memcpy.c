#include "string.h"

void *memcpy(void *s1, void *s2, size_t n) {
    char *bytes1 = (char*)s1;
    char *bytes2 = (char*)s2;
    for (int i = 0; i < n; i++) {
        *bytes1++ = *bytes2++;
    }
    return s1;
}
