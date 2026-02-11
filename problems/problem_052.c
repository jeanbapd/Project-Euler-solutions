/**
* Problem 52: Permuted Multiples
 *
 * Goal: Find the smallest positive integer x such that 2x, 3x, 4x, 5x, and 6x contain the same digits
 * Difficulty: 0
 */

#include <stdbool.h>
#include <stdio.h>
#include "../utils/timer.h"


/**
 * @brief Count digit occurrences in a number
 *
 * Complexity: O(d) where d is the number of digits
 */
void digit_count(long long number, int count[10]) {

    for (int digit = 0; digit < 10; digit++) count[digit] = 0;

    while (number != 0) {
        count[number % 10]++;
        number /= 10;
    }
}

/**
 * @brief Check if multiple numbers are permutations of each other
 *
 * Complexity: O(d)
 * @return true if all are permutations
 */
bool is_permutation(const long long number1, const long long number2, const long long number3, const long long number4, const long long number5, const long long number6) {

    int count_number1[10], count_number2[10], count_number3[10], count_number4[10], count_number5[10], count_number6[10];

    digit_count(number1,count_number1);
    digit_count(number2,count_number2);
    digit_count(number3,count_number3);
    digit_count(number4,count_number4);
    digit_count(number5,count_number5);
    digit_count(number6,count_number6);

    for (int digit = 0; digit < 10; digit++) {
        if (count_number1[digit] != count_number2[digit] || count_number2[digit] != count_number3[digit]
            || count_number3[digit] != count_number4[digit] || count_number4[digit] != count_number5[digit] || count_number5[digit] != count_number6[digit]) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Find the smallest integer whose first six multiples are digit permutations
 *
 * Complexity: O(n * d)
 * @return the result
 */
long long solve() {
    for (int number = 125874;; number++) {
        if (is_permutation(number, number * 2, number * 3, number * 4, number * 5, number * 6)) {
            return number;
        }
    }
}

/**
 *
 * @brief Main function
 */
int main() {
    start_timer();
    printf("Result = %lld\n", solve());
    stop_timer();
}
