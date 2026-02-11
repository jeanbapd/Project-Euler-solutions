/**
* Problem 44: Pentagon Numbers
 *
 * Goal: Find the minimal difference of two pentagonal numbers whose sum and difference are pentagonal
 * Difficulty: 2
 */

#include <math.h>
#include <stdio.h>
#include "../utils/timer.h"
#include <stdbool.h>

/**
 * @brief Check if a number is a perfect square
 *
 * Complexity: O(1)
 * @return true if perfect square, false otherwise
 */
bool is_perfect_squared(long long n) {
    const long long root = (long long)sqrt(n);
    for (long long r = root - 1; r <= root + 1; r++) {
        if (r * r == n) return true;
    }
    return false;
}

/**
 * @brief Compute the n-th pentagonal number
 *
 * Complexity: O(1)
 * @return the pentagonal value
 */
long long pentagone(long long n) {
    return n * (3 * n - 1) / 2;
}

/**
 * @brief Check if a number is pentagonal
 *
 * Complexity: O(1)
 * @return true if pentagonal, false otherwise
 */
bool is_pentagone(long long n) {
    const long long discriminant = 1 + 24 * n;
    if (!is_perfect_squared(discriminant)) return false;
    return ((long long)sqrt(discriminant) + 1) % 6 ==0;
}

/**
 * @brief Find the minimal difference of pentagonal pairs matching the criteria
 *
 * Complexity: O(n^2)
 * @return the minimal difference
 */
long long solve() {
    for (long long d = 1; ; d++) {
        for (long long j = 1; j < d * 2; j++) {
            const long long k = j + d;
            const long long pk = pentagone(k);
            const long long pj = pentagone(j);
            const long long sum = pk + pj;
            const long long diff = pk - pj;
            if (is_pentagone(sum) && is_pentagone(diff)) return diff;
        }
    }
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
