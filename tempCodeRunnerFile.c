#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

struct node* addtoempty(int data)
{
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

struct node* addAtBeg(struct node* tail, int data)
{
    struct node* newP = malloc(sizeof(struct node));
    newP->data = data;
    newP->next = tail->next;
    return tail;
}

void print(struct node)