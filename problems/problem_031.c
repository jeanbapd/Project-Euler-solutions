/**
* Problem 31: Coin sums
 *
 * Goal: How many different ways can £2 be made using any number of coins?
 *
 * Difficulty: 2
 */

#include <stdio.h>
#include "../utils/timer.h"


/**
 * @brief Counts the number of ways to make a sum with coins.
 * Uses dynamic programming to solve the "coin change" problem.
 *
 * Complexity: O(n * m) where n = target, m = number of coins
 *
 * @return The number of different ways to make the target sum
 */
long long solve(const int target) {

    const int coins[8] = {1,2,5,10,20,50,100,200};
    long long result[target + 1];

    result[0] = 1;

    for (int i = 1; i <= target; i++) {
        result[i] = 0;
    }

    for (int c = 0; c < 8; c++) {
        for (int s = coins[c]; s <= target; s++) {
            result[s] += result[s - coins[c]];
        }
    }

    return result[target];

}

/**
 * @brief Main function
 */
int main() {

    start_timer();
    const long long result = solve(200);
    printf(" result = %lld\n", result);
    stop_timer();
}