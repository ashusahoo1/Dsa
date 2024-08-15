#include <stdio.h>
#define MAX 10
int top = -1;
int stack[MAX];

void push()
{
    int x;
    if (top == MAX - 1)
    {
        printf("stack overflow\n");
    }
    else
    {
        printf("enter the value\n");
        scanf("%d", &x);
        top = top + 1;
        stack[top] = x;
    }
}

void pop()
{
    if (top == -1)
    {
        printf("stack underflow\n");
    }
    else
    {
        printf("pop element\n");
        stack[top];
        top = top - 1; // stack ke bahar
    }
}
void display()
{
    int i;
    if (top == -1)
    {
        printf("stack underflow\n");
    }
    else
    {
        for (i = top; i >= 0; i--)
        {
            printf("existng elemets are\n");
            printf("%d", stack[i]);
        }
    }
}
int main()
{
    push();
    push();
    pop();
    display();
}
