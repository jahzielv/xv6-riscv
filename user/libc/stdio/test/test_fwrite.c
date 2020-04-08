#include "test_stdio.h"

int test_fwrite(void) {
    FILE *myfile = fopen("test", "w");
    char *str = "These are the times that try men's souls.\n\0";
    int bytes = fwrite(str, sizeof(char), 42, myfile);
    if (bytes != 42) {
        fclose(myfile);
        return 0;
    }
    fclose(myfile); // this flushes buffer to file
    FILE *readfile = fopen("test", "r");
    char *buf = (char*)malloc(42);
    fread(buf, sizeof(char), 42, readfile);
    // printf will print junk because at this point
    // buf isn't a C string - it's not null terminated!
    // It's just raw bytes from the file, so printf will
    // keep printing until it finds \0
    write(1, buf, 42);
    fclose(readfile);
    free(buf);
    return 1;
}
