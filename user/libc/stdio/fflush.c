#include "stdio.h"

int fflush(FILE *stream) {
    size_t buflen = stream->write_pos - stream->buf;
    if (buflen) {
        int byteswritten = write(stream->fd, stream->buf, buflen);
        if (byteswritten <= 0) {
            return -1;
        }
    }
    return 0;
}
