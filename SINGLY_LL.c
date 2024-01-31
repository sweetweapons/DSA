#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *createNode(int data)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
    {
        printf("insufficient memory");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void display(struct node *head)
{
    if (head == NULL)
    {
        printf("The list is empty\n");
        return;
    }

    struct node *temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

struct node *insertAtEnd(struct node *head, int data)
{
    struct node *temp = createNode(data); // temp is the newnode that is created to add
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        struct node *current = head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = temp;
    }
    return head;
}

struct node *insertAtBeg(struct node *head, int data)
{
    struct node *temp = createNode(data);
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        temp->next = head;
        head = temp;
    }
    return head;
}

struct node *insertInBetween(struct node *head, int data, int pos)
{
    struct node *ptr = head;               // this is a pointer as a counter
    struct node *ptr2 = createNode(data); // new node which has to be added in between

    if (ptr2 == NULL)
    {
        printf("insertion in between failed\n");
        exit(EXIT_FAILURE);
    }
    if (pos < 0)
    {
        printf("Invalid position\n");
        free(ptr2);
        return head;
    }

    if (pos == 0)
    {
        ptr2->next = head;
        head = ptr2;
        return head;
    }

    //traversing the linked list to pos-1
    for (int i = 0; i < pos - 1 && ptr != NULL; i++)
    {
        ptr = ptr->next;
    }
    // Check if the position is valid
    if (ptr == NULL)
    {
        printf("Invalid position\n");
        free(ptr2); // Free the allocated memory for the new node
        return head;
    }

    //insert new node at the specific position
    ptr2->next = ptr->next;
    ptr->next = ptr2;

    return head;
}

struct node *del_at_first(struct node *head)
{
    if (head == NULL)
    {
        printf("deletion not possible\n");
        return head;
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        printf("The deleted value at the 1st position is %d\n", temp->data);
        return head;
    }
}

struct node* del_at_end(struct node *head) 
{
    if (head == NULL)
        printf("there are no nodes to delete at the end\n");
    else if (head->next == NULL) {
        free(head);
        head = NULL;
    } else {
        struct node *temp = head;
        struct node *temp2 = head;
        while (temp->next != NULL) {
            temp2 = temp;
            temp = temp->next;
        }
        temp2->next = NULL;
        free(temp);
    }
    return head;

}


void freeList(struct node *head)
{
    struct node *temp;
    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main()
{
    int pos, choice, data;
    struct node *head = NULL;
    do {
        printf("\nLinked List Operations\n");
        printf("1. Insert at the begining\n");
        printf("2. insert at the end\n");
        printf("3. Delete at first\n");
        printf("4. Delete at end\n");
        printf("5. Insert at a specific position\n");
        printf("6. Display\n");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("enter the data to be inserted at begining");
            scanf("%d",&data);
            head = insertAtBeg(head, data);
            display(head);
            break;

        case 2:
            printf("enter the data to be inserted at the end");
            scanf("%d",&data);
            head = insertAtEnd(head, data);
            display(head);
            break;

        case 3:
            head = del_at_first(head);
            display(head);
            break;

        case 4:
            head = del_at_end(head);
            display(head);
            break;

        case 5:
            printf("enter the position where the data is to be added");
            scanf("%d",&pos);
            head = createNode(data);
            printf("enter the data to be inserted at that position");
            head = insertInBetween(head, data, pos);
            display(head);
            break;

        case 6:
            display(head);
            break;
        
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }while (choice!=6);

    return 0;
}
