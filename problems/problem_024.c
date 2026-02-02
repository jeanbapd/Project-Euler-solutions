/**
* Problem 24: Lexicographic Permutations
 *
 * Goal: What is the millionth lexicographic permutation of the digits 0, 1, 2, 3, 4, 5, 6, 7, 8 and 9?
 *
 * Difficulty: 5%
 *
 */


#include <stdio.h>
#include "../utils/timer.h"



/**
 * @brief Find and print the nth lexicographic permutation of digits 0-9
 *
 * Complexity: O(n²) where n=10 (number of digits)
 */
void solve(long long rank) {
    rank--;
    long long fact[11];
    int digit[10];
    int n = 10;

    fact[0] = 1;
    for (int i = 1; i <= n; i++) {
        fact[i] = fact[i - 1] * i;
    }

    for (int i = 0; i < n; i++) {
        digit[i] = i;
    }

    for (int pos = 10; pos >= 1; pos--) {
        const long long f = fact[pos - 1];
        const int idx = (int) (rank / f);
        rank = rank % f;

        const int chosen = digit[idx];
        printf("%d", chosen);
        for (int j = idx; j < n - 1; j++) {
            digit[j] = digit[j + 1];
        }
        n--;
    }
    printf("\n");

}

/**
 *@brief Main function
 */
int main() {

    start_timer();
    solve(1000000);
    stop_timer();
}


