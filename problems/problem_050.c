/**
* Problem 50: Consecutive Prime Sum
 *
 * Goal: Find the prime below one million that can be written as the sum of the most consecutive primes
 * Difficulty: 5%
 */

#include "../utils/timer.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/**
 * @brief Generate a sieve of Eratosthenes up to limit
 *
 * Complexity: O(n log log n)
 * @return boolean array marking primality
 */
bool* sieve(const int limit) {
    bool *is_prime = calloc(limit + 1, sizeof(bool));

    for (int i=0; i <= limit; i++) {
        is_prime[i] = true;
    }

    is_prime[0] = is_prime[1] = false;

    for (int i=2; i * i <= limit; i++) {
        if (is_prime[i]) {
            for (int j=i*i; j <= limit; j += i) {
                is_prime[j] = false;
            }
        }
    }

    return is_prime;
}


/**
 * @brief Extract primes from a sieve into a compact array
 *
 * Complexity: O(n)
 * @param is_prime Sieve array
 * @param limit Maximum value in the sieve
 * @param count Output number of primes
 * @return array of primes
 */
int* extract_primes(const bool *is_prime, const int limit, int *count) {

    *count = 0;
    for (int i=2; i <= limit; i++) {
        if (is_prime[i]) (*count)++;
    }

    int *primes = calloc(*count, sizeof(int));
    int idx = 0;
    for (int i=2; i <= limit; i++) {
        if (is_prime[i]) {
            primes[idx++] = i;
        }
    }
    return primes;
}


/**
 * @brief Find the longest consecutive prime sum below a given limit
 *
 * Complexity: O(p²) where p is the number of primes
 * @return the prime with the longest consecutive sum
 */
long long solve(const int limit) {
    bool *is_prime = sieve(limit);

    int prime_count;
    int *primes = extract_primes(is_prime,limit,&prime_count);

    int max_length = 0;
    long long result = 0;

    for (int start = 0; start < prime_count; start++) {
        long long sum = 0;

        for (int end = start; end < prime_count; end++) {
            sum += primes[end];

            if (sum > limit) break;

            const int length = end - start + 1;

            if (is_prime[sum] && length > max_length) {
                max_length = length;
                result = sum;
            }
        }
    }
    free(primes);
    free(is_prime);

    return result;
}



/**
 *
 * @brief Main function
 */
int main() {
    start_timer();
    const long long result = solve(1000000);
    printf("Result = %lld\n", result);
    stop_timer();
}
