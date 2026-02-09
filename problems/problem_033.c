/**
* Problem 33: Digit Cancelling Fractions
 *
 * Goal: Find the denominator of the product of the non-trivial digit cancelling fractions in lowest terms
 * Difficulty: 5%
 */

#include <stdbool.h>
#include <stdio.h>
#include "../utils/timer.h"

/**
 * @brief Compute the greatest common divisor using Euclid's algorithm
 *
 * Complexity: O(log(min(a, b)))
 * @return the gcd of a and b
 */
int gcd(int a, int b) {
    while ( b != 0) {
        const int t = b;
        b = a % b;
        a = t;
    }
    return a;
}

/**
 * @brief Check if a fraction is a non-trivial digit cancelling fraction
 *
 * Complexity: O(1)
 * @return true if digit cancelling, false otherwise
 */
bool is_digit_canceling(const int num, const int denom) {
    if (num % 10 == 0 && denom % 10 == 0) return false;

    const int n1 = num / 10;
    const int d1 = denom / 10;
    const int n2 = num % 10;
    const int d2 = denom % 10;

    if (n2 == d1 && d2 != 0) {
        if (num * d2 == denom * n1) return true;
    }

    if (n2 == d2 && d1 != 0) {
        if (num * d1 == denom * n1) return true;
    }

    if (n1 == d1 && d2 != 0) {
        if (num * d2 == denom * n2 )return true;
    }

    if (n1 == d2 && d1 != 0) {
        if (num * d1 == denom * n2) return true;
    }
    return false;
}

/**
 * @brief Compute the denominator of the product of all digit cancelling fractions in lowest terms
 *
 * Complexity: O(n²) for n = 100
 * @return the denominator of the reduced product
 */
int solve() {
    int count = 4;
    int num_p = 1;
    int denom_p = 1;

    for (int num = 10; count > 0; num++) {
        for (int denom = num + 1; denom < 100; denom++) {

            if (is_digit_canceling(num, denom)) {
                count--;
                num_p *= num;
                denom_p *= denom;
            }
        }
    }
    return denom_p / gcd(num_p,denom_p);
}

/**
 *
 * @brief Main function
 */
int main() {
    start_timer();
    printf("%d\n", solve());
    stop_timer();
}
