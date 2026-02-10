
/**
* Problem 55: Lychrel Numbers
 *
 * Goal: Count how many Lychrel numbers are below ten-thousand
 * Difficulty: 5%
 */

#include <stdio.h>
#include "../utils/timer.h"
#include <stdbool.h>

#define MAX_ITERATIONS 50

/**
 * @brief Reverse the decimal digits of a number
 *
 * Complexity: O(d) where d is the number of digits
 * @return the reversed value
 */
__int128_t reverse(__int128_t number) {
    __int128_t result = 0;

    while (number != 0) {

        const int remainder = number % 10;
        result = result * 10 + remainder;
        number = number / 10;
    }
    return result;
}

/**
 * @brief Check if a number is a palindrome
 *
 * Complexity: O(d)
 * @return true if palindrome, false otherwise
 */
bool isPalindrome(const long long number) {
    return number == reverse(number);
}

/**
 * @brief Check if a number is a Lychrel candidate under the iteration limit
 *
 * Complexity: O(k * d) where k is MAX_ITERATIONS
 * @return true if likely Lychrel, false otherwise
 */
bool isLychrel(const long long n) {
    __int128_t number = n;
    for (int i = 0; i < MAX_ITERATIONS; i++) {
        number = number + reverse(number);

        if (isPalindrome(number)) {
            return false;
        }

    }
    return true;
}

/**
 * @brief Count Lychrel numbers below 10,000
 *
 * Complexity: O(n * k * d)
 * @return the count
 */
int solve() {
    int result = 0;

    for (int n = 1; n <= 10000; n++) {
        if (isLychrel(n)) {
            result++ ;
        }
    }
    return result;
}
/**
 *
 * @brief Main function
 */
int main () {
    start_timer();
    printf("Result = %d\n", solve());
    stop_timer();
}
