
/**
* Problem 49: Prime Permutations
 *
 * Goal: Find the 12-digit number formed by concatenating the three terms of the other 4-digit prime permutation sequence
 * Difficulty: 1
 */


#include "../utils/timer.h"
#include <stdio.h>
#include <stdbool.h>
#include <math.h>

/**
 * @brief Check if a number is prime
 *
 * Complexity: O(sqrt(n))
 * @return true if prime, false otherwise
 */
bool is_prime(const long long number) {

    if (number <= 1) return false;
    if (number == 2) return true;

    int i = 2;
    bool prime = true;
    while (i <= sqrt(number) && prime) {
        if (number % i == 0) {
            prime = false;
        }
        i++;
    }
    return prime;
}

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
 * @brief Check if three numbers are permutations of each other
 *
 * Complexity: O(d)
 * @return true if all are permutations
 */
bool is_permutation(const long long number1, const long long number2, const long long number3) {

    int count_number1[10], count_number2[10], count_number3[10];
    digit_count(number1,count_number1);
    digit_count(number2,count_number2);
    digit_count(number3,count_number3);

    for (int digit = 0; digit < 10; digit++) {
        if (count_number1[digit] != count_number2[digit] || count_number2[digit] != count_number3[digit]) {
            return false;
        }
    }
    return true;
}

/**
 * @brief Find the concatenated result of the prime permutation sequence
 *
 * Complexity: O(n^2 * sqrt(n))
 * @return void (writes into result)
 */
void solve(char *result) {

    for (int prime = 1488; prime < 10000; prime++) {
        if (!is_prime(prime)) continue;

        const int max_d = (9999 - prime) / 2;

        for (int d = 1; d <= max_d; d++) {
            const int second_prime = prime + d;
            const int third_prime = prime + 2 * d;

            if (is_prime(second_prime) && is_prime(third_prime) &&
                is_permutation(prime, second_prime, third_prime)) {

                sprintf(result, "%d%d%d", prime,second_prime,third_prime);
                return;
            }
        }
    }
}



/**
 *
 * @brief Main function
 */
int main() {
    char result[13];
    start_timer();
    solve(result);
    printf("Result = %s\n",result);
    stop_timer();
}
