// cq implementation using array

#define MAX 3
#include<stdio.h>

int cq[MAX];
int f = -1, r = -1;

void insert() {
    int x;
    if ((f == 0 && r == MAX - 1) || (f == r + 1)) {
        printf("cq overflow\n");
    } else {
        printf("Enter a value: ");
        scanf("%d", &x);
        if (f == -1) {
            f = 0;
        }
        r = (r + 1) % MAX;
        cq[r] = x;
    }
}

void deletion() {
    if (f == -1) {
        printf("cq underflow\n");
    } else {
        printf("The deleted element is %d\n", cq[f]);
        if (f == r) {
            f = -1;
            r = -1;
        } else {
            f = (f + 1) % MAX;
        }
    }
}

void display() {
    int i;
    if (f == -1) {
        printf("cq underflow\n");
    } else {
        printf("Circular Queue elements are: ");
        if (f <= r) {
            for (i = f; i <= r; i++) {
                printf("%d ", cq[i]);
            }
        } else {
            for (i = f; i < MAX-1; i++) {
                printf("%d ", cq[i]);
            }
            for (i = 0; i <= r; i++) {
                printf("%d ", cq[i]);
            }
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: insert(); break;
            case 2: deletion(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
    return 0;
}

