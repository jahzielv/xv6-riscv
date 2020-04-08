#include "test_stdio.h"

int test_fputc(void) {
    char out = 'q';
    fputc((int)out, stdout);
    return 1;
}
