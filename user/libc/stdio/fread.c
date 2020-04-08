#include "stdio.h"
#include "../string/string.h"
#include "../../user.h"
// int read(int, void*, int);

/*
Description
The fread function reads, into the array pointed to by ptr , up to nmemb members whose size is specified by size , from the stream pointed to by stream . The file position indicator for the stream (if defined) is advanced by the number of characters successfully read. If an error occurs, the resulting value of the file position indicator for the stream is indeterminate. If a partial member is read, its value is indeterminate.

Returns
The fread function returns the number of members successfully read, which may be less than nmemb if a read error or end-of-file is encountered. If size or nmemb is zero, fread returns zero and the contents of the array and the state of the stream remain unchanged.
 
 */
#define MIN(a,b) ((a)<(b) ? (a) : (b))

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream) {
    if (!nmemb || !size) {
        return 0;
    }
    unsigned char *currdest = ptr;
    size_t stream_length = size*nmemb;
    size_t bytes_left_to_read = stream_length;
    size_t val;
    /* int bytesread; */
    /* printf_os("CURRENT POS IN FREAD: %d\n", stream->read_pos); */

    if (stream->read_pos != stream->read_end) {
    val = MIN(stream->read_end - stream->read_pos,bytes_left_to_read);
        memcpy(currdest, stream->read_pos, val);
        stream->read_pos += val;
        currdest += val;
        bytes_left_to_read -= val;
    }

    // now read_pos == read_end
    iovec iov[2] = {
        {.iov_base = currdest, .iov_len = bytes_left_to_read},
        {.iov_base = stream->buf, .iov_len = BUFSIZ}
    };
    int totalbytes = readv(stream->fd, iov, 2); // fill up buffer
    if (totalbytes <= 0) {
        printf_os("totalbytes was %d\n", totalbytes);
    }
    int newbufsize = bytes_left_to_read - totalbytes;
    stream->read_end = stream->buf + newbufsize;
    stream->read_pos = stream->buf;

            

    /* bytesread = read(stream->fd, currdest, bytes_left_to_read); */
    
    /* return bytesread; */
    return nmemb;
}
