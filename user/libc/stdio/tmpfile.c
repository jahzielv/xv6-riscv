#include "stdio.h"

FILE *tmpfile(void) {
    char *randname = "randstr";
    FILE *tmp = fopen(randname, "w+");
    unlink(randname);
    return tmp;
}
