#include<stdio.h>
#include<stdlib.h>
#define MAX 4

int stack_arr[MAX];
int top = -1;     // stack is empty

int isfull()
{
    if(top == MAX - 1)
        return 1;
    else
        return 0;   
}

int isempty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}

void push(int data)
{
    if(isfull())
    {
        printf("stack overflow occured");
        return;
    }
    top = top + 1;
    stack_arr[top] = data;
}

int pop()
{
    if(isempty())
    {
        printf("stack underflow");
        exit(1);
    }
    int value;
    value = stack_arr[top];
    printf("the value deleted is %d ", value);
    top = top-1;
}

int peek()
{
    if(isempty())
    {
        printf("stack underflow\n");
        exit(1);
    }
    return stack_arr[top];
}

void display()
{
    int i;
    if(isempty())
    {
        printf("stack underflow\n");
        return;
    }
    for(i = 0; i<=top; i++)
    {
        printf("%d->", stack_arr[i]);
    }
    printf("NULL");
}

int main()
{
    int choice, data;  // the element which is deleted is stored in the data as we are keep track of the deleted element
    while(1) //while(1) means loop will execute infintely
    {
        printf("\n");
        printf("1.push\n");
        printf("2.pop\n");
        printf("3.print the top element\n");
        printf("4. print all the elements of the stack\n");
        printf("5. quit\n");
        printf("please enter your choice\n");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("enter the element to be pushed: ");
                scanf("%d", &data);
                push(data);
                break;

            case 2:
                data = pop();
                printf("the deleted element is %d ", data);
                break;

            case 3:
                printf("the topmost element of the stack is %d\n", peek());
                break;
            
            case 4:
                display();
                break;
            
            case 5:
                exit(1);

            default:
                printf("wrong choice\n");
        }

    }

    return 0;
    // push(10);
    // push(20);
    // push(30);
    // push(40);  //now the stack is full because the capacity of the stack is 4, so we cant push the item
    // pop();
}