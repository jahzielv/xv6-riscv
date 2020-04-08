#include "test_stdio.h"

int test_fseek(void) {
    FILE *f = fopen("fseekfile", "a+");
    printf_os("fseekfile fd: %d\n", f->fd);
    fprintf(f, "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\n"); // 53 bytes (string + \n)
//          abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\n
//                                                               ^
//                                                               |
//                                              f->off is now here.
//                                              if we read without
//                                              fseeking, we'll run
//                                              out of bounds and get junk.

    if (fseek(f, 10, SEEK_SET) < 0) {
        printf_os("big rip\n");
    }

//          abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\n
//                   ^^
//                   ||_________
//  f->off is now here          |
//                              |
//  Reading should now start here 

    char *buf1 = (char*)malloc(10);
    fread(buf1, sizeof(char), 10, f);
    int ret;
    if (*buf1 != 'k' /*next character*/) {
        ret = 0;
        printf_os("bad fseek: %s\n", buf1);
    } else {
        ret = 1;
        printf_os("next 10 bytes of fseekfile: %s\n", buf1);
    }


    free(buf1);
    fclose(f);
    return ret;

}
