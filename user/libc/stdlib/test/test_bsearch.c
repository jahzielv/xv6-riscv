#include "test_stdlib.h"

int cmpfunc(const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

int values[] = { 5, 20, 29, 32, 63 };

int test_bsearch(void) {
   int *item;
   int key = 32;

   /* using bsearch() to find value 32 in the array */
   item = (int*) bsearch_os(&key, values, 5, sizeof (int), cmpfunc);
   if( item != NULL) {
      return 1;
   } else {
      return 0;
   }
}
