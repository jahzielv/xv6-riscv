#include "../../../kernel/types.h"
#include "../../../kernel/stat.h"
#include "../../user.h"
#include "time.h"

/**
 * finds the time and converts to seconds * 
 * 
 * @param time_t pointer to store the current time
 * @return the time_t holding the correct time in seconds
 */
time_t time(time_t *timer) {
    struct tm r0;
    date(&r0);
    *timer = r0.tm_hour*86400 + r0.tm_min*60 + r0.tm_sec;
    return *timer;
}
