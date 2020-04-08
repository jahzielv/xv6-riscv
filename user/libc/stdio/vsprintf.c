#include "stdio.h"
#include "../stdarg/stdarg.h"

int vsprintf(char *s, char *format, va_list arg) {
    char *s_curr;
    int pipearr[2];
    pipe(pipearr);
    /* FILE pipein  = { */
    /*     pipearr[1], O_RDONLY */
    /* }; */
    /* FILE pipeout = { */
    /*     pipearr[0], O_WRONLY */
    /* }; */
    FILE *pipein = fileinit(pipearr[1], "r");
    FILE *pipeout = fileinit(pipearr[0], "w");
    int c, i, state, numbytestrans = 0;

    state = 0;
    for (i = 0; format[i]; i++) {
        c = format[i] & 0xff;
        if(state == 0){
            if(c == '%'){
                state = '%';
            } else {
                fputc((int)c, pipein);
                numbytestrans++;
            }
        } else if(state == '%'){
            if(c == 'd'){
                numbytestrans += printnum(pipein, va_arg(arg, int), 10, 1);
            } else if(c == 'x' || c == 'p'){
                numbytestrans += printnum(pipein, va_arg(arg, int), 16, 0);
            } else if(c == 's'){
                s_curr = va_arg(arg, char *);
                if(s_curr == 0)
                    s_curr = "(null)";
                while(*s_curr != 0){
                    fputc((int)*s_curr, pipein);
                    s_curr++;
                    numbytestrans++;
                }
            } else if(c == 'c'){
                fputc(va_arg(arg, int), pipein);
                numbytestrans++;
            } else if(c == '%'){
                fputc((int)c, pipein);
                numbytestrans++;
            } else {
                // Unknown % sequence.
                fputc((int)'%', pipein);
                numbytestrans++;
                fputc((int)c, pipein);
                numbytestrans++;
            }
            state = 0;
        }
    }
    int k = read(pipeout->fd, s, numbytestrans);
    if (k < 0) {
        return -1;
    }
    return numbytestrans;
}
