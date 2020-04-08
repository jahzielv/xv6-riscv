#include "stdio.h"
#include "../stdarg/stdarg.h"

int vprintf(char *format, va_list arg) {
    return vfprintf(stdout, format, arg);
}
