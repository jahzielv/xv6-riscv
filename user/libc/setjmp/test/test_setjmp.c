#include "test_setjmp.h"

#include "../../../types.h"
#include "../../../stat.h"
#include "../../../user.h"
jmp_buf buf;
int test_setjmp(void) {
  switch (setjmp(buf)) {
    case 0:
      printf(1,"I just set jump\n");
      longjmp(buf, 42);
      break;
    case 42:
      printf(1, "Returned from longjmp\n");
      break;
    default:
      printf(2, "We shouldn't get here!\n");
  }

  return 0;
}
