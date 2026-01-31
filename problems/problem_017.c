/**
* Problem 17: Number Letter Counts
 *
 * Goal: If all the numbers from 1 to 1000 (one thousand) inclusive were written out in words, how many letters would be used?
 *
 * Difficulty: 5%
 *
 */


#include <stdio.h>


#include "../utils/timer.h"


/**
 * @brief Counts the number of letters in the English word representation of a number
 *
 * Complexity: O(1)
 * @return The number of letters (excluding spaces and hyphens)
 */
long count_letters(int n) {

    const int units[] = {0, 3, 3, 5, 4, 4, 3, 5, 5, 4};

    int teens[] = {3, 6, 6, 8, 8, 7, 7, 9, 8, 8};

    const int tens[] = {0, 0, 6, 6, 5, 5, 5, 7, 6, 6};

    if (n == 1000) {
        return 11;
    }

    long result = 0;

    if (n >= 100) {
        result += units[n / 100] + 7;
        if (n % 100 != 0) {
            result += 3;
        }
        n %= 100;
    }

    if (n >= 20) {
        result += tens[n / 10] + units[n % 10];
    }else if (n >= 10) {
        result += teens[n - 10];
    }else {
        result += units[n];
    }

    return result;
}
/**
 * @brief Calculates the total number of letters used writing all numbers from 1 to limit
 *
 * Complexity: O(limit)
 *
 * @return The result
 */
long solve(const int limit) {

    long result = 3;

    for (int i = 2; i <= limit; i++) {
        result += count_letters(i);
    }

    return result;

}

/**
 *@brief Main function
 */
int main() {

    start_timer();
    const long result5 = solve(5);
    printf("Test limit = 5 result = %ld\n", result5);
    stop_timer();

    start_timer();
    const long result = solve(1000);
    printf("Test limit = 1000  result = %ld\n", result);
    stop_timer();
}


