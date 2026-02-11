/**
* Problem 21: Amicable Numbers
 *
 * Goal: Evaluate the sum of all the amicable numbers under 10000.
 *
 * Difficulty: 1
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include "../utils/timer.h"

/**
 * @brief Compute the sum of all amicable numbers under limit
 *
 * @details Uses a sieve-like approach to compute sum of proper divisors,
 * then identifies amicable pairs.
 *
 * Complexity: O(N log N)
 *
 * @return The result
 */
long solve(const int limit) {

    long *sum = (long *)calloc(limit + 1, sizeof(long));
    long result = 0;
    if (!sum) {
        return -1;
    }

    for (long d = 1; d <= limit / 2; d++) {
        for (long m = 2 * d; m <= limit; m += d) {
            sum[m] += d;
        }
    }
    for (long a = 2; a <= limit; a++) {
        const long b = sum[a];
        if (b > a && b <= limit) {
            if (sum[b] == a) {
                result += a + b;
            }
        }
    }
    free(sum);
    return result;
}

/**
 *@brief Main function
 */
int main() {

    start_timer();
    const long result = solve(10000);
    printf("result = %ld\n", result);
    stop_timer();
}


