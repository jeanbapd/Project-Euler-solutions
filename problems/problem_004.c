/**
* Problem 4: Largest Palindrome Product
 *
 * Goal: Find the largest palindrome made from the product of two 3-digit numbers.
 *
 * Difficulty: 5%
 * Example: The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 * 99.
 */

#include <stdio.h>
#include <stdlib.h>
#include "../utils/timer.h"
#include <stdbool.h>
#include <string.h>

/**
 *@brief Algorithm to check if a number is a palindrome
 *
 * Complexity: O(6)
 */
bool is_palindrome(long number) {
    char palin[7];
    sprintf(palin, "%ld", number);
    size_t len = strlen(palin);

    for (size_t i = 0; i < len; i++) {
        if (palin[i] != palin[len-i-1]) {
            return false;
        }
    }
    return true;
}


/**
 *@brief The product of two three-digit numbers is at least equal to 10,000 and at most equal to 998,001,
 * so finding the largest palindrome amounts to searching for palindromes in this range,
 * starting with 998,001 and then decrementing.
 *
 * Complexity: O(nb_pairs*d) where d is the number of digit in the number (d = 6)  and nb_pairs the number of pairs tested
 * @return the result
 */
long solve() {
    long result = 0;

    for (int i = 999; i >= 100; i--) {

        if (i * 999 < result) {
            break;
        }

        for (int j = 999; j >= i; j--) {

            long number = i * j;

            if (is_palindrome(number)) {
                result = number;
                break;
            }
        }
    }
    return result;
}




/**
 *@brief Main function
 */
int main() {

    start_timer();
    int result10= solve();
    printf("Test,  result = %d\n", result10);
    stop_timer();
    return EXIT_SUCCESS;
}