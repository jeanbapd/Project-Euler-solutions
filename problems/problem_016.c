/**
* Problem 16: Power Digit Sum
 *
 * Goal: What is the sum of the digits of the number 2^{1000}?
 *
 * Difficulty: 0
 *
 */

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../utils/timer.h"

/**
 * @brief Returns the sum of the decimal digits of 2^n.
 *
 * Builds 2^n using a decimal big-integer (array of digits), then sums its digits.
 *
 * Complexity: O(n²)
 *
 * @return The result
 */
long solve(const double n) {

    const size_t cap = (n == 0) ? 1 : (size_t)floor(n * log10(2.0)) + 1;

    uint8_t *digits = (uint8_t *)calloc(cap, sizeof(uint8_t));
    if (!digits) {
        return -1;
    }

    size_t len = 1;
    digits[0] = 1;
    for (int i = 1; i <= n; i++) {
        int carry = 0;
        for (size_t j = 0; j < len; j++) {
            const int digit = digits[j] * 2 + carry;
            digits[j] = (uint8_t)(digit % 10);
            carry = digit / 10;
        }
        while (carry) {
            if (len >= cap) {
                free(digits);
                return -1;
            }
            digits[len++] = (uint8_t)(carry % 10);
            carry /= 10;
        }
    }

    int sum = 0;
    for (size_t i = 0; i < len; i++) {
        sum += digits[i];
    }
    free(digits);
    return sum;

}

/**
 *@brief Main function
 */
int main() {

    start_timer();
    const long result2 = solve(15);
    printf("Test n = 15 result = %ld\n", result2);
    stop_timer();

    start_timer();
    const long result = solve(1000);
    printf("Test n = 1000  result = %ld\n", result);
    stop_timer();
}


