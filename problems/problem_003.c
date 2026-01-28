/**
* Problem 3: Largest Prime Factor
 *
 * Goal: Find the largest prime factor of the number 600851475143
 *
 * Difficulty: 5%
 * Example: The prime factors of 13195 are 5, 7, 13 and 29.
 */

#include "../utils/timer.h"
#include <stdio.h>
#include <stdlib.h>


/**
 *@brief First approach: Brute force
 *Goes through all the primary factors and looks for the maximum
 * Complexity O(sqrt(n))
 * @return the result
 */
long brute_force(long n) {

    long max = 1;

    if (n % 2 == 0) {
        max = 2;
        while (n % 2 == 0) {
            n = n / 2;
        }
    }

    int i = 3;
    while (i * i <= n) {
        if (n % i == 0) {
            if (max < i) {
                max = i;
            }
            while (n % i == 0) {
                n = n / i;
            }
        }
        i = i + 2;
    }
    if (n > 2) {
        if (max < n) {
            max = n;
        }
    }
    return max;
}

/**
 *@brief Second approach: Optimized
 *All prime number greater than 3 can be written this way: 6k + 1
 * Complexity O(log n)
 * @return the result
 */
long optimized(long n) {

    if (n<= 1) {
        return 0;
    }

    long max = 1;

    if (n % 2 == 0) {
        max = 2;
        while (n % 2 == 0) {
            n = n >> 1;
        }
    }

    if (n % 3 == 0) {
        max = 3;
        while (n % 3 == 0) {
            n = n / 3;
        }
    }

    int i = 5;
    while (i * i <= n) {
        if (n % i == 0) {
            max = i;
            while (n % i == 0) {
                n = n / i;
            }
        }

        if (n % (i + 2) == 0) {
            max = i + 2;
            while (n % (i + 2) == 0) {
                n = n / (i + 2);
            }
        }

        i = i + 6;

    }

    if (n > 1) {
        max = n;
    }

    return max;
}
/**
 *@brief Main function
 */
int main() {

    start_timer();
    int result = brute_force(13195);
    printf("Test n = 13195,  result = %d\n", result);
    stop_timer();

    start_timer();
    int result_op_test = optimized(13195);
    printf("Test n = 13195,  result = %d\n", result_op_test);
    stop_timer();


    start_timer();
    int result_op = optimized(600851475143);
    printf("Test n = 600851475143,  result = %d\n", result_op);
    stop_timer();

    return EXIT_SUCCESS;
}