#include "test_stdio.h"

int test_fprintf(void) {
    FILE *test = fopen("fprintftest", "w");
    int d = 10;
    int x = 0xdeadbeef;
    char c = 'Q';
    char *s = "This is a sample string\0";

    fprintf(test, "FPRINTF TEST: %d %x %c %s\n", d, x, c, s);
    /* printf(1, "num bytes = %d\n", bw); */
    fclose(test);
    FILE *read = fopen("fprintftest", "r");
    char *buf = (char*)malloc(52);
    fread(buf, sizeof(char), 52, read);
    /* fwrite(buf, sizeof(char), 64, stdout); */
    write(STDOUT_FD, buf, 52);
    fclose(test);
    free(buf);
    return 1;
}
