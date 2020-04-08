#define NULL (void*)0
#define CLK_TCK NULL // number per second of the value returned by the clock function

typedef unsigned int size_t;
typedef unsigned int uint;
typedef size_t clock_t;
typedef size_t time_t; // arithmetic types capable of representing times

struct tm {
    int tm_sec;   /*  seconds after the minute --- [0, 60] */
    int tm_min;   /*  minutes after the hour --- [0, 59] */
    int tm_hour;  /*  hours since midnight --- [0, 23] */
    int tm_mday;  /*  day of the month --- [1, 31] */
    int tm_mon;   /*  months since January --- [0, 11] */
    int tm_year;  /*  years since 1900 */
    int tm_wday;  /*  days since Sunday --- [0, 6] */
    int tm_yday;  /*  days since January 1 --- [0, 365] */
    int tm_isdst; /*  Daylight Saving Time flag */
    // value of tm_isdst is positive if Daylight Saving Time is in effect, zero if Daylight Saving Time is not in effect, and negative if the information is not available
};


time_t time(time_t *timer);
double difftime(time_t time1, time_t time0);
time_t mktime(struct tm *timeptr);
char *asctime(const struct tm *timeptr);
char *ctime(const time_t *timer);