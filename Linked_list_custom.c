//traversal in linked list

#include<stdio.h>
#include<stdlib.h>

struct node   //creating a data type 
{
    int data;
    struct node* next; //pointer to a struct node data type

};

void listtraversal (struct node *head){
    int i=1;
    while (head!=NULL)
    {
        printf("element %d is: %d \n",i, head->data);
        head= head->next;
        i++;
    }
    
}


int main(){
    struct node* head=(struct node*) malloc(sizeof(struct node)); //creating pointer of struct node data type
    struct node *second=(struct node*) malloc(sizeof(struct node));
    struct node *third=(struct node*) malloc(sizeof(struct node));

    head->data=4; // (*head).data
    head->next= second;
    
    second->data=5;
    second->next= third;

    third->data=6;
    third->next= NULL;

    listtraversal(head);

    return 0;
}
