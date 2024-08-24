#include <stdio.h>
#include <stdlib.h>

struct node {
    int val;
    struct node* next;
};

struct node* head = NULL;
struct node* last = NULL;

// Function prototypes
void create(int x);
void display();

int main() {
    int m, n, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the values of nodes:\n");
    for(i = 0; i < n; i++) {
        printf("Enter the value of node %d: ", i+1);
        scanf("%d", &m);
        create(m);
        display();
        printf("\n"); // New line for better output formatting
    }
    return 0;
}

void create(int x) {
    struct node* tmp; // Corrected type to struct node*
    tmp = (struct node*)malloc(sizeof(struct node));
    tmp->val = x;
    tmp->next = NULL;

    if(head == NULL) {
        head = tmp;
        last = tmp;
    } else {
        last->next = tmp;
        last = tmp;
    }
}

void display() {
    struct node* p = head;
    if(head == NULL) {
        printf("Empty linked list");
    } else {
        while(p != NULL) {
            printf("%d->", p->val);
            p = p->next;
        }
    }
}
