#include "stdio.h"
#include "../string/string.h"


#define MIN(a,b) ((a)<(b) ? (a) : (b))

size_t fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    
    /* int byteswritten; */
    if (!nmemb || !size) {
        return 0;
    }
    if (stream == stdout) {
        return write(STDOUT_FD, ptr, nmemb);
    }

    if (nmemb > stream->write_end - stream->write_pos) {
        // if there's not enough room in the buffer
        // call writev
        iovec iov[2] = {
            {
                .iov_base = stream->buf,
                .iov_len = stream->write_pos - stream->buf
            },
            {
                .iov_base = (void*)ptr,
                .iov_len = nmemb
            }
        };
        size_t rem = iov[0].iov_len + iov[1].iov_len;
        printf_os("GOING TO CALL READV\n");
        int byteswritten = writev(stream->fd, iov, 2);
        if (byteswritten == rem) {
            /* stream->write_end = stream->buf + BUFSIZ; */
            stream->write_pos = stream->buf;
            return byteswritten;
        }

    }
    memcpy(stream->write_pos, ptr, nmemb);
    /* printf_os("\n\nPRINTING buf FROM fwrite:\n  %s\n\n", stream->buf); */
    stream->write_pos += nmemb;
    return nmemb;
}
