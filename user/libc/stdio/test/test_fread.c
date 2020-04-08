#include "test_stdio.h"

int test_fread(void) {
    FILE *myf = fopen("README", "r");
    /* printf(1, "flags = %d\n", myf->flags); */
    char *buf = (char*)malloc(24);
    int read = fread(buf, sizeof(char), 24, myf);
    /* printf(1, "read = %d\n", read); */
    if (read != 24) {
        free(buf);
        fclose(myf);
        return 0;
    }
    printf(1, "%s\n", buf);
    free(buf);
    fclose(myf);
    return 1;
}

// need to test different modes
// a/a+ should start at the end
// so reads from a+ should technically
// return nothing, since it's setting
// the cursor at the end of the file.
