#include "test_stdio.h"

int test_sprintf(void) {
    char *buf = (char*)malloc(23);
    int d = 21;
    int x = 0xDEAD900l;
    char c = 'Z';
    char *s = "This is a sample string";

    int numbytes = sprintf(buf, "SPRINTF TEST: %d %x %c %s\n", d, x, c, s);
    /* printf_os("numbytes sprintf: %d\n", numbytes); */
    if (numbytes != 22) {
        free(buf);
        return 0;
    }
    printf_os("%s", buf);
    free(buf);
    return 1;
}
