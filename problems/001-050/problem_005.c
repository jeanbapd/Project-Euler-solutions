/**
* Problem 5: Smallest Multiple
 *
 * Goal: Find the smallest positive number that is evenly divisible by all numbers from 1 to 20.
 *
 * Difficulty: 5%
 */

#include "../../utils/timer.h"
#include "stdio.h"
#include "math.h"

/**
 * @brief First approach: Brute force
 *  Try each number untill we find one divisible by all dividers
 *  Complexity: O(n * k) where k is the number of dividers
 * @return the solution
 */
long brute_force() {
    int dividers[8] = {16,9,5,7,11,13,17,19};
    int i = 0;
    long num = 20;
    while (i <= 7) {
        if (num % dividers[i] == 0) {
            i++;
        }
        else {
            num++;
            i = 0;
        }
    }
    return num;

}

/**
 *@brief Calculate GCD using Euclidean algorithm
 */
long gcd(long a,long b) {
    while (b != 0) {
        long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

/**
 *@brief Calculate LCM of two numbers
 */
long lcm(long a, long b) {
    return (a * b) / gcd(a, b);
}
/**
 *@brief Second approach: Optimized
 *Uses LCM formula iteratively
 * Complexity O(k * log(max_value))
 * @return the result
 */
long optimized() {
    int dividers[8] = {16,9,5,7,11,13,17,19};
    long num = dividers[0];
    for (int i = 1; i < 8; i++) {
        num = lcm(num,dividers[i]);
    }

    return num;
}

/**
 *@brief Main function
 */
int main() {

    start_timer();
    int resultBF10 = brute_force();
    printf("brute_force result = %d\n", resultBF10);
    stop_timer();

    start_timer();
    int resultOpt = optimized();
    printf("optimized n result = %d\n", resultOpt);
    stop_timer();


    return 0;

}