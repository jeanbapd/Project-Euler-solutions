

/**
* Problem 58: Spiral Primes
 *
 * Goal: Find the side length of the square spiral for which the ratio of primes along both diagonals first falls below 10%
 * Difficulty: 2
 */

#include <stdio.h>
#include "../utils/timer.h"
#include <stdbool.h>
#include <math.h>

/**
 * @brief Check if a number is prime
 *
 * Complexity: O(sqrt(n))
 * @return true if prime, false otherwise
 */
bool is_prime(const long long number) {

    if (number <= 1) return false;
    if (number == 2) return true;

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
 * @brief Find the spiral side length where the diagonal prime ratio falls below 10%
 *
 * Complexity: O(n * sqrt(n))
 * @return the side length
 */
int solve() {
    long long primes = 0;
    long long total = 1;

    for (int n = 3; ; n += 2) {
        for (int k = 1; k <= 4; k++) {
            const long long corner = n * n - (k - 1) * (n - 1);

            if (is_prime(corner)) primes++;
        }
        total += 4;

        const double ratio = (double)primes / (double)total;
        if (ratio < 0.10) {
            return n;
        }
    }
}

/**
 *
 * @brief Main function
 */
int main() {
    start_timer();
    printf("%d\n", solve());
    stop_timer();
}
