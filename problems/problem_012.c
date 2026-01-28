/**
* Problem 12: Highly divisible triangular number
 *
 * Goal: Find the first triangular number to have over 500 divisors
 *
 * Difficulty: 5%
 */

#include <stdio.h>
#include "../utils/timer.h"

/**
 * @brief Count the number of divisors using prime factorization
 *
 * Complexity: O(sqrt(N))
 * @return number of divisors
 */
long nb_divisor(long N) {
    long result = 1;
    long p = 2;

    while (p * p<= N) {
        if (N % p == 0) {
            long a = 0;
            while (N % p == 0) {
                N /= p;
                a += 1;
            }
            result *= a + 1;
        }
        p++;
    }
    if (N > 1) {
        result *= 2;
    }
    return result;
}

/**
 * @brief Find first triangular number with at least limit divisors
 *
 * Complexity: O(n * sqrt(n))
 * @return the triangular number
 */
long solve(long limit ) {
    int n = 7;
    while (true) {
        long num_divisors;
        if (n % 2 == 0) {
            num_divisors = nb_divisor(n / 2) * nb_divisor(n +1);
        } else {
            num_divisors = nb_divisor(n) * nb_divisor((n + 1) / 2);
        }
        if (num_divisors >= limit) {
            return (n * ( n+1 )/2);
        }
        n++;
    }
}

/**
 *@brief Main function
 */
int main() {

    start_timer();
    long result = solve(6);
    printf("Test limit = 6 result = %ld\n", result);
    stop_timer();

    start_timer();
    long result500 = solve(500);
    printf("Test limit = 500 result = %ld\n", result500);
    stop_timer();


    return 0;

}