
#include <math.h>

#include "../utils/timer.h"
#include <stdio.h>


void multiply(int *digits, int *len, long long factor) {
    long long carry = 0;
    for (int i = 0; i < *len; i++) {
        const long long product = digits[i] * factor + carry;
        digits[i] = product % 10;
        carry = product / 10;
    }
    while (carry > 0) {
        digits[(*len)++] = carry % 10;
        carry = carry / 10;
    }
}
int digit_sum(const long long a, const long long b) {

    int digits[300] = {0};
    int len = 1;
    digits[0] = 1;

    for (long long i = 0; i < b; i++) {
        multiply(digits, &len, a);
    }

    int sum = 0;
    for (int i = 0; i < len; i++) {
        sum += digits[i];
    }

    return sum;

}

int solve() {
    int max_digit_sum = 0;

    for (long long a = 2; a < 100; a++) {
        for (long long b = 2; b < 100; b++) {
            const int sum = digit_sum(a,b);
            if (sum > max_digit_sum) {
                max_digit_sum = sum;
            }
        }
    }
    return max_digit_sum;
}


int main() {
    start_timer();
    printf("Result: %d\n", solve());
    stop_timer();
}