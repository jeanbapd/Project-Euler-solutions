/**
* Problem 2: Even Fibonacci Numbers
 *
 * Goal: By considering the terms in the Fibonacci sequence whose values do not exceed four million,
 * find the sum of the even-valued terms.
 *
 * Difficulty: 5%
 * Example: limit = 10 -> 1, 2, 3, 5, 8 -> Sum: 10
 */

#include <stdio.h>
#include "../../utils/timer.h"

/**
 *@brief Generate Fibonaci Numbers and sum the even numbers
 * Complexity: O(log n) where n is the limit
 * @return the result
 */
long long solve(int limit) {

     long long sum = 0;
    int a = 1, b = 2;

    while (b <= limit) {
        if (b % 2 == 0) {
            sum += b;
        }
        long long next = a + b;
        a = b;
        b = next;
    }
    return sum;
}

/**
 *@brief Main function
 */
int main() {

    start_timer();
    int result10= solve(10);
    printf("Test n = 10,  result = %d\n", result10);
    stop_timer();

    start_timer();
    long long result= solve(4000000);
    printf("Test n = 4 000 000,  result = %lld\n", result);
    stop_timer();

    return 0;
}