#include <stdio.h>
#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_NONZERO 1000

// Function to convert a matrix to its sparse representation
void convertToSparse(int matrix[MAX_ROWS][MAX_COLS], int sparseMatrix[MAX_ROWS][MAX_NONZERO][2], int rows, int cols, int rowSizes[MAX_ROWS]) {
    for (int i = 0; i < rows; ++i) {
        int nonZeroCount = 0;
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] != 0) {
                sparseMatrix[i][nonZeroCount][0] = j;    // Column index
                sparseMatrix[i][nonZeroCount][1] = matrix[i][j];  // Value
                ++nonZeroCount;
            }
        }
        rowSizes[i] = nonZeroCount;
    }
}

// Function to multiply two sparse matrices
void multiplySparseMatrices(int matrix1[MAX_ROWS][MAX_COLS], int rows1, int cols1, int matrix2[MAX_ROWS][MAX_COLS], int rows2, int cols2, int resultMatrix[MAX_ROWS][MAX_COLS]) {
    if (cols1 != rows2) {
        printf("Matrix multiplication not possible.\n");
        return;
    }

    int rowSizes1[MAX_ROWS], sparseMatrix1[MAX_ROWS][MAX_NONZERO][2];
    int rowSizes2[MAX_ROWS], sparseMatrix2[MAX_ROWS][MAX_NONZERO][2];

    convertToSparse(matrix1, sparseMatrix1, rows1, cols1, rowSizes1);
    convertToSparse(matrix2, sparseMatrix2, rows2, cols2, rowSizes2);

    // Initialize result matrix to 0
    for (int i = 0; i < rows1; ++i) {
        for (int j = 0; j < cols2; ++j) {
            resultMatrix[i][j] = 0;
        }
    }

    // Perform multiplication using sparse representation
    for (int i = 0; i < rows1; ++i) {
        for (int k = 0; k < rowSizes1[i]; ++k) {
            int col1 = sparseMatrix1[i][k][0];
            int value1 = sparseMatrix1[i][k][1];
            for (int j = 0; j < rowSizes2[col1]; ++j) {
                int col2 = sparseMatrix2[col1][j][0];
                int value2 = sparseMatrix2[col1][j][1];
                resultMatrix[i][col2] += value1 * value2;
            }
        }
    }
}

// Function to print a matrix
void printMatrix(int matrix[MAX_ROWS][MAX_COLS], int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    // Define two matrices
    int rows1 = 2, cols1 = 3;
    int rows2 = 3, cols2 = 2;

    int matrix1[MAX_ROWS][MAX_COLS] = {
        {1, 2, 3},
        {4, 5, 6}
    };

    int matrix2[MAX_ROWS][MAX_COLS] = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    int resultMatrix[MAX_ROWS][MAX_COLS];

    multiplySparseMatrices(matrix1, rows1, cols1, matrix2, rows2, cols2, resultMatrix);

    // Print the result matrix
    printMatrix(resultMatrix, rows1, cols2);

    return 0;
}
