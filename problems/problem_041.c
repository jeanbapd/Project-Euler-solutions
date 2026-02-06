/**
* Problem 41: Pandigital Prime
 *
 * Goal: Find the largest n-digit pandigital prime
 * Difficulty: 5%
 */

#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/timer.h"

/**
 * @brief Check if a number is prime
 *
 * Complexity: O(sqrt(n))
 * @return true if prime, false otherwise
 */
bool is_prime(const long long number) {
    int i = 2;
    bool prime = true;
    while (i < sqrt(number) && prime) {
        if (number % i == 0) {
            prime = false;
        }
        i++;
    }
    return prime;
}

/**
 * @brief Swap two characters
 */
void swap(char *a, char *b) {
    const char temp = *a;
    *a = *b;
    *b = temp;
}

/**
 * @brief Quick filter for permutations that can still be prime based on last digit
 *
 * @return true if the permutation can still be prime
 */
bool valid_permutation(char *str) {
    const int len = strlen(str);
    const char last = str[len - 1];
    return (last == '1' || last == '3' || last == '7' || last == '9');
}

/**
 * @brief Generate the previous lexicographic permutation in-place
 *
 * @return true if a new permutation was produced
 */
bool permutation(char *str) {
    int n = strlen(str);
    int i = n - 2;

    while (i >= 0 && str[i] <= str[i + 1]) i--;
    if (i<0) return false;

    int j = n - 1;
    while (str[j] >= str[i]) j--;

    swap(&str[i], &str[j]);

    int left = i + 1, right = n - 1;
    while (left < right) {
        swap(&str[left], &str[right]);
        left++;
        right--;
    }
    return true;
}


/**
 * @brief Find the largest pandigital prime from a starting permutation
 *
 * @return the prime value, or 0 if none
 */
long long solve(char *str) {
    do {
        if (valid_permutation(str)) {
            const long long number = atoll(str);
            if (is_prime(number)) {
                return number;
            }
        }
    } while (permutation(str));
    return 0;
}

/**
 *
 * @brief Main function
 */
int main() {
    start_timer();
    char str[] = "7654321" ;
    printf("%lld\n", solve(str));
    stop_timer();
}
