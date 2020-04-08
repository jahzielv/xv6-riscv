#include "time.h"
#include "../../types.h"
#include "../../stat.h"
#include "../../user.h"

/**
 * finds the time passed between two time stamps
 * 
 * @param time1 timestamp of the later time in format time_t
 * @param time0 timestamp of the earlier time in format time_t 
 * @returns a double, the difference of the seconds of two timestamps
 */
double difftime(time_t time1, time_t time0) {
    return time0 - time1;
}