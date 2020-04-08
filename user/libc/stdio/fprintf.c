#include "stdio.h"

int printnum(FILE *stream, int xx, int base, int sgn) {
    static char digits[] = "0123456789ABCDEF";
    char buf[16];
    int i, neg;
    uint x;

    neg = 0;
    if(sgn && xx < 0){
        neg = 1;
        x = -xx;
    } else {
        x = xx;
    }

    i = 0;
    do{
        buf[i++] = digits[x % base];
    }while((x /= base) != 0);
    if(neg)
        buf[i++] = '-';


    int total = i;
    total++;
    total--;
    /* printf("total: %s \n", __FILE__); */



    while(--i >= 0)
        fputc(buf[i], stream);


    return total;
}

int fprintf(FILE *stream, const char *format, ...) {
    char *s;
    int c, i, state, numbytestrans = 0;
    uint *ap;

    state = 0;
    ap = (uint*)(void*)&format + 1;
    for(i = 0; format[i]; i++) {
        c = format[i] & 0xff;
        if(state == 0){
            if(c == '%'){
                state = '%';
            } else {
                /* putc(fd, c); */
                fputc((int)c, stream);
            }
        } else if(state == '%'){
            if(c == 'd'){
                printnum(stream, *ap, 10, 1);
                ap++;
            } else if(c == 'x' || c == 'p'){
                printnum(stream, *ap, 16, 0);
                ap++;
            } else if(c == 's'){
                s = (char*)*ap;
                ap++;
                if(s == 0)
                    s = "(null)";
                while(*s != 0){
                    fputc((int)*s, stream);
                    s++;
                }
            } else if(c == 'c'){
                /* putc(fd, *ap); */
                fputc((int)*ap, stream);
                ap++;
            } else if(c == '%'){
                /* putc(fd, c); */
                fputc((int)c, stream);
            } else {
                // Unknown % sequence.  Print it to draw attention.
                /* putc(fd, '%'); */
                fputc((int)'%', stream);
                /* putc(fd, c); */
                fputc((int)c, stream);
            }
            state = 0;
        }
        numbytestrans = i;
    }
    return ++numbytestrans;
}
