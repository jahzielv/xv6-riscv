#include "../../../types.h"
#include "../../../stat.h"
#include "../../../user.h"
#include "test_time.h"

/**
 * tests mktime, which finds the day of the week,
 * using three test cases: Dec 5, 7, 8th.
 * Any testcase from the century 2000+ will work.
 * 
 * @return 1 on success
 */
int test_mktime(void) {

    static const char *const wday[] = {
        "Sunday", "Monday", "Tuesday", "Wednesday",
        "Thursday", "Friday", "Saturday", "-unknown-"};
    struct tm time_str;
    time_str.tm_year = 2019;
    time_str.tm_mon = 12;
    time_str.tm_mday = 5;
    time_str.tm_hour = 0;
    time_str.tm_min = 0;
    time_str.tm_sec = 1;
    time_str.tm_isdst = -1;
    time_t time = mktime(&time_str);
    if (time == -1) {
        time_str.tm_wday = 7;
        printf(1, "The corresponding day of the week is %s.\n", wday[time_str.tm_wday]);
        return 0;
    } else {
        printf(1, "For the date Dec 5, 2019, the corresponding day of the week is %s.\n", wday[time_str.tm_wday]);
    }    
       
    struct tm time_str7;
    time_str7.tm_year = 2019;
    time_str7.tm_mon = 12;
    time_str7.tm_mday = 7;
    time_str7.tm_hour = 0;
    time_str7.tm_min = 0;
    time_str7.tm_sec = 1;
    time_str7.tm_isdst = -1;
    time_t time7 = mktime(&time_str7);
    if (time7 == -1) {
        time_str7.tm_wday = 7;
        printf(1, "The corresponding day of the week is %s.\n", wday[time_str7.tm_wday]);
        return 0;
    } else {
        printf(1, "For the date Dec 7, 2019, the corresponding day of the week is %s.\n", wday[time_str7.tm_wday]);
    }  

    struct tm time_str8;
    time_str8.tm_year = 2019;
    time_str8.tm_mon = 12;
    time_str8.tm_mday = 8;
    time_str8.tm_hour = 0;
    time_str8.tm_min = 0;
    time_str8.tm_sec = 1;
    time_str8.tm_isdst = -1;
    time_t time8 = mktime(&time_str8);
    if (time8 == -1) {
        time_str.tm_wday = 7;
        printf(1, "The corresponding day of the week is %s.\n", wday[time_str8.tm_wday]);
        return 0;
    } else {
        printf(1, "For the date Dec 8, 2019, the corresponding day of the week is %s.\n", wday[time_str8.tm_wday]);
    }  
    
    return 1;
}
