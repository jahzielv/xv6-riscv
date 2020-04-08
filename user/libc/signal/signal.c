#include "../../types.h"
#include "../../user.h"
#include "signal.h"
#include "../errno/errno.h"

void (*signal(int sig, void (*func)(int)))(int) {
  int ret = (int)signal_os(sig, func);
  if (ret == -1) {
     errno = errno_os();
  }
  return (void(*)(int))ret;
}

int raise(int sig){
  return raise_os(sig);
}
