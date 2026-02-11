/**
* Problem 37: Truncatable Primes
 *
 * Goal: Find the sum of the only eleven primes that are truncatable from left to right and right to left
 * Difficulty: 1
 */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../utils/timer.h"

/**
 * @brief Check if a number is prime
 *
 * Complexity: O(sqrt(n))
 * @return true if prime, false otherwise
 */
bool is_prime(const long long number) {
    if (number <= 1) return false;
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
 * @brief Check if a number is left-truncatable prime
 *
 * Complexity: O(d * sqrt(n)) where d is the number of digits
 * @return true if left-truncatable, false otherwise
 */
bool is_left_truncatable(long long number) {
    while (number > 0) {
        if (!is_prime(number)) return false;
        char str[64];
        sprintf(str, "%lld", number);
        const int len = (int)strlen(str);

        if (len == 1) break;

        number = 0;
        for (long long i = 1; i < len; i++) {
            number = number * 10 + str[i] - '0';
        }

    }
    return true;
}

/**
 * @brief Check if a number is right-truncatable prime
 *
 * Complexity: O(d * sqrt(n)) where d is the number of digits
 * @return true if right-truncatable, false otherwise
 */
bool is_right_truncatable(long long number) {
    while (number > 0) {
        if (!is_prime(number)) return false;
        number /= 10;
    }
    return true;
}

/**
 * @brief Sum the first eleven truncatable primes
 *
 * Complexity: O(k * d * sqrt(n)) for k candidates
 * @return the result
 */
long long solve() {
    long long sum = 0;
    int count = 0;
    for (long long n = 11; count < 11; n+=2) {
        if (is_left_truncatable(n) && is_right_truncatable(n)) {
            count++;
            sum += n;
        }
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
