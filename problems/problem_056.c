
/**
* Problem 56: Powerful Digit Sum
 *
 * Goal: Find the maximum digital sum of a^b for 1 <= a, b < 100
 * Difficulty: 2
 */

#include <math.h>

#include "../utils/timer.h"
#include <stdio.h>


/**
 * @brief Multiply a big integer represented by digits by a small factor
 *
 * Complexity: O(d) where d is the number of digits
 */
void multiply(int *digits, int *len, long long factor) {
    long long carry = 0;
    for (int i = 0; i < *len; i++) {
        const long long product = digits[i] * factor + carry;
        digits[i] = product % 10;
        carry = product / 10;
    }
    while (carry > 0) {
        digits[(*len)++] = carry % 10;
        carry = carry / 10;
    }
}
/**
 * @brief Compute the digit sum of a^b using manual big integer multiplication
 *
 * Complexity: O(b * d)
 * @return the digit sum
 */
int digit_sum(const long long a, const long long b) {

    int digits[300] = {0};
    int len = 1;
    digits[0] = 1;

    for (long long i = 0; i < b; i++) {
        multiply(digits, &len, a);
    }

    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += digits[i];
    }

    return sum;

}

/**
 * @brief Find the maximum digit sum of a^b for 2 <= a, b < 100
 *
 * Complexity: O(n^2 * b * d)
 * @return the maximum digit sum
 */
int solve() {
    int max_digit_sum = 0;

    for (long long a = 2; a < 100; a++) {
        for (long long b = 2; b < 100; b++) {
            const int sum = digit_sum(a,b);
            if (sum > max_digit_sum) {
                max_digit_sum = sum;
            }
        }
    }
    return max_digit_sum;
}


/**
 *
 * @brief Main function
 */
int main() {
    start_timer();
    printf("Result: %d\n", solve());
    stop_timer();
}
