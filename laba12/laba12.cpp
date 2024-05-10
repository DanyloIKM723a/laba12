#include <iostream>
#include <algorithm>

const int ROWS = 3;
const int COLS = 3;

void sortFirstColumnDescending(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS - 1; ++i) {
        for (int j = i + 1; j < ROWS; ++j) {
            if (matrix[i][0] < matrix[j][0]) {
                for (int k = 0; k < COLS; ++k) {
                    std::swap(matrix[i][k], matrix[j][k]);
                }
            }
        }
    }
}

int main() {
    int matrix[ROWS][COLS] = { {5, 1, 2}, {3, 7, 4}, {9, 6, 8} };

    int maxRowIndex = 0, minRowIndex = 0;
    for (int i = 1; i < ROWS; ++i) {
        if (matrix[i][0] > matrix[maxRowIndex][0]) {
            maxRowIndex = i;
        }
        if (matrix[i][0] < matrix[minRowIndex][0]) {
            minRowIndex = i;
        }
    }

    for (int i = 0; i < COLS; ++i) {
        std::swap(matrix[maxRowIndex][i], matrix[minRowIndex][i]);
    }

    sortFirstColumnDescending(matrix);

    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
