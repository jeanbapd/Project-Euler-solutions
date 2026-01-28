/**
* Problem 10: Summation of primes
 *
 * Goal: Find the sum of all the primes below two million.
 *
 * Difficulty: 5%
 */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include "../utils/timer.h"


/**
 * @brief Finds the sum of all primes below N using Sieve of Eratosthenes
 *
 *Complexity: O(N log log N)
 *@return the result
 */
long solve(long N) {
    bool isPrime[N + 1];

    int i,p = 0;

    for (i = 2; i <= N; i++) {
        isPrime[i] = true;
    }

    for (p = 2; p <= sqrt(N); p++) {
        if (isPrime[p]) {
            for (i = p * p; i <= N; i += p) {
                isPrime[i] = false;
            }
        }
    }
    long result = 0;

    for (long i = 2;i < 2000000;i++) {
        if (isPrime[i]) {
            result += i;
        }

    }
    return result;
}

/**
 *@brief Main function
 */
int main() {

    long N = 2000000;

    start_timer();
    long result = solve(N);
    printf("result = %ld\n", result);
    stop_timer();
}


