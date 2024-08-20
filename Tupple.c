// sparse matrixx


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

// Function to print the matrix
void printMatrix(int matrix[3][4], int rows, int cols) {
    printf("Sparse Matrix:\n");
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
    int smat[3][4] = {
        {0, 0, 3, 0},
        {4, 0, 0, 5},
        {0, 6, 0, 0}
    };

    int rows = 3;
    int cols = 4;
    int n = 4; // Number of non-zero elements

    // The result matrix for storing the tuple representation
    int tmat[13][3]; // Adjust size based on maximum number of non-zero elements + 1 for dimensions

    // Convert sparse matrix to tuple representation
    Tupple_mat(smat, tmat, rows, cols, n);

    // Print the original and tuple matrices
    printMatrix(smat, rows, cols);
    printTupleMatrix(tmat, n + 1); // Print number of rows in tmat

    return 0;
}
