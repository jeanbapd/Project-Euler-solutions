//
// Created by jean-baptiste on 27/01/2026.
//

#include <stdio.h>
#include "../../utils/timer.h"

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
 *@brief Main function
 */
int main() {

    start_timer();
    int resultBF = brute_force();
    printf("brute_force result = %d\n", resultBF);
    stop_timer();

    start_timer();
    int resultOpt = optimized();
    printf("optimized result = %d\n", resultOpt);
    stop_timer();

    return 0;

}