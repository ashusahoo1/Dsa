#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (node != NULL) {
        node->data = data;
        node->next = NULL;
    }
    return node;
}

struct Node* insertSorted(struct Node* head, int data) {
    struct Node* new = newNode(data);
    if (new == NULL) {
        printf("Memory allocation failed!\n");
        return head;
    }

    if (head == NULL || data <= head->data) {
        new->next = head;
        return new;
    }

    struct Node* current = head;
    while (current->next != NULL && current->next->data < data) {
        current = current->next;
    }

    new->next = current->next;
    current->next = new;
    return head;
}

void display(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;

    head = insertSorted(head, 5);
    head = insertSorted(head, 3);
    head = insertSorted(head, 8);
    head = insertSorted(head, 1);
    head = insertSorted(head, 6);

    printf("Sorted Linked List: ");
    display(head);

    // Free allocated memory
    freeList(head);

    return 0;
}
