/**
* Problem 36: Double-base palindromes
 *
 * Goal: Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
 *
 * Difficulty: 0
 */

#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include "../utils/timer.h"

/**
 * @brief Checks if a string is a palindrome
 * @return true if palindrome, false otherwise
 */
bool is_palindrome(char *number) {
    const int len = strlen(number);
    for (int i = 0; i < len / 2; i++) {
        if (number[i] != number[len - 1 - i]) {
            return false;
        }
    }
    return true;
}



/**
 * @brief Checks if a number is a palindrome in binary representation
 * Uses bit manipulation to compare bits from both ends without converting to string.
 * @return true if binary representation is palindrome, false otherwise
 */
bool is_binary_palindrome(const long long number) {
    if (number == 0) return true;

    int bits = 0;
    long long temp = number;
    while (temp > 0) {
        bits++;
        temp = temp >> 1;
    }

    for (int i = 0; i < bits/2; i++) {
        const int left = (number >> (bits - i - 1)) & 1;
        const int right = (number >> i) & 1;

        if (left != right) {
            return false;
        }
    }

    return true;
}

/**
 * @brief Brute force approach
 * Check all odd numbers below 1,000,000 for double-base palindrome property.
 * Only odd numbers are checked since even numbers end in 0 in binary (not palindromic).
 * Complexity: O(n * log n)
 * @return Sum of all double-base palindromes below 1,000,000
 */
long long solve() {
    long long sum = 0;
    for (long long num = 1; num < 1000000; num+=2) {
        char str10[9];
        sprintf(str10, "%lld", num);
        const bool is_palin10 = is_palindrome(str10);
        if (is_palin10 && is_binary_palindrome(num)) {
            sum += num;
        }
    }
    return sum;
}

/**
 * @brief Generates a palindrome by mirroring digits
 * @return The generated palindrome
 */
long long generate_palindrome(int half, const bool is_odd) {
    long long palindrome = half;

    if (is_odd) {
        half = half / 10;
    }

    while (half > 0) {
        palindrome = palindrome * 10 + (half % 10);
        half = half / 10;
    }

    return palindrome;
}

/**
 * @brief Optimized approach
 * Generate palindromes in base 10 and check if they're also palindromes in base 2.
 * This dramatically reduces the search space from 1,000,000 to ~2000 candidates.
 * Complexity: O(sqrt(n) * log n)
 * @return Sum of all double-base palindromes below 1,000,000
 */
long long optimized() {
    long long sum = 0;

    for (int i = 1; i < 1000; i++) {
        const long long num = generate_palindrome(i, true);
        if (num >= 1000000) break;

        if (is_binary_palindrome(num)) {
            sum += num;
        }
    }

    for (int i = 1; i < 1000; i++) {
        const long long num = generate_palindrome(i, false);
        if (num >= 1000000) break;

        if (is_binary_palindrome(num)) {
            sum += num;
        }
    }

    return sum;
}

/**
 * @brief Main function
 */
int main () {

    start_timer();
    const long long result = solve();
    printf("result = %lld\n",result);
    stop_timer();

    start_timer();
    const long long result_opt = optimized();
    printf("result = %lld\n",result_opt);
    stop_timer();
}