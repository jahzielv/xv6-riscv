#include "../kernel/types.h"
#include "../kernel/stat.h"
#include "user.h"
#include "./libc/stdlib/test/test_stdlib.h"
/* #include "./libc/setjmp/test/test_setjmp.h" */
/* #include "./libc/time/test/test_time.h" */
/* #include "./libc/string/test/test_string.h" */
/* #include "./libc/signal/test/test_signal.h" */
/* #include "./libc/errno/test/test_errno.h" */

/**
 * main driver program that runs various test cases for the libc implementation
 * @param argc argument count
 * @param argv argument values
 * @return exits, does not return
 */
/*int main(int argc, char *argv[])*/
/*{*/

/*    printf(1, "\n\n>>> BEGIN TESTING: ERRNO\n");*/
/*    if (test_init_errno())*/
/*    {*/
/*        printf(1, "initiation succeeded\n");*/
/*    }*/
/*    else*/
/*    {*/
/*        printf(2, "ATTENTION NEEDED: ");*/
/*        printf(2, "initiation failed\n");*/
/*    }*/

/*    errno = 1;*/
/*    if (errno == 1)*/
/*    {*/
/*        printf(1, "set errno value succeeded\n");*/
/*    }*/
/*    else*/
/*    {*/
/*        printf(2, "ATTENTION NEEDED: ");*/
/*        printf(2, "set errno value failed\n");*/
/*    }*/

/*    errno = 0;*/

/*    if (test_sys_errno())*/
/*    {*/
/*        printf(1, "kernal errno succeeded\n");*/
/*    }*/
/*    else*/
/*    {*/
/*        printf(2, "ATTENTION NEEDED: ");*/
/*        printf(2, "kernal errno failed\n");*/
/*    }*/
/*    errno = 0;*/

/*    printf(1, "\n\n>>> BEGIN TESTING: STDLIB\n");*/
/*    // abs*/
/*    if (test_abs())*/
/*    {*/
/*        printf(1, "abs succeeded\n");*/
/*    }*/
/*    else*/
/*    {*/
/*        printf(2, "ATTENTION NEEDED: ");*/
/*        printf(2, "abs failed :(\n");*/
/*    }*/

/*    // bsearch*/
/*    if (test_bsearch())*/
/*    {*/
/*        printf(1, "bsearch succeeded\n");*/
/*    }*/
/*    else*/
/*    {*/
/*        printf(2, "ATTENTION NEEDED: ");*/
/*        printf(2, "bsearch failed :(\n");*/
/*    }*/

/*    // atol*/
/*    if (test_atol())*/
/*    {*/
/*        printf(1, "atol succeeded\n");*/
/*    }*/
/*    else*/
/*    {*/
/*        printf(2, "ATTENTION NEEDED: ");*/
/*        printf(2, "atol failed :(\n");*/
/*    }*/

/*    // atoi*/
/*    if (test_atoi())*/
/*    {*/
/*        printf(1, "atoi succeeded\n");*/
/*    }*/
/*    else*/
/*    {*/
/*        printf(2, "ATTENTION NEEDED: ");*/
/*        printf(2, "atoi failed :(\n");*/
/*    }*/

/*    // atoll*/
/*    if (test_atoll())*/
/*    {*/
/*        printf(1, "atoll succeeded\n");*/
/*    }*/
/*    else*/
/*    {*/
/*        printf(2, "ATTENTION NEEDED: ");*/
/*        printf(2, "atoll failed :(\n");*/
/*    }*/

/*    // div*/
/*    if (test_div())*/
/*    {*/
/*        printf(1, "div succeeded\n");*/
/*    }*/
/*    else*/
/*    {*/
/*        printf(2, "ATTENTION NEEDED: ");*/
/*        printf(2, "div failed\n");*/
/*    }*/

/*    // labs*/
/*    if (test_labs())*/
/*    {*/
/*        printf(1, "labs succeeded\n");*/
/*    }*/
/*    else*/
/*    {*/
/*        printf(2, "ATTENTION NEEDED: ");*/
/*        printf(2, "labs failed :(\n");*/
/*    }*/

/*    // ldiv*/
/*    if (test_ldiv())*/
/*    {*/
/*        printf(1, "ldiv succeeded\n");*/
/*    }*/
/*    else*/
/*    {*/
/*        printf(2, "ATTENTION NEEDED: ");*/
/*        printf(2, "ldiv failed :(\n");*/
/*    }*/

/*    // qsort*/
/*    if (test_qsort())*/
/*    {*/
/*        printf(1, "qsort succeeded\n");*/
/*    }*/
/*    else*/
/*    {*/
/*        printf(2, "ATTENTION NEEDED: ");*/
/*        printf(2, "qsort failed :(\n");*/
/*    }*/
    


/*    printf(1, "\n\n>>> BEGIN TESTING: TIME\n");*/
/*    // time*/
/*    if (test_time())*/
/*    {*/
/*        printf(1, "clock succeeded\n");*/
/*    }*/
/*    else*/
/*    {*/
/*        printf(2, "ATTENTION NEEDED: ");*/
/*        printf(2, "FAILED CLOCK\n");*/
/*    }*/

