#include "test_stdio.h"

int test_tmpfile(void) {
    FILE *tmp = tmpfile();
    fprintf(tmp, "This string is in a temp file\n");
    char *buf = (char*)malloc(30);
    int read = fread(buf, sizeof(char), 30, tmp);
    printf_os("bytes read in %s: %d\n", __FILE__, read);
    printf_os(buf);
    fclose(tmp);
    /* write(1, buf, 30); */
    return 1;
}
