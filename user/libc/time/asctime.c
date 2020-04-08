#include "time.h"
#include "../../types.h"
#include "../../stat.h"
#include "../../user.h"

/**
 * converts a struct tm time to a standardized string format
 * with day of the week, mon, date, year, and time
 * 
 * @param timeptr tm struct pointer containing the time that needs to be converted
 * @return string of the standardized time
 */
char *asctime(const struct tm *timeptr) {

    char* wday = (char *) malloc(2);
    if (timeptr->tm_wday == 0) {
        wday = "Sun";
    } else if (timeptr->tm_wday == 1) {
        wday = "Mon";
    } else if (timeptr->tm_wday == 2) {
        wday = "Tues";
    } else if (timeptr->tm_wday == 3) {
        wday = "Wed";
    } else if (timeptr->tm_wday == 4) {
        wday = "Thu";
    } else if (timeptr->tm_wday == 5) {
        wday = "Fri";
    } else if (timeptr->tm_wday == 6) {
        wday = "Sat";
    }

    char* mon_name = (char *) malloc(2);
    if (timeptr->tm_mon-1 == 0) {
        mon_name = "Jan";
    } else if (timeptr->tm_mon-1 == 1) {
        mon_name = "Feb";
    } else if (timeptr->tm_mon-1 == 2) {
        mon_name = "Mar";
    } else if (timeptr->tm_mon-1 == 3) {
        mon_name = "Apr";
    } else if (timeptr->tm_mon-1 == 4) {
        mon_name = "May";
    } else if (timeptr->tm_mon-1 == 5) {
        mon_name = "Jun";
    } else if (timeptr->tm_mon-1 == 6) {
        mon_name = "Jul";
    } else if (timeptr->tm_mon-1 == 7) {
        mon_name = "Aug";
    } else if (timeptr->tm_mon-1 == 8) {
        mon_name = "Sep";
    } else if (timeptr->tm_mon-1 == 9) {
        mon_name = "Oct";
    } else if (timeptr->tm_mon-1 == 10) {
        mon_name = "Nov";
    } else if ((timeptr->tm_mon)-1 == 11) {
        mon_name = "Dec";
    }
    
    printf(1, "The current time in standardized format is %s, %s %d %d %d:%d:%d.\n",
        wday, mon_name, timeptr->tm_mday, timeptr->tm_year,
        timeptr->tm_hour, timeptr->tm_min, timeptr->tm_sec);

    char * result = "";
    return result;
}

