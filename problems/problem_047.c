/**
* Problem 47: Distinct Prime Factors
 *
 * Goal: Find the first four consecutive integers each with four distinct prime factors
 * Difficulty: 1
 */

#include <stdbool.h>
#include "../utils/timer.h"

/**
 * @brief Check if a number has the required count of distinct prime factors
 *
 * Complexity: O(sqrt(n))
 * @return true if the count matches, false otherwise
 */
bool has_consecutive_numbers(long long number, int consecutive_numbers) {
    int count = 0;

    for (long long p = 2; p*p <= number; p += (p == 2 ? 1 : 2)) {
        if (number % p == 0) {
            count++;
            while (number % p == 0) {
                number /= p;
            }
            if (count == consecutive_numbers) {
                return true;
            }

        }
    }
    if (number > 1) count++;
    return count == consecutive_numbers;
}




/**
 * @brief Find the first sequence of consecutive numbers with the given number of distinct prime factors
 *
 * Complexity: O(n * sqrt(n))
 * @return the first number in the sequence
 */
long long solve(const int consecutive_numbers) {

    for (int i = 2; ; i++) {
        if (has_consecutive_numbers(i,consecutive_numbers) &&
            has_consecutive_numbers(i+1,consecutive_numbers) &&
            has_consecutive_numbers(i+2,consecutive_numbers) &&
            has_consecutive_numbers(i+3,consecutive_numbers)) {
            return i;
        }
    }
}

/**
 *
 * @brief Main function
 */
int main() {
    start_timer();
    printf("Result = %lld\n",solve(4));
    stop_timer();
}
