#include "string.h"

size_t strlen_os(char *s)
{
  int n;

  for(n = 0; s[n]; n++)
    ;
  return n;
}
