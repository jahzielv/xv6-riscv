#include "stdio.h"

int fputc(int c, FILE *stream) {
    char character = (char)c;
    if (stream == stdout) {
        write(1, &character, 1);
    } else {
        write(stream->fd, &character, 1);
    }
    return c;
}
