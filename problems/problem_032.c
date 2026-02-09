
#include <stdbool.h>
#include <stdio.h>
#include "../utils/timer.h"

void digit_count(long long number1, long long number2, long long number3, int count[10]) {

    for (int digit = 0; digit < 10; digit++) count[digit] = 0;

    while (number1 != 0) {
        count[number1 % 10]++;
        number1 /= 10;
    }

    while (number2 != 0) {
        count[number2 % 10]++;
        number2 /= 10;
    }

    while (number3 != 0) {
        count[number3 % 10]++;
        number3 /= 10;
    }
}

/**
 * @brief Check if three numbers are permutations of each other
 *
 * Complexity: O(d)
 * @return true if all are permutations
 */
bool is_pandigital_product(const long long number1, const long long number2, const long long number3) {

    int count_number[10];
    digit_count(number1, number2, number3, count_number);

    if (count_number[0] != 0) return false;
    for (int digit = 1; digit < 10; digit++) {
        if (count_number[digit] != 1) {
            return false;
        }
    }
    return true;
}


long long solve() {
    long long sum = 0;

    bool used[10000] = {false};

    for (int multiplicand = 1; multiplicand <= 9; multiplicand++) {
        for (int multiplier = 1234; multiplier <= 9876; multiplier++) {
            const long long product = multiplicand * multiplier;

            if (product >= 10000) break;
            if (product < 1000) continue;

            if (is_pandigital_product(multiplicand, multiplier, product) && !used[product]) {
                used[product] = true;
                sum += product;
            }
        }
    }

    for (int multiplicand = 12; multiplicand <= 98; multiplicand++) {
        for (int multiplier = 123; multiplier <= 976; multiplier++) {
            const long long product = multiplicand * multiplier;

            if (product >= 10000) break;
            if (product < 1000) continue;

            if (is_pandigital_product(multiplicand, multiplier, product) && !used[product]) {
                used[product] = true;
                sum += product;
            }
        }
    }

    return sum;

}



int main() {
    start_timer();
    printf("Result: %lld\n", solve());
    stop_timer();
}