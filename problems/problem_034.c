/**
* Problem 34: Digit Factorials
 *
 * Goal: Find the sum of all numbers equal to the sum of the factorial of their digits
 * Difficulty: 1
 */

#include <math.h>
#include <stdio.h>
#include "../utils/timer.h"
#include <stdbool.h>

/**
 * @brief Compute the upper bound for checking curious numbers
 *
 * Complexity: O(k) where k is the number of digits
 * @return the maximum value to test
 */
long long borne() {
    const long long nine_factorial = 362880;
    long long k = 1;

    while (pow(10,k - 1) <= k * nine_factorial) k++;

    const long long max_digit = --k;
    return max_digit * nine_factorial;
}


/**
 * @brief Check if a number equals the sum of the factorial of its digits
 *
 * Complexity: O(d) where d is the number of digits
 * @return true if the number is curious, false otherwise
 */
bool is_curious_number(const long long number) {
    const long long fact[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};

    long long sum = 0;
    long long x = number;

    while (x > 0) {
        const long long digit = x % 10;
        sum += fact[digit];
        x /= 10;
    }

    return sum == number;
}

/**
 * @brief Sum all curious numbers below the computed upper bound
 *
 * Complexity: O(limit * d) where d is the number of digits
 * @return the result
 */
long long solve() {
    long long sum = 0;
    const long long limit = borne();
    for (int n = 10; n <= limit; n++) {
        if (is_curious_number(n)) sum += n;
    }
    return sum;
}

/**
 *
 * @brief Main function
 */
int main() {
    start_timer();
    printf("%lld\n", solve());
    stop_timer();
}
