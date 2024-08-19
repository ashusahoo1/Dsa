#include <stdio.h>
#define MAX 10

int f = -1, r = -1;
int q[MAX];


void insert() {
    int x;
    if (r == MAX - 1) {
        printf("Queue overflow\n");
    } else {
        printf("Enter the value: ");
        scanf("%d", &x);
        if (f == -1) {
            f = 0;
        }
        r++;
        q[r] = x;
        printf("Inserted %d\n", x);
    }
}


void delete() {
    if (f == -1) {
        printf("Queue underflow\n");
    } else {
        printf("Deleted %d\n", q[f]);
        if (f == r) {
            f = -1;
            r = -1;
        } else {
            f++;
        }
    }
}


void display() {
    int i;
    if (f == -1) {
        printf("Queue is empty\n");
    } else {
        printf("Existing elements in the queue are:\n");
        for (i = f; i <= r; i++) {
            printf("%d ", q[i]);
        }
        printf("\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insert();
                break;
            case 2:
                delete();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
}
