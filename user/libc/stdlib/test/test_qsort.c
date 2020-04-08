#include "../../../../kernel/types.h"
#include "../../../../kernel/stat.h"
#include "../../../user.h"
#include "test_stdlib.h"

int comp(const void *x, const void *y) {
    return *(int*)x - *(int*)y;
}

int test_qsort(void) {
    int arr[] = {69, 16, 24, 3, 5, 0, 19, 1};
    int sorted[] = {0, 1, 3, 5, 16, 19, 24, 69};
    qsort_os(arr, 8, sizeof(int), comp);
    for (int i = 0; i < 8; i++) {
        if (arr[i] != sorted[i]) {
            return 0;
        }
    }
    return 1;

}
