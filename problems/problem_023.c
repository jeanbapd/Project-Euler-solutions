/**
 * Problem 23: Non-Abundant Sums
 *
 * Goal: Find the sum of all positive integers which cannot be written as
 *       the sum of two abundant numbers.
 *
 * Difficulty: 5%
 */
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#include "../utils/timer.h"

/**
 * @brief Compute sum of all integers that cannot be expressed as sum of two abundant numbers
 *
 * Complexity: O(N log N) for sieve + O(A²) where A is count of abundant numbers
 *
 * @return Sum of all non-abundant-sum integers
 */
long long solve() {
    int sumDiv[28124] = {0};

    for (int div = 1; div <= 28123 / 2; div++) {
        for (int m = 2 * div; m <= 28123; m += div) {
            sumDiv[m] += div;
        }
    }

    int abundants[28123];
    int count = 0;

    for (int n = 1; n <= 28123; n++) {
        if (sumDiv[n] > n) abundants[count++] = n;
    }

    bool check[28124] = {false};

    for (int i = 0; i < count; i++) {
        const int a = abundants[i];
        for (int j = i; j < count; j++) {
            const int s = a + abundants[j];
            if (s > 28123) break;
            check[s] = true;
        }
    }

    long long result = 0;
    for (int n = 1; n <= 28123; n++) {
        if (!check[n]) {
            result += n;
        }
    }

    return result;
}

/**
 * @brief Main function
 */
int main() {

    start_timer();
    const long long result = solve();
    printf("result = %lld\n", result);
    stop_timer();
    return EXIT_SUCCESS;
}