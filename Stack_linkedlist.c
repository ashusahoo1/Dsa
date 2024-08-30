#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

int isempty(struct node *top)
{
    return top == NULL;
}

void listtraversal(struct node *head)
{
    int i = 1;
    while (head != NULL)
    {
        printf("element %d is: %d \n", i, head->data);
        head = head->next;
        i++;
    }
}

int isfull()
{
    struct node *n = (struct node *)malloc(sizeof(struct node));
    if (n == NULL)
    {
        return 1;
    }
    else
    {
        free(n);  // Free allocated memory to avoid memory leak
        return 0;
    }
}

// `top` is the head of the stack
struct node *push(struct node *top, int x)
{
    if (isfull())
    {
        printf("stack overflow\n");
        return top;
    }
    else
    {
        struct node *p = (struct node *)malloc(sizeof(struct node));
        p->data = x;
        p->next = top;
        top = p;
        return top;
    }
}

struct node *pop(struct node *top)
{
    if (isempty(top))
    {
        printf("stack underflow\n");
        return top;
    }
    else
    {
        struct node *p = top;
        top = top->next;
        free(p);
        return top;
    }
}

int peek(struct node *top, int position)
{
    struct node *ptr = top;
    for (int i = 0; (i < position - 1 && ptr != NULL); i++)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        return ptr->data;
    }
    else
    {
        return -1;  // Invalid position
    }
}

int main()
{
    struct node *top = NULL; // Here, top is the head of the linked list, initially 0 elements in the list
    top = push(top, 18);
    top = push(top, 19);
    top = push(top, 20); // This is added at the top of the stack and at the start of the linked list

    // listtraversal(top);

    // Pop the top element
    top = pop(top);
    listtraversal(top);

    for (int i = 1; i <= 3; i++)
    {
        int value = peek(top, i);
        if (value != -1)
        {
            printf("The value at position %d is %d\n", i, value);
        }
        else
        {
            printf("Invalid position %d\n", i);
        }
    }

    return 0;
}
