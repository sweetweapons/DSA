#include<stdio.h>
#include<stdlib.h>
#define STACKSIZE 100

struct stack  
{
    int top;
    int items[STACKSIZE];
};

int pop(struct stack *ps)
{
    if(empty(ps))
    {
        printf("stack underflow");
        exit(1);
    }
    return(ps->items[ps->top --]);
}

void push(struct stack *ps, int x)
{
    if(ps->top == STACKSIZE - 1)
    {
        printf("STACK OVERFLOW");
        exit(1);
    }
    else
    ps->items[++(ps->top)] = x;
    return;
}

int peek(struct stack *ps)
{
    if(empty(ps))
    {
        printf("stack underflow");
        exit(1);
    }
    return(ps->items[ps->top]);
}

int empty(struct stack *ps)
{
    return (ps->top == -1);
}

void display(struct stack *ps)
{
    if (empty(ps))
    {
        printf("Stack is empty\n");
        return;
    }

    printf("Stack elements: ");
    for (int i = 0; i <= ps->top; ++i)
    {
        printf("%d ", ps->items[i]);
    }
    printf("\n");
}

int main()
{
    struct stack s;
    s.top = -1; // Initialize stack top

    int choice, element;

    while (1)
    {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Exit\n");
        printf("5. Display");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &element);
            push(&s, element);
            break;

        case 2:
            printf("Popped element: %d\n", pop(&s));
            break;

        case 3:
            printf("Peeked element: %d\n", peek(&s));
            break;

        case 4:
            printf("Exiting program\n");
            exit(0);

        case 5:
            display(&s);
            break;
            

        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}