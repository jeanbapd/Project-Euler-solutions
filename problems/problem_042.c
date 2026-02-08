/**
* Problem 42: Coded Triangle Numbers
 *
 * Goal: Find how many words in the list are triangle words
 * Difficulty: 5%
 */

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../utils/timer.h"

/**
 * @brief Check if a number is a perfect square
 *
 * Complexity: O(1)
 * @return true if perfect square, false otherwise
 */
bool is_perfect_squared(long long n) {
    const long long root = (long long)sqrt(n);
    for (long long r = root - 1; r <= root + 1; r++) {
        if (r * r == n) return true;
    }
    return false;
}

/**
 * @brief Check if a number is triangular
 *
 * Complexity: O(1)
 * @return true if triangular, false otherwise
 */
bool is_triangle(long long number) {
    const long long discriminant = 1 + 8 * number;
    if (!is_perfect_squared(discriminant)) return false;
    return ((long long)sqrt(discriminant) - 1) % 2 == 0;
}

/**
 * @brief Read the quoted words from a file into a dynamic array
 *
 * Complexity: O(n)
 * @param file_name Path to the words file
 * @param count Output number of words read
 * @return array of words, or NULL on error
 */
char** read_words(const char *file_name, int *count) {

    FILE *f = fopen(file_name, "r");
    if (!f) {
        return NULL;
    }

    int cap = 100;
    *count = 0;
    char **words = malloc(cap * sizeof(char*));
    char buffer[256];
    while (fscanf(f,"\"%[^\"]\"", buffer) == 1) {
        if (*count >= cap) {
            cap *= 2;
            words = realloc(words, cap*sizeof(char*));
        }

        words[*count] = malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(words[*count], buffer);
        (*count)++;

        fscanf(f,",");
    }
    fclose(f);
    return words;


}

/**
 * @brief Free memory allocated for words array
 */
void free_words(char **words, int count) {

    for (int i = 0; i < count; i++) {
        free(words[i]);
    }
    free(words);
}

/**
 * @brief Count triangle words in the provided word list
 *
 * Complexity: O(n * m) where m is average word length
 * @return the count of triangle words
 */
int solve() {
    int count;
    int result = 0;
    char **words = read_words("utils/words.txt", &count);

    for (int i = 0; i < count; i++) {
        const char *name = words[i];
        int value = 0;
        for (int j = 0; j < strlen(name); j++) {
            value += name[j] - 'A' + 1;
        }
        if (is_triangle(value)) {
            result++;
        }
    }
    free_words(words, count);
    return result;
}

/**
 *
 * @brief Main function
 */
int main() {
    start_timer();
    printf("%d\n", solve());
    stop_timer();
}
