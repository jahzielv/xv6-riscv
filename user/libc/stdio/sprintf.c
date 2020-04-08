#include "stdio.h"

int sprintf(char *s, char *format, ...) {
    int ret;
    va_list list;
    va_start(list, format);
    ret = vsprintf(s, format, list);
    va_end(list);
    return ret;
}
