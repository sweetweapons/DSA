#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node* getnode(int info) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("insufficient memory\n");
    } else {
        newNode->data = info;
        newNode->next = NULL;
    }
    return newNode;
}

void count_no_of_nodes(struct node *head) {
    int count = 0;
    if (head == NULL) 
        printf("the linked list is empty\n");
    else {
        struct node *ptr = head;
        while (ptr != NULL) { 
            count++;
            ptr = ptr->next;
        }
        printf("the count is %d\n", count);
    }
}

void display_nodes(struct node *head) {
    if (head == NULL) 
        printf("the linked list is empty\n");
    else {
        struct node *ptr = head;
        while (ptr != NULL) {
            printf("%d->", ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
}

void add_at_end(struct node *head, int data) {
    struct node *ptr = head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    
    temp->data = data;
    temp->next = NULL;

    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
}

void add_at_beg(struct node **head, int data) {
    struct node *ptr = malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = *head;
    *head = ptr;
}

void add_at_specific_pos(struct node *head, int data, int pos) {
    struct node *ptr = head;
    struct node *ptr2 = getnode(data);

    if (ptr2 ==  NULL) {
        printf("failed to create a new node\n");
        return; 
    }

    // traversing to position-1 node
    for (int i = 1; i < pos-1 && ptr != NULL; i++) {
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

struct node* del_at_first(struct node *head) {
    if (head == NULL)
        printf("the list is already empty!\n");
    else {
        struct node *temp = head;
        head = head->next;
        printf("the deleted item is %d\n", temp->data);
        free(temp);
    }
    return head;
}

struct node* del_at_end(struct node *head) {
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

void del_at_pos(struct node **head, int position) {
    struct node *ptr = *head;
    struct node *prevptr = NULL;

    if (*head == NULL) {
        printf("The list is already empty.\n");
        return;
    }

    if (position == 1) {
        *head = ptr->next;
        free(ptr);
        printf("Node at position 1 deleted successfully.\n");
        return;
    }

    int current_pos = 1;
    while (ptr != NULL && current_pos != position) {
        prevptr = ptr;
        ptr = ptr->next;
        current_pos++;
    }

    if (ptr == NULL) {
        printf("Invalid position to delete.\n");
        return;
    }

    // Node ptr is the node to be deleted
    prevptr->next = ptr->next;
    free(ptr);

    printf("Node at position %d deleted successfully.\n", position);
}

struct node* del_whole_list(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        struct node *nextnode = temp->next;
        free(temp);
        temp = nextnode;
    }
    return NULL;
}

void freeList(struct node *head) {
    struct node *current = head;
    struct node *next;

    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
}

int main() {
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->next = NULL;

    struct node *current = (struct node *)malloc(sizeof(struct node));
    current->data = 50;
    current->next = NULL;
    head->next = current;

    struct node *current1 = (struct node *)malloc(sizeof(struct node));
    current1->data = 55;
    current1->next = NULL;
    current->next = current1;

    printf("linked list before insertion\n");

    display_nodes(head);
    count_no_of_nodes(head);

    add_at_end(head, 85);

    printf("linked list after insertion at end \n");
    display_nodes(head);
    count_no_of_nodes(head);

    printf("linked list after insertion at beginning \n");
    add_at_beg(&head, 99);
    display_nodes(head);
    count_no_of_nodes(head);

    printf("linked list after at position 1 \n");
    add_at_specific_pos(head, 100, 1);
    display_nodes(head);
    count_no_of_nodes(head);

    printf("linked list after at position 3 \n");
    add_at_specific_pos(head, 200, 3);
    display_nodes(head);
    count_no_of_nodes(head);

    head =  del_at_first(head);
    count_no_of_nodes(head);
    display_nodes(head);

    printf("Linked list after deleting at the end\n");
    display_nodes(head);
    head = del_at_end(head);
    count_no_of_nodes(head);
    display_nodes(head);

    int position;
    printf("Enter the position to be deleted: ");
    scanf("%d", &position);
    del_at_pos(&head, position);
    display_nodes(head);
    count_no_of_nodes(head);

    printf("Before deleting the whole linked list\n");
    display_nodes(head);
    count_no_of_nodes(head);
    head = del_whole_list(head);
    printf("The whole linked list is empty\n");

    // Free the entire linked list before returning
    //freeList(head);

    return 0;
}
