#include "stdio.h"
#include "../string/string.h"

int fputs(char *str, FILE *stream) {
    if (stream == stdout) {
        size_t strsize = strlen_os(str);
        write(STDIN_FD, str, strsize);
    } else {
        size_t strsize = strlen_os(str);
        write(stream->fd, str, strsize);
    }
    return 0;
}
