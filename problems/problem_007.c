/**
* Problem 7: 10 001st Prime
 *
 * Goal: What is the 10001st prime number?
 *
 * Difficulty: 5%
 *
 */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include "../utils/timer.h"


/**
 *@brief Finds the Nth prime number using the Sieve of Eratosthenes
 *
 *Complexity: O(N log log N)
 *@return the result
 */
long solve(long N) {
    bool isPrime[N + 1];

    int i,p,compt = 0;

    for (i = 2; i <= N; i++) {
        isPrime[i] = true;
    }

    for (p = 2; p <= sqrt(N); p++) {
        if (isPrime[p]) {
            for (i = p * p; i <= N; i += p) {
                isPrime[i] = false;
            }
        }
    }

    for (i = 2; i <= N; i++) {
        if (isPrime[i]) {
            compt++;
            if (compt == 10001) {
                return i;
            }
        }
    }
    return 0;
}

/**
 *@brief Main function
 */
int main() {
    //According to Rosser's theorem, the nth prime number is less than n(ln n + ln ln n), hence the 1001st prime number is smaller than 115000.
    long N = 115000;

    start_timer();
    int result = solve(N);
    printf("result = %d\n", result);
    stop_timer();
}


