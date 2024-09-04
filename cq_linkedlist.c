#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node *next;
};

// Front and rear pointers for the circular queue
struct Node *f = NULL;
struct Node *r = NULL;

// Function to insert an element into the circular queue
void insert() {
    struct Node *newNode;
    int x;
    
    printf("Enter a value: ");
    scanf("%d", &x);
    
    newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    
    newNode->data = x;
    newNode->next = NULL;
    
    if (f == NULL) {
        // If the queue is empty
        f = newNode;
        r = newNode;
        r->next = f; // Make it circular
    } else {
        r->next = newNode;
        r = newNode;
        r->next = f; // Maintain circular nature
    }
}

// Function to delete an element from the circular queue
void deletion() {
    struct Node *temp;
    
    if (f == NULL) {
        printf("cq underflow\n");
    } else {
        temp = f;
        printf("The deleted element is %d\n", f->data);
        
        if (f == r) {
            // If there's only one node in the queue
            f = NULL;
            r = NULL;
        } else {
            f = f->next;
            r->next = f; // Maintain circular nature
        }
        free(temp);
    }
}

// Function to display elements of the circular queue
void display() {
    struct Node *temp;
    
    if (f == NULL) {
        printf("cq underflow\n");
    } else {
        temp = f;
        printf("Circular Queue elements are: ");
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != f);
        printf("\n");
    }
}

// Main function
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
