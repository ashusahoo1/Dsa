/*Removing Vowels from a 2D Array and Shifting Elements*/

#include <stdio.h>
#include <stdbool.h>

#define M 4
#define N 7

bool isVowel(char c) {
    return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
}

void removeVowels(char matrix[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (isVowel(matrix[i][j])) {
                // Shift elements in the current row and all subsequent rows
                for (int k = i; k < M; k++) {
                    for (int l = (k == i ? j : 0); l < N - 1; l++) {
                        matrix[k][l] = matrix[k][l + 1];
                    }
                    // Replace last element of each row with 'X'
                    if (k < M - 1) {
                        matrix[k][N - 1] = matrix[k + 1][0];
                    }
                }
                matrix[M - 1][N - 1] = 'X'; // Replace last element with 'X'
                j--; // Recheck the new element at this position
            }
        }
    }
}

void printMatrix(char matrix[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char matrix[M][N] = {
        {'A', 'S', 'D', 'U', 'C', 'J', 'P'},
        {'R', 'I', 'J', 'K', 'L', 'M', 'N'},
        {'N', 'T', 'W', 'O', 'Y', 'Q', 'S'},
        {'Q', 'S', 'F', 'D', 'B', 'L', 'B'}
    };
    
    printf("Original matrix:\n");
    printMatrix(matrix);
    
    removeVowels(matrix);
    
    printf("\nMatrix after removing vowels:\n");
    printMatrix(matrix);
    
    return 0;
}
