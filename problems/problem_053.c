/**
* Problem 53: Combinatoric Selections
 *
 * Goal: Count values of nCr for 1 <= n <= 100 that exceed one million
 * Difficulty: 1
 */

#include <stdio.h>
#include "../utils/timer.h"
#include <stdbool.h>
#include <math.h>

/**
 * @brief Check if nCr exceeds one million using logarithms
 *
 * Complexity: O(r)
 * @return true if nCr > 1,000,000
 */
bool combinatoric(const int n, const int r) {
    double result = 0.0;

    for (int i = 0; i < r; i++) {
        result += log(n - i) - log(i + 1);
    }
    return result > log(1000000);

}

/**
 * @brief Count combinations greater than one million for n up to 100
 *
 * Complexity: O(n^3) with logarithm-based check
 * @return the count
 */
int solve() {
    int count = 0;

    for (int n = 1; n <= 100; n++) {
        for (int r = 1; r <= n; r++) {
            if (combinatoric(n, r)) {
                count++;
            }
        }
    }
    return count;
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
