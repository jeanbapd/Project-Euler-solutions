/**
* Problem 26: Reciprocal Cycles
 *
 * Goal: Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part
 * Difficulty: 5%
 */


#include <stdio.h>

#include "../utils/timer.h"

/**
 * @brief Compute the length of the recurring cycle in the decimal expansion of 1/d
 *
 * Complexity: O(d)
 * @return the cycle length (0 if terminating)
 */
int find_cycle(const int d) {
    int seen[1001] = {0};
    int remainder = 1;
    int pos = 1;

    while (remainder != 0 && seen[remainder] == 0) {
        seen[remainder] = pos++;
        remainder = (remainder * 10) % d;
    }
    return remainder == 0 ? 0 : pos - seen[remainder];
}

/**
 * @brief Find the denominator with the longest recurring cycle for d < 1000
 *
 * Complexity: O(n²) for n = 1000
 * @return the best denominator
 */
int solve() {
    int max_d = 7;
    int max_cycle = 6;

    for (int d = 10; d <= 1000; d++) {

        const int cycle = find_cycle(d);
        if (max_cycle < cycle) {
            max_cycle = cycle;
            max_d = d;
        }

    }

    return max_d;
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
