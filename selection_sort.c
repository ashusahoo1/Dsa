#include <stdio.h>

void ssort(int list[], int size);

int main() {
    int n, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Call the selection sort function
    ssort(arr, n);

    // Print the sorted array
    printf("Sorted array:\n");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

void ssort(int list[], int size) {
    int i, j, tmp;
    for(i = 0; i < size - 1; i++) {
        for(j = i + 1; j < size; j++) {
            if(list[i] > list[j]) {
                tmp = list[i];
                list[i] = list[j];
                list[j] = tmp;
            }
        }
    }
}
