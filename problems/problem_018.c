/**
* Problem 18: Maximum Path Sum
 *
 * Goal: Find the maximum total from top to bottom of the triangle
 *
 * Difficulty: 5%
 */

#include <stdio.h>
#include "../utils/timer.h"

/**
 * @brief Finds the maximum path sum from top to bottom of a triangle
 * using bottom-up approach
 *
 * Complexity: O(N²) where N is the number of lines
 * @return the result
 */
long solve(const int rows, int cols, int grid[rows][cols]) {

    for (int i = rows - 2; i >= 0; i--) {
        for (int j = 0; j <= i; j++) {
            const long left = grid[i + 1][j];
            const long right = grid[i + 1][j + 1];
            grid[i][j] += (left > right ? left : right);
        }
    }
    return grid[0][0];
}

/**
 *@brief Main function
 */
int main() {
    int gridTest[4][4] = {
        {3, 0, 0, 0},
        {7, 4, 0, 0},
        {2, 4, 6, 0},
        {8, 5, 9, 3}
    };
    int grid[15][15] = {
        {75, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {95, 64, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {17, 47, 82, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {18, 35, 87, 10, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {20, 4, 82, 47, 65, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {19, 1, 23, 75, 3, 34, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {88, 2, 77, 73, 7, 63, 67, 0, 0, 0, 0, 0, 0, 0, 0},
        {99, 65, 4, 28, 6, 16, 70, 92, 0, 0, 0, 0, 0, 0, 0},
        {41, 41, 26, 56, 83, 40, 80, 70, 33, 0, 0, 0, 0, 0, 0},
        {41, 48, 72, 33, 47, 32, 37, 16, 94, 29, 0, 0, 0, 0, 0},
        {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14, 0, 0, 0, 0},
        {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57, 0, 0, 0},
        {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48, 0, 0},
        {63, 66, 04, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31, 0},
        {04, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 04, 23}
    };

    start_timer();
    const long resultTest = solve(4,4,gridTest);
    printf("result = %ld\n", resultTest);
    stop_timer();

    start_timer();
    const long result = solve(15,15,grid);
    printf("result = %ld\n", result);
    stop_timer();


    return 0;

}