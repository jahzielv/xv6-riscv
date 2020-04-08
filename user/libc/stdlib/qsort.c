#include "stdlib.h"

void swap(void *a, void *b, size_t size) {
    char *a_bytes = (char*)a;
    char *b_bytes = (char*)b;
    char temp;
    for (int i = 0; i < size; i++) {
        temp = *a_bytes;
        *a_bytes = *b_bytes;
        *b_bytes = temp;
        a_bytes++;
        b_bytes++;
    }
}

void bubbleSort(void *base, int n, size_t size, int (*compar)(const void *, const void *)) 
{ 
   int i, j; 
   for (i = 0; i < n-1; i++) {
  
       // Last i elements are already in place    
       for (j = 0; j < n-i-1; j++) {
           if (compar( ((char*)base + (j * size)), ((char*)base + (size * (j + 1))) ) > 0) {
              swap( ((char*)base + (j * size)), ((char*)base + (size * (j + 1))) , size); 
            }

       }
   } 
}

void qsort_os(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *)) {
    bubbleSort(base, nmemb, size, compar);
}
