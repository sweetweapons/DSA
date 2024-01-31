#include<stdio.h>
#include<stdlib.h>

#define N 5

int queue[N];
int front = -1;
int rear = -1;

void enqueue(int x)
{
    if (rear == N - 1)
    {
        printf("Queue is full\n");
    }
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = x;
    }
    else
    {
        rear = (rear + 1) % N; // Corrected this line
        queue[rear] = x;
    }
}

void dequeue()
{
    if (front == -1 && rear == -1)
    {
        printf("The queue is empty and cannot dequeue any elements\n");
    }
    else if (front == rear)
    {
        printf("There is only one item and that is %d\n", queue[front]);
        front = rear = -1;
    }
    else
    {
        printf("The dequeued element is %d\n", queue[front]);
        front = (front + 1) % N; // Corrected this line
    }
}

void display()
{
    int i;
    if (front == -1 && rear == -1)
        printf("The queue is empty\n");

    else
    {
        for (i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void peek()
{
    if (front == -1 && rear == -1)
    {
        printf("The queue is empty\n");
    }
    else
    {
        printf("The data at the front is %d\n", queue[front]);
    }
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    printf("Queue after enqueuing elements: \n");
    display();

    peek();

    dequeue();
    dequeue();
    dequeue();

    printf("\nQueue after dequeuing elements: \n");
    display();

    return 0;
}
