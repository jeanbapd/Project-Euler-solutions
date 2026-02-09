/**
* Problem 48: Self Powers
 *
 * Goal: Find the last ten digits of the series 1^1 + 2^2 + ... + 1000^1000
 * Difficulty: 5%
 */

#include <stdio.h>
#include "../utils/timer.h"



/**
 * @brief Compute modular exponentiation by squaring
 *
 * Complexity: O(log(power))
 * @return the modular result
 */
long long mod_pow(long long base, long long power, const long long mod) {
    long long result = 1;
    base %= mod;

    while (power > 0) {
        if (power % 2 == 1) {
            result = ((__int128_t)result * base) % mod;
        }
        base = ((__int128_t)base * base) % mod;
        power >>= 1;
    }

    return result;
}


/**
 * @brief Sum self powers modulo 10^10
 *
 * Complexity: O(n log n)
 * @return the last ten digits of the series
 */
long long solve() {

    long long sum = 0;
    const long long ten_power_ten = 10000000000LL;

    for (long long i = 1; i <= 1000; i++) {
        sum = (sum + mod_pow(i,i,ten_power_ten)) % ten_power_ten;
    }

    return sum;
}



/**
 *
 * @brief Main function
 */
int main() {

    start_timer();
    const long long sum = solve();
    printf("%lld\n", sum);
    stop_timer();

}
