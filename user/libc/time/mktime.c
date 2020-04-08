#include "../../types.h"
#include "../../stat.h"
#include "../../user.h"
#include "time.h"

/** 
 * given the user specified date in timeptr
 * mktime will return the week of the day
 * 
 * @param timeptr, struct tm which gives a date
 * @return 1 for success, -1 to indicate invalid pointer argument
 */
time_t mktime(struct tm *timeptr) {
    if (timeptr == NULL) {
        return -1;
    }
    else {
        timeptr->tm_wday = timeptr->tm_mday + ((13*(timeptr->tm_mon-2)) / 5) + timeptr->tm_year - 2000 + 
            ((timeptr->tm_year - 2000)/4) + (20/4) - (2*20);
        timeptr->tm_wday = timeptr->tm_wday % 7 - 1;
        // fix Saturday edge
        if (timeptr->tm_wday == -1) {
            timeptr->tm_wday = 6;
        }
        return 1;
    }
}

