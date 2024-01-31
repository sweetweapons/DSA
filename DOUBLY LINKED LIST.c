#include<stdio.h>
#include<stdlib.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};

struct node* add_to_empty_list(struct node* head, int data) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data= data;
    temp->next=NULL;
    head=temp;
    return head;
}

struct node* createNode(int data) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Insufficient memory\n");
        exit(EXIT_FAILURE);
    }
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* add_at_beg(struct node* head, int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = head;
    if (head != NULL) 
    {
        head->prev = temp;
    }
    head = temp; // Update head to point to the new node
    return head;
}

struct node* add_at_end(struct node* head, int data) 
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->next = NULL;
    temp->prev = NULL;
    temp->data = data;
    if (head == NULL)
    {
        head = temp; // If the list is empty, the new node becomes the head
        return head;
    }
    struct node* ptr;
    ptr = head;
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    return head;
}

struct node* add_at_specific_pos(struct node* head, int data, int pos)
{
    struct node* ptr= head;
    struct node* ptr2 = createNode(data);

    if (ptr2 == NULL)
    {
        printf("failed to create a new node\n");
        return head;
    }

    //else traversing to the position-1 node
    for(int i=1; i<pos-1; i++ && ptr != NULL)
    {
        ptr = ptr->next;
    }

    // Check if the position is valid
    if (ptr == NULL) {
        printf("Invalid position\n");
        free(ptr2); // Free the allocated memory for the new node
        return;
    }

    // Insert the new node at the specified position
    ptr2->next = ptr->next;
    ptr2 = ptr->next->prev;
    ptr->next = ptr2;
    ptr->next = ptr2;
    ptr2->prev = ptr;    
}

struct node* display(struct node* head)
{
    struct node* ptr;
    ptr=head;
    while(ptr != NULL)
    {
        printf("%d->",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

int main() {
    struct node* head= NULL;
    struct node* ptr;

    //add to empty 
    head = add_to_empty_list(head,45);

    //add at begining
    head = add_at_beg(head, 12);

    head = add_at_end(head, 41);

    head = add_at_specific_pos(head, 99, 1);

    head = display(head);
}