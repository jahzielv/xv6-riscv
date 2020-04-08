#include "errno.h"

int errnoval = 0;

int *geterrno() {
  return &errnoval;
}

void seterrno() {
  errnoval = errno_os();
}
