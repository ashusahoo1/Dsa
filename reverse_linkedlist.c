#include <stdio.h>
#include <stdlib.h>

// Define the structure for the node
struct node {
    int data;
    struct node* next;
};

// Function to traverse and print the linked list
void listtraversal(struct node *a) {
    while (a != NULL) {
        printf(" %d", a->data);
        a = a->next;
    }
    printf("\n");
}

// Function to insert a new node at the start of the list
struct node* insertatstart(struct node *headnode, int data) {
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = headnode;
    return ptr;
}

// Function to reverse the linked list
struct node* reverseList(struct node* head) {
    struct node* prev = NULL;
    struct node* current = head;
    struct node* next = NULL;
    
    while (current != NULL) {
        // Store the next node
        next = current->next;
        // Reverse the current node's pointer
        current->next = prev;
        // Move pointers one position ahead
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}

int main() {
    struct node* head = NULL;
    
    // Insert some nodes
    head = insertatstart(head, 10);
    head = insertatstart(head, 20);
    head = insertatstart(head, 30);
    head = insertatstart(head, 40);
    
    // Print the original list
    printf("Original List:\n");
    listtraversal(head);
    
    // Reverse the list
    head = reverseList(head);
    
    // Print the reversed list
    printf("Reversed List:\n");
    listtraversal(head);
    
    return 0;
}
