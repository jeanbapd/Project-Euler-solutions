/**
* Problem 9: Special Pythagorean Triplet
 *
 * Goal: There exists exactly one Pythagorean triplet for which a + b + c = 1000. Find the product abc.
 *
 * Difficulty: 0
 *
 */
#include <stdio.h>
#include "../utils/timer.h"

/**
* @brief Finds the product  abc
 *
 * Go through all combinations of a, b, c with a, b, c between 0 and 1000.
 *
 * Complexity: O(N * N *N)
 * @return The product abc
 */
long brute_force() {

    for (int a = 0; a <= 1000; a++) {
        for (int b = a + 1; b <= 1000; b++) {
            for (int c = b + 1; c <= 1000; c++) {
                if (a + b + c == 1000 && a*a + b*b == c*c) {
                    return a*b*c;
                }
            }
        }
    }
    return 0;
}


/**
* @brief Finds the product  abc
 *
 * Thanks to the statement, we see that c = 1000 - a - b.
 * We also find a range for a and b, so we can optimize the code as follows
 *
 * Complexity: O(N * N)
 * @return The product abc
 */
long optimized() {
    for (int a = 1; a < 1000/3; a++) {
        for (int b = a + 1; b <= (1000 - a)/2; b++) {
            int c = 1000 - a - b;
            if (a*a + b*b == c*c) {
                return a*b*c;
            }
        }
    }
    return 0;
}

/**
* @brief Finds the product  abc
 *
 * Use the fact that b can be found based on a, and the framework of a found in 2.
 *
 * Complexity: O(N)
 * @return The product abc
 */
long math(){
	for (int a = 1; a < 1000/3; a++) {
		int num = 500000 - 1000*a;
		int denom = 1000 - a;
		if (num % denom == 0){
			int b = num / denom;
			int c = 1000 - a - b;
			if (b>a && c>b && a*a + b*b == c*c){
				return a*b*c;
			}
		}
	}
	return 0;
}
/**
 *@brief Main function
 */
int main() {

    start_timer();
    long resultBF = brute_force();
    printf("brute_force result = %ld\n", resultBF);
    stop_timer();

    start_timer();
    long resultOpt = optimized();
    printf("optimized result = %ld\n", resultOpt);
    stop_timer();

	start_timer();
    long resultmath = optimized();
    printf("Math result = %ld\n", resultmath);
    stop_timer();

    return 0;

}