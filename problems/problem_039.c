/**
* Problem 39: Integer Right Triangles
 *
 * Goal: For which value of p <= 1000, is the number of solutions maximized?
 * Difficulty: 5%
 */


#include <stdio.h>
#include "../utils/timer.h"

/**
 * @brief Count the number of Pythagorean triplets for a given perimeter
 *
 * Complexity: O(p²)
 * @return The number of valid triplets
 */
long long nb_triplet(const int perimeter) {
    long long count = 0;

    for (long long a = 1; a <= perimeter / 3; a++) {
        for (long long b = a; b <= (perimeter - a)/2; b++) {
            const long long c = perimeter - a - b;
            if (a*a + b*b == c*c) count++;
        }
    }
    return count;
}

/**
 * @brief Find the perimeter with the maximum number of Pythagorean triplets
 *
 * Complexity: O(limit * p²)
 * @return the result
 */
long long solve(const int limit) {
    long long  max = 0;
    int best_p = 0;
    for (int p = 1; p <= limit; p++) {
        const long long count = nb_triplet(p);
        if (count > max) {
            max = count;
            best_p = p;
        }
    }
    return best_p;
}


/**
 *
 * @brief Main function
 */
int main() {

    start_timer();
    printf("%lld\n", solve(1000));
    stop_timer();
}