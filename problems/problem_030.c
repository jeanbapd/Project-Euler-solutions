/**
 * Problem 30: Digit fifth powers
 *
 * Goal: Find the sum of all numbers that can be written as the sum of fifth powers of their digits.
 *
 * Difficulty: 0
 */

#include <math.h>
#include <stdio.h>
#include <stdbool.h>
#include "../utils/timer.h"

/**
 * @brief Calculates the upper bound for numbers that can be digit fifth powers
 *
 * @return The maximum possible value for a valid number
 */
long long borne(const long long power) {
    long long k = 1;
    while (pow(10, k -1) <= k * pow(9,power)) {
        k++;
    }
    const long long max_digit = --k;
    return max_digit * pow(9,power);
}

/**
 * @brief Checks if a number equals the sum of fifth powers of its digits
 *
 * @return true if number is an Armstrong number (for power 5), false otherwise
 */
bool is_armstrong(const long long number) {
    long long sum = 0;
    long long x = number;
    while (x > 0) {
        long long d = x % 10;
        sum += pow(d, 5);
        x /= 10;
    }
    return sum == number;
}

/**
 * @brief Brute force approach
 * Check all numbers from 10 to the calculated upper bound.
 * Starting at 10 because single-digit numbers are excluded by the problem.
 * Complexity: O(n * d) where n = upper bound, d = average number of digits
 * @return Sum of all numbers equal to the sum of fifth powers of their digits
 */
long long solve() {
    long long limit = borne(5);

    long long sum = 0;
    for (int n = 10; n <= limit; n++) {
        if (is_armstrong(n)) {
            sum += n;
        }
    }

    return sum;
}

/**
 * @brief Main function
 */
int main() {

    start_timer();
    printf("%lld\n", solve());
    stop_timer();

}