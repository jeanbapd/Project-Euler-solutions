/**
 * Problem 1: Multibles of 3 or 5
 *
 * Goal: Find the sum of all the multiples of 3 or 5 below 1000.
 *
 * Difficulty: 5%
 * Example: 10 -> 3, 5, 6, 9 -> Sum: 23
 */

#include "../utils/timer.h"
#include "stdio.h"

/**
 * @brief First approach: Brute force
 *  Go through all integers smaller than n and check if they are multiples of 3 or 5.
 *  Complexity: O(n)
 * @return the solution
 */
int brute_force(int n) {

    int sum = 0;

    for (int i = 1; i < n; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;

}
/**
 * @brief the sequence is k*n(n+1)/2
 */
int sequence(int k, int limit) {
    int n = (limit - 1)/k;
    return  k * n * (n + 1) / 2;
}

/**
 *@brief Second approach: Optimized
 *The sum of all mutiple of 3 or 5 is equals of the sum of multiples of 3 plus sum of multiples of 5
 * minus sum of multiples of 15 (because 15 is a multiple of 3 AND 5).
 * Complexity O(1)
 * @return the result
 */
int optimized(int limit) {
    return sequence(3,limit) + sequence(5,limit) - sequence(15,limit);
}

/**
 *@brief Main function
 */
int main() {

    start_timer();
    int resultBF10 = brute_force(10);
    printf("brute_force n = 10 result = %d\n", resultBF10);
    stop_timer();

    start_timer();
    int resultOpt = optimized(10);
    printf("optimized n = 10 result = %d\n", resultOpt);
    stop_timer();

    start_timer();
    int resultOpt1000 = optimized(1000);
    printf("optimized n = 1000  result = %d\n", resultOpt1000);
    stop_timer();

    return 0;

}