/**
 * Problem 35: Circular primes
 *
 * Goal: Find the sum of all circular primes below one million.
 *
 * Difficulty: 1
 */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/timer.h"


/**
 * @brief Checks if a number is prime
 *
 * @return true if prime, false otherwise
 */
bool is_Prime(const long long number) {
    int i = 2;

    bool prime = true;
    while (i <= sqrt(number) && prime) {
        if (number % i == 0) {
            prime = false;
        }
        i++;
    }
    return prime;
}

/**
 * @brief Rotates a string one position to the left
 */
void circular(char *str) {
    const int len = strlen(str);
    if (len <= 1 ) {
        return;
    }
    const char first = str[0];
    for (int i = 0; i < len - 1; i++) {
        str[i] = str[i + 1];
    }
    str[len - 1] = first;
}

/**
 * @brief Brute force approach
 * Check all primes and verify if all rotations are also prime.
 * Complexity: O(n * log n * d) where d is number of digits
 * @return Sum of all circular primes in range [n, p]
 */
long long solve(const int n, const int p) {
    long long result = 0;
    for (long long num = n; num <= p; num++) {
        if (is_Prime(num)) {
            bool state = true;
            char str[64];
            sprintf(str, "%lld", num);
            const int len = strlen(str);
            for (int k = 1; k < len; k++) {
                circular(str);
                const long long rotated = atoll(str);
                if (!is_Prime(rotated)) {
                    state = false;
                    break;
                }
            }
            if (state) {
                result++;
            }
        }
    }

    return result;
}

int main() {

    start_timer();
    const long long result = solve(2,1000000);
    printf("result = %lld\n", result);
    stop_timer();
}