/**
* Problem 22: Names Scores
 *
 * Goal: Compute the sum of name scores from a sorted list of names.
 *       Each name's score is its alphabetical position * sum of letter values (A=1, B=2, etc.)
 *
 * Difficulty: 0
 * Example: ["COLIN"] at position 938 -> score = 938 * (3+15+12+9+14) = 49,714
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../utils/timer.h"

/**
 * @brief Comparison function for qsort to sort strings alphabetically
 *
 * @return Negative if name1 < name2, 0 if equal, positive if name1 > name2
 */
int compare(const void *name1, const void *name2) {
    const char *n1 = *(const char **)name1;
    const char *n2 = *(const char **)name2;
    return strcmp(n1, n2);
}

/**
 * @brief Read names from a comma-separated quoted file
 *
 * @return Array of name strings, or NULL if file cannot be opened
 */
char** read_names(const char *file_name, int *count) {

    FILE *f = fopen(file_name, "r");
    if (!f) {
        return NULL;
    }

    int cap = 100;
    *count = 0;
    char **names = malloc(cap * sizeof(char*));
    char buffer[256];
    while (fscanf(f,"\"%[^\"]\"", buffer) == 1) {
        if (*count >= cap) {
            cap *= 2;
            names = realloc(names, cap*sizeof(char*));
        }

        names[*count] = malloc((strlen(buffer) + 1) * sizeof(char));
        strcpy(names[*count], buffer);
        (*count)++;

        fscanf(f,",");
    }
    fclose(f);
    return names;


}

/**
 * @brief Free memory allocated for names array
 */
void free_names(char **names, int count) {

    for (int i = 0; i < count; i++) {
        free(names[i]);
    }
    free(names);
}
/**
 * @brief Calculate alphabetical value of a name
 *
 * @details Sums the position values of each letter (A=1, B=2, ..., Z=26)
 * Complexity: O(n) where n is the length of the name
 * @return Sum of letter values
 */
long alpha_value(const char *name) {
    long result = 0;
    for (int i = 0; name[i] != '\0'; i++) {
        result += (name[i] - 'A' + 1);
    }
    return result;
}
/**
 * @brief Compute the sum of all name scores
 *
 * @details Steps:
 *          1. Read names from file
 *          2. Sort names alphabetically
 *          3. Calculate each name's score: position * alphabetical_value
 *          4. Sum all scores
 *
 * Complexity: O(N log N) for sorting, O(N*M) for scoring where M is avg name length
 *
 * @return Total sum of all name scores
 */
long solve() {

    int count;
    char **names = read_names("utils/names.txt", &count);
    qsort(names, count, sizeof(char*), compare);

    long result = 0;
    for (long i = 0; i < count; i++) {
        result += (i + 1) * alpha_value(names[i]);
    }
    free_names(names,count);
    return result;

}

/**
 *@brief Main function
 */
int main() {

    start_timer();
    const long result = solve();
    printf("result = %ld\n", result);
    stop_timer();
}


