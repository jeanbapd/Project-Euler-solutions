/**
* Problem 28: Number Spiral Diagonals
 *
 * Calculate the sum of numbers on the diagonals of an limit×limit spiral
 *
 * Difficulty: 0
 */
#include "../utils/timer.h"
#include <stdio.h>



/**
 * @brief Calculate the sum of diagonals in a number spiral without generating it
 *
 * Complexity: O(limit) - only iterates through odd-sized layers
 *
 * @return Sum of all numbers on both diagonals
 */
long long solve(const int limit) {
    long long result = 1;

    for (int n = 3; n <= limit; n+=2) {
        const int top_right = n * n;
        const int top_left = top_right - (n - 1);
        const int down_right = top_right - 3 * (n - 1);
        const int down_left = top_right - 2 * (n - 1);

        result += top_right + top_left + down_right + down_left;

    }

    return result;
}

/**
 * @brief Main function
 */
int main() {

    start_timer();
    const long result5 = solve(5);
    printf("Test result = %ld\n", result5);
    stop_timer();

    start_timer();
    const long result = solve(1001);
    printf("Result = %ld\n", result);
    stop_timer();
}