#include "../../../types.h"
#include "../../../stat.h"
#include "../../../user.h"
#include "test_time.h"

/**
 * tests time, which finds the current time in seconds
 * 
 * @return 1 on success
 */
int test_time(void) {
    time_t timer;
    time_t sec = time(&timer);
    if (sec == -1) {
        return 0;
    } else {
        printf(1, "In seconds, the current time is %d.\n", timer);
        return 1;    
    }
    exit();
}
