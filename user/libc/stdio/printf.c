#include "stdio.h"
#include "../stdarg/stdarg.h"

int printf_os(char *format, ...) {
    int ret;
    va_list list;
    va_start(list, format);
    ret = vfprintf(stdout, format, list);
    va_end(list);
    return ret;
}
