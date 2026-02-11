/**
* Problem 14: Longest Collatz Sequence
 *
 * Goal: Which starting number, under one million, produces the longest Collatz chain?
 *
 * Difficulty: 0
 *
 */

#include <stdio.h>
#include "../utils/timer.h"

/**
 * @brief Computes the length of the Collatz sequence for a given number
 *
 * Complexity: O(log n)
 * @return The length of the sequence until reaching 1
 */
long collatz(long n) {
    long counter = 0;

    while (n != 1) {
        if (n % 2 == 0) {
            n >>= 1;
        }else {
            counter++;
            n = (3 * n + 1) >> 1;
        }
        counter++;
    }
    counter++;
    return counter;
}

/**
 * @brief Finds the number under the limit that produces the longest Collatz sequence
 *
 * Complexity: O(limit * log(limit))
 *
* @return The starting number that produces the longest sequence
 */
long solve(const long limit) {

    long max_counter = 10;
    long best_start = 13;

    for (long i = best_start; i < limit; i++) {
        const long counter = collatz(i);
        if (counter > max_counter) {
            max_counter = counter;
            best_start = i;
        }
    }
    return best_start;
}
/**
 *@brief Main function
 */
int main() {

    start_timer();
    const long result10 = solve(10);
    printf("Test limit = 10 result = %ld\n", result10);
    stop_timer();

    start_timer();
    const long result = solve(1000000);
    printf("Test limit = 1000000 result = %ld\n", result);
    stop_timer();
}


