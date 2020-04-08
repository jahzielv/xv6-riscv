#include "../../../types.h"
#include "../../../stat.h"
#include "../../../user.h"
#include "test_time.h"

/**
 * tests the standarization of date formatting
 * prints out regular and standardized formats
 * of the current time and date
 * 
 * @return 1 on success
 */
int test_asctime(void) {
    struct tm r0;
    if (date(&r0)) {
        printf(1, "Now, the current time in regular format is %d/%d/%d %d:%d:%d\n", r0.tm_year, r0.tm_mon, r0.tm_mday, r0.tm_hour, r0.tm_min, r0.tm_sec);
    } else {
        return -1;
    }    

    mktime(&r0);
    char* time = asctime(&r0);
    printf(1, "%s", time);
    
    return 1;
    exit();
}
