#include "stdio.h"
#include "../../user.h"

int fclose(FILE *stream) {
    int fl = fflush(stream);
    if (fl < 0) {
        return -1;
    }
    int cls = close(stream->fd);
    if (cls < 0) {
        return -1;
    }
    free(stream->buf);
    free(stream);
    return 0;
}
