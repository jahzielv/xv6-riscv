#include "test_stdio.h"

int test_fclose(void) {
    FILE *f1;
    FILE *f2;
    f1 = fopen("README", "r");
    int fd1 = f1->fd;
    fclose(f1);
    f2 = fopen("README", "r");
    int fd2 = f2->fd;
    if (fd1 != fd2) {
        return 0;
    }
    return 1;

}
