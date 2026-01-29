/**
* Problem 15: Lattice Paths
 *
 * Goal: How many such routes are there through a 20 * 20 grid?
 *
 * Difficulty: 5%
 *
 */

#include <stdio.h>
#include "../utils/timer.h"

/**
 * @brief Computes the binomial coefficient C(n, k) = n! / (k! * (n-k)!)
 *
 * Complexity: O(k)
 * @return The binomial coefficient C(n, k)
 */
long binomial(const long n, long k) {

    if (k > n - k) {
        k = n - k;
    }

    long result = 1;
    for (long i = 0; i < k; i++) {
        result = result * (n - i) / (i + 1);
    }

    return result;
}

/**
 * @brief Calculates the number of paths through an n * n grid
 *
 * Complexity: O(n)
 *
 * @return The number of different paths from top-left to bottom-right
 */
long solve(const long nb_side_case) {

    return binomial(nb_side_case * 2,nb_side_case);
}

/**
 *@brief Main function
 */
int main() {

    start_timer();
    const long result2 = solve(2);
    printf("Test number of side cases = 2 result = %ld\n", result2);
    stop_timer();

    start_timer();
    const long result = solve(20);
    printf("Test number of side cases = 20 result = %ld\n", result);
    stop_timer();
}


