#include "../../../types.h"
#include "../../../stat.h"
#include "../../../user.h"
#include "test_time.h"

/**
 * takes two timestamps and tests difftime
 * to find the delta between the two timestamps
 * 
 * @return 1 on success
 */
int test_difftime(void) {

    struct tm r0, r1;
    date(&r0);
    printf(1, "The current time, our first timestamp, is %d/%d/%d %d:%d:%d\n", r0.tm_year, r0.tm_mon, r0.tm_mday, r0.tm_hour, r0.tm_min, r0.tm_sec);
    printf(1, "Note: letting time pass");

    for (int i = 0; i < 2300; i++)
    {
        for (int i = 0; i < 50; i++) {
            if (i%10 == 0) {
                printf(1, ".");
            }
        }  
    }
    printf(1, "\n");
    date(&r1);
    printf(1, "Now, our second timestamp is %d/%d/%d %d:%d:%d\n", r1.tm_year, r1.tm_mon, r1.tm_mday, r1.tm_hour, r1.tm_min, r1.tm_sec);

    // convert timestamps to standard compliant time_t type
    time_t time1, time0;
    time1 = r1.tm_hour*86400+r1.tm_min*60 + r1.tm_sec;
    time0 = r0.tm_hour*86400+r0.tm_min*60 + r0.tm_sec;
    time_t diff = difftime(time0, time1);
    if (diff == -1) {
        return 0;
    }
    printf(1, "The difference in these timestamps is %d second(s).\n", diff);

    return 1;
}
