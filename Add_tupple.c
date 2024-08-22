#include <stdio.h>

// Function to convert a sparse matrix to tuple representation
void Tupple_mat(int smat[3][4], int tmat[13][3], int rows, int cols, int n) {
    int i, j, k;
    k = 1; // Start from the second row in tmat

    // Set the first row with dimensions and number of non-zero elements
    tmat[0][0] = rows;
    tmat[0][1] = cols;
    tmat[0][2] = n;

    // Fill the tmat with non-zero elements and their positions
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (smat[i][j] != 0) {
                tmat[k][0] = i;        // Row index
                tmat[k][1] = j;        // Column index
                tmat[k][2] = smat[i][j]; // Value
                k++;
            }
        }
    }
}

// Function to add two sparse matrices
void addSparseMatrices(int smat1[3][4], int smat2[3][4], int result[3][4], int rows, int cols) {
    int i, j;

    // Initialize the result matrix
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            result[i][j] = smat1[i][j] + smat2[i][j];
        }
    }
}

// Function to print the matrix
void printMatrix(int matrix[3][4], int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to print the tuple representation matrix
void printTupleMatrix(int matrix[13][3], int rows) {
    printf("Tuple Matrix:\n");
    for (int i = 0; i < rows; i++) {
        printf("%d %d %d\n", matrix[i][0], matrix[i][1], matrix[i][2]);
    }
}

int main() {
    int smat1[3][4] = {
        {0, 0, 3, 0},
        {4, 0, 0, 5},
        {0, 6, 0, 0}
    };

    int smat2[3][4] = {
        {0, 2, 0, 0},
        {1, 0, 0, 0},
        {0, 0, 0, 3}
    };

    int rows = 3;
    int cols = 4;

    // Matrix to store the result of the addition
    int result[3][4];

    // Add the two sparse matrices
    addSparseMatrices(smat1, smat2, result, rows, cols);

    // Convert the result to tuple representation
    int n = 0; // Number of non-zero elements
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (result[i][j] != 0) {
                n++;
            }
        }
    }

    // The result matrix for storing the tuple representation
    int tmat[13][3]; // Adjust size based on maximum number of non-zero elements + 1 for dimensions

    // Convert result matrix to tuple representation
    Tupple_mat(result, tmat, rows, cols, n);

    // Print the original matrices, result matrix, and tuple representation
    printf("First Sparse Matrix:\n");
    printMatrix(smat1, rows, cols);

    printf("Second Sparse Matrix:\n");
    printMatrix(smat2, rows, cols);

    printf("Result Sparse Matrix:\n");
    printMatrix(result, rows, cols);

    printTupleMatrix(tmat, n + 1); // Print number of rows in tmat

    return 0;
}
