#include "test_stdio.h"

int test_fopen(void) {
    FILE *myf = fopen("README", "r");
    if (!myf) {
        return 0;
    }
    if (myf->fd != 3 || myf->flags != 0) {
        return 0;
    }
    fclose(myf);
    return 1;
}
