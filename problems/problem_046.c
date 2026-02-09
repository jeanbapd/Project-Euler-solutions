/**
* Problem 46: Goldbach's Other Conjecture
 *
 * Goal: Find the smallest odd composite that cannot be written as the sum of a prime and twice a square
 * Difficulty: 5%
 */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include "../utils/timer.h"

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
 * @brief Check if a number is a perfect square
 *
 * Complexity: O(1)
 * @return true if perfect square, false otherwise
 */
bool is_perfect_squared(const long long n) {
    const long long root = (long long)sqrt(n);
    for (long long r = root - 1; r <= root + 1; r++) {
        if (r * r == n) return true;
    }
    return false;
}

/**
 * @brief Find the smallest odd composite that breaks Goldbach's other conjecture
 *
 * Complexity: O(n * sqrt(n))
 * @return the result
 */
int solve() {

    for (int N = 9; ; N += 2) {
        if (!is_prime(N)) {
            bool find = false;

            for (int prime = 2; prime < N; prime += (prime == 2 ? 1 : 2)) {
                if (!is_prime(prime)) continue;
                const int difference = N - prime;

                const int k_square = difference / 2;
                if (is_perfect_squared(k_square)) {
                    find = true;
                    break;
                }

            }
            if (!find) {
                return N;
            }
        }
    }
}


/**
 *
 * @brief Main function
 */
int main() {
    start_timer();
    printf("Result = %d\n", solve());
    stop_timer();
}
