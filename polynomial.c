#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define the structure for a polynomial term node
typedef struct Node {
    int coeff;              // Coefficient of the term
    int x_exp;              // Exponent of x
    int y_exp;              // Exponent of y
    int z_exp;              // Exponent of z
    struct Node* next;      // Pointer to the next term
} Node;

// Function to create a new polynomial term node
Node* createNode(int coeff, int x_exp, int y_exp, int z_exp) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    newNode->coeff = coeff;
    newNode->x_exp = x_exp;
    newNode->y_exp = y_exp;
    newNode->z_exp = z_exp;
    newNode->next = NULL;
    return newNode;
}

// Function to print the polynomial
void printPolynomial(Node* head) {
    if (head == NULL) {
        printf("Polynomial is empty.\n");
        return;
    }

    Node* current = head;
    while (current != NULL) {
        // Handle sign
        if (current->coeff > 0 && current != head)
            printf(" + ");
        else if (current->coeff < 0)
            printf(" - ");

        // Print absolute value of coefficient if necessary
        int abs_coeff = abs(current->coeff);
        int need_coeff = (abs_coeff != 1) || (current->x_exp == 0 && current->y_exp == 0 && current->z_exp == 0);
        if (need_coeff)
            printf("%d", abs_coeff);

        // Print variables and their exponents
        if (current->x_exp != 0) {
            printf("x");
            if (current->x_exp > 1)
                printf("^%d", current->x_exp);
        }
        if (current->y_exp != 0) {
            printf("y");
            if (current->y_exp > 1)
                printf("^%d", current->y_exp);
        }
        if (current->z_exp != 0) {
            printf("z");
            if (current->z_exp > 1)
                printf("^%d", current->z_exp);
        }

        current = current->next;
    }
    printf("\n");
}

// Function to free the polynomial linked list
void freePolynomial(Node* head) {
    Node* current = head;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    // Create terms of the polynomial
    Node* head = createNode(2, 1, 2, 3);               // 2xy^2z^3
    head->next = createNode(3, 2, 1, 2);               // +3x^2yz^2
    head->next->next = createNode(-4, 1, 3, 1);        // -4xy^3z
    head->next->next->next = createNode(5, 2, 2, 0);   // +5x^2y^2
    head->next->next->next->next = createNode(7, 1, 2, 5); // +7xy^2z^5
    head->next->next->next->next->next = createNode(11, 0, 0, 0); // +11

    // Print the polynomial
    printf("The polynomial is:\n");
    printPolynomial(head);

    // Free allocated memory
    freePolynomial(head);

    return 0;
}
