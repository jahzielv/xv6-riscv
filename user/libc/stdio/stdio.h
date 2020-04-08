#include "../../types.h"
#include "../../user.h"
#include "../../fcntl.h"
#include "../stddef/stddef.h"
#include "../stdarg/stdarg.h"

typedef struct IO_FILE {
    int fd;
    int flags;
    size_t buf_size;
    unsigned char *buf; // the FILE's buffer
    unsigned char *write_pos;
    unsigned char *read_pos;
    unsigned char *write_end;
    unsigned char *read_end;
} FILE;

FILE *stdin; 
FILE *stdout;
FILE *stderr;

// standard stream fd numbers
#define STDIN_FD 0
#define STDOUT_FD 1
#define STDERR_FD 2

// constants for use in fseek
#define SEEK_SET 1
#define SEEK_CUR 2
#define SEEK_END 3

// general constants
#define EOF -1
#define BUFSIZ 1024


// functions
int fprintf(FILE *stream, const char *format, ...);
FILE *fopen(char *filename, char *mode);
size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream);
int fclose(FILE *stream);
size_t fwrite(void *ptr, size_t size, size_t nmemb, FILE *stream);
int fprintf(FILE *stream, const char *format, ...);
int fputc(int c, FILE *stream);
int printf_os(char *format, ...);
int vfprintf(FILE *stream, char *format, va_list arg);
int printnum(FILE *stream, int xx, int base, int sgn);
int vsprintf(char *s, char *format, va_list arg);
int sprintf(char *s, char *format, ...);
int fputs(char *str, FILE *stream);
int vprintf(char *format, va_list arg);
FILE *tmpfile(void);
void rewind(FILE *stream);
int fseek(FILE *stream, int offset, int whence);
FILE *fileinit(int, char*);
int fflush(FILE *);
