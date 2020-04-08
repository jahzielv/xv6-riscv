#include "test_errno.h"

#include "../../signal/signal.h"

/**
 * test the initial errno value, should be 0
 * @return 1 if success, 0 if failed
 */
int test_init_errno() {
  if (errno != 0) {
    return 0;
  }
  return 1;
}

/**
 * try to set a kernel space handler
 * errno should be EILGHDL
 * @return 1 if success, 0 if failed
 */
int test_sys_errno() {
  //set up the signal handler for some
  if (((int)signal(SIGINT, (void(*)(int))0x80000000)) < 0) {
    if (errno == EILGHDLR) {
      return 1;
    }
  }
  return 0;
}