#include "stdio.h"
#include "../string/string.h"
#include "../../user.h"


/*
 * r: read only
 * w: overwrite/create and write only
 * a: write only, appending to end
 * r+: read and write to existing file
 * w+: basically like w??
 * a+: open or create file, writing to end of file
 */
int modeflags(char *mode)
{
	int flags;
    if (strchr_os(mode, '+')) {
         flags = O_RDWR;
         if (*mode == 'a' || *mode == 'w') {
             flags |= O_CREATE;
         }
         // handle r+ case
    } else if (*mode == 'r') {
         flags = O_RDONLY;
    } else if (*mode == 'w') {
        flags = O_WRONLY;
    }
	/* if (strchr_os(mode, 'x')) flags |= O_EXCL; */
	/* if (strchr_os(mode, 'e')) flags |= O_CLOEXEC; */
    if (*mode != 'r') {
        flags |= O_CREATE;
    } 
	/* if (*mode == 'w') flags |= O_TRUNC; */
	/* if (*mode == 'a') flags |= O_APPEND; */
	return flags;
}

FILE *fileinit(int fd, char *mode)
{
	FILE *f;
	/* struct winsize wsz; */

	/* /1* Check for valid initial mode character *1/ */
	/* if (!strchr("rwa", *mode)) { */
	/* 	errno = EINVAL; */
	/* 	return 0; */
	/* } */

	/* Allocate FILE+buffer or fail */
	/* if (!(f=malloc(sizeof *f + UNGET + BUFSIZ))) return 0; */
	if (!(f=malloc(sizeof(FILE) + BUFSIZ))) return 0;

	/* Zero-fill only the struct, not the buffer */
	memset(f, 0, sizeof *f);

	/* Impose mode restrictions */
	/* if (!strchr(mode, '+')) f->flags = (*mode == 'r') ? F_NOWR : F_NORD; */
    f->flags = modeflags(mode);

	f->fd = fd;
	f->buf = malloc(BUFSIZ);
    f->read_pos = f->buf;
    f->write_pos = f->buf;
    f->read_end = f->buf;
    f->write_end = f->buf + BUFSIZ; 
	/* f->buf_size = BUFSIZ; */

	/* Activate line buffered mode for terminals */
	/* f->lbf = EOF; */
	/* if (!(f->flags & F_NOWR) && !__syscall(SYS_ioctl, fd, TIOCGWINSZ, &wsz)) */
		/* f->lbf = '\n'; */

	/* Initialize op ptrs. No problem if some are unneeded. */
	/* f->read = __stdio_read; */
	/* f->write = __stdio_write; */
	/* f->seek = __stdio_seek; */
	/* f->close = __stdio_close; */

	/* if (!libc.threaded) f->lock = -1; */

	/* Add new FILE to open file list */
	/* return __ofl_add(f); */
        return f;
}



FILE *fopen(char *filename, char *mode) {
    /* FILE *newfile = (FILE*)malloc(sizeof(FILE)); */
    /* newfile->fd = open(filename, O_RDONLY); */
    /* return newfile; */

	FILE *f;
	int fd;
	int flags;

	/* Check for valid initial mode character */
	/* if (!strchr("rwa", *mode)) { */
	/* 	errno = EINVAL; */
	/* 	return 0; */
	/* } */

	/* Compute the flags to pass to open() */
	flags = modeflags(mode);

	fd = open(filename, flags);
	if (fd < 0) return 0;
	/* if (flags & O_CLOEXEC) */
	/* 	__syscall(SYS_fcntl, fd, F_SETFD, FD_CLOEXEC); */

	f = fileinit(fd, mode);
	if (f) return f;

	/* __syscall(SYS_close, fd); */
    close(fd);
	return 0;
}


