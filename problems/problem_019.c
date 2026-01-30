/**
* Problem 19: Counting Sundays
 *
 * Goal: Count how many Sundays fell on the first of the month
 * during the twentieth century (1 Jan 1901 to 31 Dec 2000).
 *
 * Difficulty: 5%
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "../utils/timer.h"

/**
 * @brief Get number of days in a month
 *
 * Complexity: O(1)
 * @return Number of days in the month
 */
int days_in_month(const int month, const int year) {
    int result = 0;

    if (month == 2) {
        result =  __isleap(year) ? 29 : 28;
    } else if ( month == 4 || month == 6 || month == 9 || month == 11) {
        result = 30;
    }else {
        result = 31;
    }
    return result;
}

/**
 * @brief Count Sundays on the first of the month (1901-2000)
 *
 * @details Uses day-of-week encoding: 0=Monday, 1=Tuesday,..., 6=Sunday
 * Jan 1, 1901 was a Tuesday (weekday=1)
 * Complexity: O(12 * 100) = O(1)
 *
 * @return Number of Sundays on the first of the month
 */
long solve() {

    int weekdays = 1; //Tuesday
    long result = 0;

    for (int year = 1901; year <= 2000; year++) {
        for (int month = 1; month <= 12; month++) {
            if (weekdays == 6) {
                result++;
            }
            weekdays = (weekdays + days_in_month(month, year)) % 7;
        }
    }
    return result;
}

/**
 *@brief Main function
 */
int main() {

    start_timer();
    const long result = solve();
    printf("result = %ld\n", result);
    stop_timer();
}


