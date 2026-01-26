/**
* Problem 6: Sum Square Difference
 *
 * Goal: Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
 *
 * Difficulty: 5%
 */

#include "../../utils/timer.h"
#include "stdio.h"
#include "math.h"

/**
 * @brief First approach: Brute force
 *  Go through all integers smaller than n
 *  Complexity: O(n)
 * @return the solution
 */
int brute_force(int n) {

    int sum_of_squares = 0;
    int square_sum = 0;

    for (int i = 1; i <= n; i++) {
        sum_of_squares = sum_of_squares + i * i;
        square_sum = square_sum + i;
    }
    square_sum = square_sum * square_sum;
    return square_sum - sum_of_squares;

}

/**
 *@brief Second approach: Optimized
 *Uses the formulas for the sum to the power of 2 and the sum of squares
 * Complexity O(1)
 * @return the result
 */
int optimized(int n) {
    int sum_of_squares =  (n * (n + 1) * (2*n + 1))/6;
    int square_sum = (n * (n + 1)/2) * (n * (n + 1)/2) ;
    return square_sum - sum_of_squares;
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
    int resultOpt1000 = optimized(100);
    printf("optimized n = 1000  result = %d\n", resultOpt1000);
    stop_timer();

    return 0;

}