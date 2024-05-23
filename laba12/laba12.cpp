#include <iostream>

const int ROWS = 3;
const int COLS = 3;

void sortFirstColumnDescending(int matrix[ROWS][COLS]) {
    for (int i = 0; i < ROWS - 1; ++i) {
        for (int j = i + 1; j < ROWS; ++j) {
            if (matrix[i][0] < matrix[j][0]) {
                for (int k = 0; k < COLS; ++k) {
                    // Замість std::swap використовуємо ручну заміну
                    int temp = matrix[i][k];
                    matrix[i][k] = matrix[j][k];
                    matrix[j][k] = temp;
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

    // Ручна заміна рядків
    for (int i = 0; i < COLS; ++i) {
        int temp = matrix[maxRowIndex][i];
        matrix[maxRowIndex][i] = matrix[minRowIndex][i];
        matrix[minRowIndex][i] = temp;
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
