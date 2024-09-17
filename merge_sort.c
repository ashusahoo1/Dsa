#include <stdio.h>

void merge(int list1[], int list2[], int list3[], int s1, int s2, int *s3) {
    int i, j, k, c;
    i = 0;
    j = 0;
    k = 0;
    c = 0;

    while(i < s1 && j < s2) {
        if(list1[i] < list2[j]) {
            list3[k] = list1[i];
            i++;
        } else if(list1[i] == list2[j]) {
            list3[k] = list1[i];
            i++;
            j++;
            c++;
        } else {
            list3[k] = list2[j];
            j++;
        }
        k++;
    }

    while(i < s1) {
        list3[k] = list1[i];
        i++;
        k++;
    }

    while(j < s2) {
        list3[k] = list2[j];
        j++;
        k++;
    }

    *s3 = s1 + s2 - c; // calculate the size of the merged array excluding duplicates
}

int list1[100], list2[100], list3[100];
int s1, s2, s3;

int main() {
    int i;

    printf("\nEnter the size of both arrays:\n");
    scanf("%d%d", &s1, &s2);

    printf("\nEnter the elements in the first array:\n");
    for(i = 0; i < s1; i++) {
        scanf("%d", &list1[i]);
    }

    printf("\nEnter the elements in the second array:\n");
    for(i = 0; i < s2; i++) {
        scanf("%d", &list2[i]);
    }

    merge(list1, list2, list3, s1, s2, &s3);

    printf("\nMerged array:\n");
    for(i = 0; i < s3; i++) {
        printf("%d ", list3[i]);
    }

    return 0;
}
