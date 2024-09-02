#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *f = NULL;
struct node *r = NULL;

void Traversal(struct node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data); //data appoint
        head = head->next;//traversal
    }
}
void enqueue(int value)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("queue is full");
    }
    else
    {
        ptr->data = value;

        if (f == NULL)
        {
            f = r = ptr;
        }
        else
        {
            r->next = ptr;
            ptr->next = NULL;
            r = ptr;
        }
    }
}

int dequeue()
{
    int a = -1;
    if (f == NULL)
    {
        printf("Queue empty");
    }
    else
    {
        struct node *ptr = f;
        a = ptr->data;
        f = f->next;
        // return a;
        free(ptr); 
    }
    return a;
}
int main()
{
    enqueue(2);
    enqueue(9);
    enqueue(4);

    Traversal(f);
    printf("dequeing %d\n", dequeue());
    printf("dequeing %d\n", dequeue());
    printf("dequeing %d\n", dequeue());
    printf("dequeing %d\n", dequeue());
    
}
