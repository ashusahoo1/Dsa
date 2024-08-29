#include <stdio.h>

// Function to convert a sparse matrix to tuple representation
void Tuple_mat(int smat[3][4], int tmat[13][3], int rows, int cols, int n) {
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

// Function to transpose a tuple matrix
void Transpose_tuple(int tmat[13][3], int t_tmat[13][3]) {
    int i, k = 1;
    int n = tmat[0][2]; // Number of non-zero elements
    int rows = tmat[0][1]; // Rows of transposed matrix (originally columns)
    int cols = tmat[0][0]; // Columns of transposed matrix (originally rows)

    // Set the first row with dimensions and number of non-zero elements
    t_tmat[0][0] = rows;
    t_tmat[0][1] = cols;
    t_tmat[0][2] = n;

    // Transpose the tuple form
    for (i = 1; i <= n; i++) {
        t_tmat[k][0] = tmat[i][1]; // Transpose row and column
        t_tmat[k][1] = tmat[i][0];
        t_tmat[k][2] = tmat[i][2]; // Copy value
        k++;
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
    int t_tmat[13][3]; // For storing the transposed tuple matrix

    // Convert sparse matrix to tuple representation
    Tuple_mat(smat, tmat, rows, cols, n);

    // Transpose the tuple matrix
    Transpose_tuple(tmat, t_tmat);

    // Print the original tuple matrix and the transposed tuple matrix
    printf("Original Tuple Matrix:\n");
    printTupleMatrix(tmat, n + 1); // Print number of rows in tmat

    printf("\nTransposed Tuple Matrix:\n");
    printTupleMatrix(t_tmat, n + 1); // Print number of rows in t_tmat

    return 0;
}
