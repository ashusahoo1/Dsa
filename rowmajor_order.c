#include <stdio.h>

void printRowMajorOrder(int MAT[][3], int rows, int cols) {
    printf("Row-major order:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", MAT[i][j]);
        }
    }
    printf("\n\n");
}

void printMatrix(int MAT[][3], int rows, int cols) {
    printf("Matrix form:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", MAT[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int MAT[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int rows = 3;
    int cols = 3;

    printRowMajorOrder(MAT, rows, cols);
    printMatrix(MAT, rows, cols);

    return 0;
}
