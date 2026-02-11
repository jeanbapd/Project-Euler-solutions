/**
* Problem 20: Factorial Digit Sum
 *
 * Goal: Find the sum of the digits in the number 100!
 *
 * Difficulty: 0
 */

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "../utils/timer.h"

/**
 * @brief Calculates the number of decimal digits in n! using logarithms
 *
 * Complexity: O(n)
 * @return the number of digits in n!
 */
size_t digits_factorial(const int n) {
    if (n < 2) {
        return 1;
    }

    double val = 0.0;
    for (int i = 2; i <= n; i++) {
        val += log10((double)i);
    }
    return (size_t)floor(val) + 1;
}

/**
 * @brief Computes n! and returns the sum of its digits
 *
 * Complexity: O(N * d) where d is the number of digits in N!
 * @return the maximum product
 */
long solve(const int n) {
    const size_t cap = digits_factorial(n);

    uint8_t *digits = (uint8_t *)calloc(cap, sizeof(uint8_t));
    if (!digits) {
        return -1;
    }

    size_t len = 1;
    digits[0] = 1;
    for (int i = 2; i <= n; i++) {
        int carry = 0;
        for (size_t j = 0; j < len; j++) {
            const int digit = digits[j] * i + carry;
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
    const long resultTest = solve(10);
    printf("result = %ld\n", resultTest);
    stop_timer();

    start_timer();
    const long result = solve(100);
    printf("result = %ld\n", result);
    stop_timer();


    return 0;

}