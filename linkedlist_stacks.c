#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
} *top = NULL;

void push(int data)
{
    struct node* newnode;
    newnode = malloc(sizeof(newnode));
    //checking if memory cant be allocated for some reason
    if(newnode == NULL)
    {
        printf("stack overflow");
        exit(1);
    }
    newnode->data = data;
    newnode->next = NULL;

    newnode->next = top;
    top = newnode;
}

void display()
{
    struct node* temp;
    temp = top;
    printf("the stack elements are: ");
    while(temp != NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int choice, data;
    while(1)
    {
        printf("1. push\n");
        printf("2. print\n");
        printf("3. quit\n");
        printf("enter your choice\n");
        scanf("%d", &choice);

        switch(choice)
        {
        case 1:
        printf("enter the element to be pushed: ");
        scanf("%d", &data);
        push(data);
        break;

        case 2:
        display();
        break;

        case 3:
        exit(1);
        default:
        printf("wrong choice\n");
        break;
        }
    }
    return 0;
}