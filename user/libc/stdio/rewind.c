#include "stdio.h"

void rewind(FILE *stream) {
   stream->currpos = 0;
}
