#include <stdio.h>

int delete(int list[], int size, int pos) {
    for (int i = pos - 1; i < size - 1; i++) {
        list[i] = list[i + 1];
    }
    return size - 1;
}

void traverse(int list[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", list[i]);
    }
    printf("\n");
}

int main() {
    int list[10] = {7, 5, 3, 2, 1};  // Example array with a capacity of 10 elements
    int size = 5;  // Initial size of the array
    int pos = 3;  // Position of the item to be deleted (1-based index)

    size = delete(list, size, pos);
    traverse(list, size);

    return 0;
}
