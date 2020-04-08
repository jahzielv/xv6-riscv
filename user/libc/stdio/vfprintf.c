#include "stdio.h"
#include "../stdarg/stdarg.h"

int vfprintf(FILE *stream, char *format, va_list arg) {
    char *s;
    int c, i, state, numbytestrans = 0;

    state = 0;
    for (i = 0; format[i]; i++) {
        c = format[i] & 0xff;
        if(state == 0){
            if(c == '%'){
                state = '%';
            } else {
                fputc((int)c, stream);
            }
        } else if(state == '%'){
            if(c == 'd'){
                printnum(stream, va_arg(arg, int), 10, 1);
            } else if(c == 'x' || c == 'p'){
                printnum(stream, va_arg(arg, int), 16, 0);
            } else if(c == 's'){
                s = va_arg(arg, char *);
                if(s == 0)
                    s = "(null)";
                while(*s != 0){
                    fputc((int)*s, stream);
                    s++;
                }
            } else if(c == 'c'){
                fputc(va_arg(arg, int), stream);
            } else if(c == '%'){
                fputc((int)c, stream);
            } else {
                // Unknown % sequence.
                fputc((int)'%', stream);
                fputc((int)c, stream);
            }
            state = 0;
        }
        numbytestrans = i;
    }
    return ++numbytestrans;

}
