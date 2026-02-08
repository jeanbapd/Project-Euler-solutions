/**
* Problem 43: Sub-string Divisibility
 *
 * Goal: Find the sum of all 0 to 9 pandigital numbers with a specific sub-string divisibility property
 * Difficulty: 5%
 */

#include <stdbool.h>
#include <stdio.h>
#include "../utils/timer.h"

/**
 * @brief Check the sub-string divisibility condition at a given position
 *
 * Complexity: O(1)
 * @return true if the condition is satisfied so far
 */
bool is_valid(int digits[], const int position) {

    const int divisors[] = {2, 3, 5, 7, 11, 13, 17};

    if (position < 3) return true;

    const int num = digits[position - 2] * 100 + digits[position - 1] * 10 + digits[position];

    return (num % divisors[position - 3] == 0);
}


/**
 * @brief Backtracking search to sum all pandigital numbers with the property
 *
 * Complexity: O(10!) worst case
 * @return void (accumulates into sum)
 */
void solve(int digits[], const int position, bool used[], long long *sum) {

    if (position == 10) {

        long long number = 0;
        for (int i = 0; i < 10; i++) {
            number = number * 10 + digits[i];
        }
        *sum += number;
        return;
    }

    for (int digit = 0; digit < 10; digit++) {
        if (!used[digit]) {
            digits[position] = digit;

            if (position >= 2 && !is_valid(digits, position)) {
                continue;
            }

            used[digit] = true;
            solve(digits, position + 1, used, sum);
            used[digit] = false;
        }
    }
}

/**
 *
 * @brief Main function
 */
int main() {

    int digits[10];
    bool used[10] = {false};
    long long sum = 0;

    start_timer();
    solve(digits, 0, used, &sum);

    printf("Result = %lld\n", sum);
    stop_timer();
}
