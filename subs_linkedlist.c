/*Q2 (b): Subtract Two Numbers Represented as Linked Lists*/
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to insert a node at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* node = newNode(data);
    if (*head == NULL) {
        *head = node;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

// Function to subtract two linked lists and store the result in a third linked list
struct Node* subtractLinkedLists(struct Node* l1, struct Node* l2) {
    struct Node* result = NULL;
    int borrow = 0;

    while (l1 != NULL || l2 != NULL) {
        int v1 = (l1 != NULL) ? l1->data : 0;
        int v2 = (l2 != NULL) ? l2->data : 0;

        int diff = v1 - v2 - borrow;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }

        insertAtEnd(&result, diff);

        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }

    return result;
}

// Function to print a linked list
void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* l1 = NULL;
    struct Node* l2 = NULL;

    insertAtEnd(&l1, 9);
    insertAtEnd(&l1, 8);
    insertAtEnd(&l1, 7);

    insertAtEnd(&l2, 4);
    insertAtEnd(&l2, 5);
    insertAtEnd(&l2, 6);

    printf("First List: ");
    printList(l1);

    printf("Second List: ");
    printList(l2);

    struct Node* result = subtractLinkedLists(l1, l2);

    printf("Resultant List: ");
    printList(result);

    return 0;
}
