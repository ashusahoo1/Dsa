#include <stdio.h>
#include <stdlib.h>

// Define a structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Define a structure for the stack
struct Stack {
    struct Node* top;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the stack
void initStack(struct Stack* stack) {
    stack->top = NULL;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    if (!newNode) {
        return;
    }
    if (isEmpty(stack)) {
        stack->top = newNode;
    } else {
        newNode->prev = stack->top;
        stack->top->next = newNode;
        stack->top = newNode;
    }
    printf("Pushed %d onto the stack.\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = stack->top->prev;
    if (stack->top) {
        stack->top->next = NULL;
    }
    free(temp);
    printf("Popped %d from the stack.\n", data);
    return data;
}

// Function to display the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* current = stack->top;
    printf("Stack: ");
    while (current) {
        printf("%d ", current->data);
        current = current->prev;
    }
    printf("\n");
}

// Main function to test the stack implementation
int main() {
    struct Stack stack;
    initStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    display(&stack);

    pop(&stack);
    display(&stack);

    pop(&stack);
    display(&stack);

    pop(&stack);
    display(&stack);

    return 0;
}
