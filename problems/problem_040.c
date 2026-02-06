/**
* Problem 40: Champernowne's Constant
 *
 * Goal: Find the product of the digits at positions 1,10,100,1000,10000,100000,1000000
 * Difficulty: 5%
 */

#include <stdio.h>
#include <string.h>
#include "../utils/timer.h"

/**
 * @brief Compute the product of Champernowne constant digits at positions 1,10,100,...,1,000,000
 *
 * Complexity: O(n * d) where d is the number of digits per integer
 * @return the result
 */
long long solve() {
    long long  result = 1;
    long long  count = 0;

    for (long long n = 1; count < 1000000; n++) {
        char str[64];
        sprintf(str, "%lld", n);
        const int len = strlen(str);
        for (int i = 0; i < len; i++) {
            count++;
            if (count == 1 || count == 10 || count == 100 || count == 1000 || count == 10000 || count == 100000 || count == 1000000) {
                result*=(long long) (str[i] - '0');
            }
            if (count >= 1000000) break;
        }

    }
    return result;
}


/**
 *
 * @brief Main function
 */
int main() {
    start_timer();
    printf("%lld\n", solve());
    stop_timer();
}
