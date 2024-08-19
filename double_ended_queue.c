// double ended queue implementation


#include <stdio.h>
#include <stdlib.h>

#define MAX 10
int left = -1, right = -1;
int dq[MAX];

void input_right() {
    int x;
    if ((left == 0 && right == MAX - 1) || (left == right + 1)) {
        printf("Deque overflow\n");
    } else {
        printf("Enter the value: ");
        scanf("%d", &x);
        if (left == -1) { // If the deque is initially empty
            left = 0;
            right = 0;
        } else if (right == MAX - 1) { // Circular increment
            right = 0;
        } else {
            right++;
        }
        dq[right] = x;
    }
}

void input_left() {
    int x;
    if ((left == 0 && right == MAX - 1) || (left == right + 1)) {
        printf("Deque overflow\n");
    } else {
        printf("Enter the value: ");
        scanf("%d", &x);
        if (left == -1) { // If the deque is initially empty
            left = 0;
            right = 0;
        } else if (left == 0) { // Circular decrement
            left = MAX - 1;
        } else {
            left--;
        }
        dq[left] = x;
    }
}

void deletion_left() {
    if (left == -1) {
        printf("Deque underflow\n");
    } else {
        printf("The deleted element is %d\n", dq[left]);
        if (left == right) { // Deque has only one element
            left = -1;
            right = -1;
        } else if (left == MAX - 1) {
            left = 0; // Circular increment
        } else {
            left++;
        }
    }
}

void deletion_right() {
    if (left == -1) {
        printf("Deque underflow\n");
    } else {
        printf("The deleted element is %d\n", dq[right]);
        if (left == right) { // Deque has only one element
            left = -1;
            right = -1;
        } else if (right == 0) {
            right = MAX - 1; // Circular decrement
        } else {
            right--;
        }
    }
}

void display() {
    if (left == -1) {
        printf("Deque is empty\n");
        return;
    }
    
    printf("Deque elements: ");
    
    int i = left;
    while (1) {
        printf("%d ", dq[i]);
        if (i == right) {
            break;
        }
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void input_restricted() {
    while (1) {
        int ch;
        printf("\n1. Insert at right\n");
        printf("2. Delete at left\n");
        printf("3. Delete at right\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                input_right();
                break;
            case 2:
                deletion_left();
                break;
            case 3:
                deletion_right();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
}

void output_restricted() {
    while (1) {
        int ch;
        printf("\n1. Insert at right\n");
        printf("2. Insert at left\n");
        printf("3. Delete at left\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                input_right();
                break;
            case 2:
                input_left();
                break;
            case 3:
                deletion_left();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Wrong choice\n");
        }
    }
}

int main() {
    int choice;
    printf("Deque Operations\n");
    printf("1. Input Restricted Deque\n");
    printf("2. Output Restricted Deque\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            input_restricted();
            break;
        case 2:
            output_restricted();
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}
