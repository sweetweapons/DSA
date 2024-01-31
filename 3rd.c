#include<stdio.h>
#include<stdlib.h>

// Structure for a node in the linked list
struct node {
    int data;
    struct node *next;
};

// Function to create a new node with the given data
struct node* getnode(int info) 
{
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL)
        printf("Insufficient memory\n");
    else {
        newNode->data = info;
        newNode->next = NULL;
    }
    return newNode;
}


// Function to display the nodes in the linked list
void display_nodes(struct node *head) 
{
    if (head == NULL)
        printf("The linked list is empty\n");
    else {
        struct node *ptr = head;
        while (ptr != NULL) {
            printf("%d->", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

// Function to count the number of nodes in the linked list
void count_no_of_nodes(struct node *head) 
{
    int count = 0;
    struct node *ptr = head;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }
    printf("The count is %d\n", count);
}

// Function to add a new node at the end of the linked list
void add_at_end(struct node *head, int data) 

{
    struct node *ptr, *temp;
    ptr = head;
    temp = (struct node *)malloc(sizeof(struct node));

    if (temp == NULL) {
        printf("Insufficient memory\n");
        return;
    }

    temp->data = data;
    temp->next = NULL;

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

// Function to add a new node at the beginning of the linked list
void add_at_beg(struct node **head, int data) 
{
    struct node *ptr = malloc(sizeof(struct node));
    if (ptr == NULL) {
        printf("Insufficient memory\n");
        return;
    }

    ptr->data = data;
    ptr->next = *head;
    *head = ptr;
}

// Function to add a new node at a specific position in the linked list
void add_at_specific_pos(struct node *head, int data, int pos) {
    struct node *ptr = head;
    struct node *ptr2 = getnode(data);

    if (ptr2 == NULL) {
        printf("Failed to create a new node\n");
        return;
    }

    // Traversing to position-1 node
    for (int i = 1; i < pos - 1 && ptr != NULL; i++) {
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
    ptr->next = ptr2;
}

int main() {
    struct node *head = NULL;
    int choice, data, position;

    do {
        printf("\nMenu:\n");
        printf("1. Display the linked list\n");
        printf("2. Count the number of nodes\n");
        printf("3. Add a node at the end\n");
        printf("4. Add a node at the beginning\n");
        printf("5. Add a node at a specific position\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_nodes(head);
                break;
            case 2:
                count_no_of_nodes(head);
                break;
            case 3:
                printf("Enter the data to add at the end: ");
                scanf("%d", &data);
                add_at_end(head, data);
                break;
            case 4:
                printf("Enter the data to add at the beginning: ");
                scanf("%d", &data);
                add_at_beg(&head, data);
                break;
            case 5:
                printf("Enter the data to add: ");
                scanf("%d", &data);
                printf("Enter the position to add at: ");
                scanf("%d", &position);
                add_at_specific_pos(head, data, position);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
