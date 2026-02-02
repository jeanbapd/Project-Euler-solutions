/**
* Problem 25: 1000-digit Fibonacci Number
 *
 * Goal: Find the index of the first Fibonacci number to contain N digits
 * Difficulty: 5%
 */

#include <math.h>
#include <stdio.h>
#include <string.h>

#include "../utils/timer.h"


long long fib[500];

/**
 * @brief Calculate nth Fibonacci number with memoization
 *
 *
 * Complexity: O(n) with memoization
 * @return The nth Fibonacci number
 */
long long Fibo(const int n) {

    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    if (fib[n] != -1) {
        return fib[n];
    }

    fib[n] = Fibo(n-1) + Fibo(n-2);
    return fib[n];
}

/**
 * @brief Find first Fibonacci index with given number of digits (brute force)
 *
 * @details Generates Fibonacci numbers sequentially until finding one with
 *          the required number of digits. Uses log10 to count digits.
 *
 * Complexity: O(n) where n is the result index
 *
 * @return Index of first Fibonacci number with 'limit' digits
 */
long long brute_force(const int limit) {

    long long n = 1;

    while (1) {
        const long long f = Fibo(n);

        int nb_digits;
        if (f == 0) {
            nb_digits = 1;
        }else {
            nb_digits = (int)log10(f) + 1;
        }

        if (nb_digits >= limit) {
            return n;
        }
        n++;
    }
}

/**
 * @brief Find first Fibonacci index with given number of digits (optimized)
 *
 * @details Uses Binet's formula and logarithms to solve directly
 *
 * Complexity: O(1)
 *
 * @return Index of first Fibonacci number with 'limit' digits
 */
long long optimized(const int limit) {
    return (long long)ceil((limit - 1 + log10(sqrt(5.0))) / log10( (1.0 + sqrt(5.0)) / 2.0));
}

/**
 *@brief Main function
 */
int main() {
    memset(fib, -1, sizeof(fib));
    start_timer();
    const long long result3= brute_force(3);
    printf("Test limit = 3,  result = %lld\n", result3);
    stop_timer();

    start_timer();
    const long long result = optimized(1000);
    printf("Test limit = 1000,  result = %lld\n", result);
    stop_timer();

    return 0;
}