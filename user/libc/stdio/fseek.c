#include "stdio.h"

int fseek(FILE *stream, int offset, int whence) {
    int newoff = lseek(stream->fd, offset, whence);
    if (stream->read_pos != stream->read_end) {
        stream->read_pos = (unsigned char*)newoff;
    }
    return newoff;
}