/*    // difftime*/
/*    if (test_difftime())*/
/*    {*/
/*        printf(1, "difftime succeeded\n");*/
/*    }*/
/*    else*/
/*    {*/
/*        printf(2, "ATTENTION NEEDED: ");*/
/*        printf(2, "FAILED DIFFTIME\n");*/
/*    }*/

/*    // mktime*/
/*    if (test_mktime())*/
/*    {*/
/*        printf(1, "mktime succeeded\n");*/
/*    }*/
/*    else*/
/*    {*/
/*        printf(2, "ATTENTION NEEDED: ");*/
/*        printf(2, "FAILED MKTIME\n");*/
/*    }*/

/*    // asctime*/
/*    if (test_asctime())*/
/*    {*/
/*        printf(1, "asctime succeeded\n");*/
/*    }*/
/*    else*/
/*    {*/
/*        printf(2, "ATTENTION NEEDED: ");*/
/*        printf(1, "FAILED ASCTIME\n");*/
/*    }*/

/*    printf(1, "\n\n>>> BEGIN TESTING: SETJMP\n");*/    
/*    // setjmp*/
/*    test_setjmp();*/

/*    printf(1, "\n\n>>> BEGIN TESTING: STRING\n");*/
/*    // strchr*/
/*    if (test_strchr())*/
/*    {*/
/*        printf(1, "strchr succeeded\n");*/
/*    }*/
/*    else*/
/*    {*/
/*        printf(2, "ATTENTION NEEDED: ");*/
/*        printf(2, "strchr failed :(\n");*/
/*    }*/

/*    printf(1, "\n\n>>> BEGIN TESTING: SIGNAL\n");*/
/*    // signal handler*/
/*    if (test_signal_handler())*/
/*    {*/
/*        printf(1, "signal handler succeeded\n");*/
/*    }*/
/*    else*/
/*    {*/
/*        printf(2, "ATTENTION NEEDED: ");*/
/*        printf(1, "signal handler failed\n");*/
/*    }*/
    
/*    // sig_atomic_t*/
/*    printf(1, "Note: testing signal sig_atomic_t can only be run within 1 CPU.\n");*/
/*    printf(1, "Please press control + c 10 times.\n");*/
/*    if (test_sig_atomic_t())*/
/*    {*/
/*        printf(1, "signal sig_atomic_t succeeded\n");*/
/*    }*/
/*    else*/
/*    {*/
/*        printf(2, "ATTENTION NEEDED: ");*/
/*        printf(1, "signal sig_atomic_t failed\n");*/
/*    }*/
    
/*    // test_signal_IGN*/
/*    printf(1, "\nNote: Please wait a few seconds while sleep is in progress.\n");*/
/*    printf(1, "Manual checking: correct output: PID: x RECEIVED SIGTERM\n");*/
/*    test_signal_IGN();*/

/*    // sig_DFL*/
/*    if (test_signal_DFL())*/
/*    {*/
/*        printf(1, "signal SIG_DFL succeeded\n");*/
/*    }*/
/*    else*/
/*    {*/
/*        printf(2, "ATTENTION NEEDED: ");*/
/*        printf(1, "signal SIG_DFL failed\n");*/
/*    }*/
    
/*    // signal kill2*/
/*    printf(1, "Manual checking: correct output: PID: x RECEIVED SIGTERM\n");*/
/*    test_kill2();*/
    

/*    printf(1, "\n\n>>> TESTING: DONE\n");*/
/*    printf(1, "run command 'exit' to exit qemu simulator\n");*/

/*    exit();*/
/*}*/

int main (int argc, char *argv[]) {
   printf("\n\n>>> BEGIN TESTING: STDLIB\n");
   // abs
   if (test_abs())
   {
       printf("abs succeeded\n");
   }
   else
   {
       printf("ATTENTION NEEDED: ");
       printf("abs failed :(\n");
   }

   // bsearch
   if (test_bsearch())
   {
       printf("bsearch succeeded\n");
   }
   else
   {
       printf("ATTENTION NEEDED: ");
       printf("bsearch failed :(\n");
   }

   // atol
   if (test_atol())
   {
       printf("atol succeeded\n");
   }
   else
   {
       printf("ATTENTION NEEDED: ");
       printf("atol failed :(\n");
   }

   // atoi
   if (test_atoi())
   {
       printf("atoi succeeded\n");
   }
   else
   {
       printf("ATTENTION NEEDED: ");
       printf("atoi failed :(\n");
   }

   // atoll
   if (test_atoll())
   {
       printf("atoll succeeded\n");
   }
   else
   {
       printf("ATTENTION NEEDED: ");
       printf("atoll failed :(\n");
   }

   // div
   if (test_div())
   {
       printf("div succeeded\n");
   }
   else
   {
       printf("ATTENTION NEEDED: ");
       printf("div failed\n");
   }

   // labs
   if (test_labs())
   {
       printf("labs succeeded\n");
   }
   else
   {
       printf("ATTENTION NEEDED: ");
       printf("labs failed :(\n");
   }

   // ldiv
   if (test_ldiv())
   {
       printf("ldiv succeeded\n");
   }
   else
   {
       printf("ATTENTION NEEDED: ");
       printf("ldiv failed :(\n");
   }

   // qsort
   if (test_qsort())
   {
       printf("qsort succeeded\n");
   }
   else
   {
       printf("ATTENTION NEEDED: ");
       printf("qsort failed :(\n");
   }
    


    exit(0);
}
