/**
* Problem 38: Pandigital Multiples
 *
 * Goal: Find the largest 1 to 9 pandigital 9-digit number formed as a concatenated product
 * Difficulty: 5%
 */

#include "../utils/timer.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Count digit occurrences in a number
 *
 * Complexity: O(d) where d is the number of digits
 */
void digit_count(long long number, int count[10]) {

    for (int digit = 0; digit < 10; digit++) count[digit] = 0;

    while (number != 0) {
        count[number % 10]++;
        number /= 10;
    }

}

/**
 * @brief Check if a 9-digit number is 1 to 9 pandigital
 *
 * Complexity: O(d)
 * @return true if pandigital, false otherwise
 */
bool is_pandigital(const long long number) {

    int count_number[10];
    digit_count(number, count_number);

    if (count_number[0] != 0) return false;
    for (int digit = 1; digit < 10; digit++) {
        if (count_number[digit] != 1) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Find the largest pandigital concatenated product
 *
 * Complexity: O(n * k * d) for candidate numbers and concatenations
 * @return the result
 */
long long solve() {
    long long max_pandigital = 0;

    for (long long n = 1; n < 10000; n++) {
        char pandigital[20] = "";

        for (long long i = 1; strlen(pandigital) < 9; i++) {
            char temp[20];
            const long long product = n * i;
            sprintf(temp, "%lld", product);
            strcat(pandigital, temp);
        }

        if (strlen(pandigital) == 9) {
            const long long number = atoll(pandigital);

            if (is_pandigital(number) && number > max_pandigital) {
                max_pandigital = number;
            }
        }

    }

    return max_pandigital;
}

/**
 *
 * @brief Main function
 */
int main() {
    start_timer();
    printf("Result = %lld\n", solve());
    stop_timer();
}
