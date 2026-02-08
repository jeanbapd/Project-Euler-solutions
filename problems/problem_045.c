/**
* Problem 45: Triangular, Pentagonal, and Hexagonal
 *
 * Goal: Find the next triangular number that is also pentagonal and hexagonal
 * Difficulty: 5%
 */

#include <math.h>
#include <stdio.h>
#include "../utils/timer.h"
#include <stdbool.h>

/**
 * @brief Compute the n-th hexagonal number
 *
 * Complexity: O(1)
 * @return the hexagonal value
 */
long long hexagone(long long n) {
    return 2 * n * n - n;
}

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
 * @brief Find the next hexagonal number that is also pentagonal
 *
 * Complexity: O(n)
 * @return the result
 */
long long solve() {
    for (int n = 144; ;n++) {
        const long long value = hexagone(n);
        if (is_pentagone(value)) {
            return value;
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
