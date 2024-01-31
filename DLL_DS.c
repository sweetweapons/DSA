#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Insufficient memory\n");
        exit(EXIT_FAILURE);
    }
    newNode->prev = NULL;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

struct node* add_to_empty_list(int data) {
    return createNode(data);
}

struct node* add_at_beg(struct node* head, int data) {
    struct node* temp = createNode(data);
    temp->next = head;
    if (head != NULL) {
        head->prev = temp;
    }
    return temp;
}

struct node* add_at_end(struct node* head, int data) {
    struct node* temp = createNode(data);
    if (head == NULL) {
        return temp;
    }
    struct node* ptr = head;
    while (ptr->next != NULL) {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
    return head;
}

struct node* add_at_specific_pos(struct node* head, int data, int pos) {
    if (pos == 0) {
        return add_at_beg(head, data);
    }

    struct node* ptr = head;
    struct node* ptr2 = createNode(data);

    if (ptr2 == NULL) {
        printf("Failed to create a new node\n");
        return head;
    }

    for (int i = 1; i < pos - 1 && ptr != NULL; i++) {
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Invalid position\n");
        free(ptr2);
        return head;
    }

    ptr2->next = ptr->next;
    if (ptr->next != NULL) {
        ptr->next->prev = ptr2;
    }
    ptr->next = ptr2;
    ptr2->prev = ptr;

    return head;
}

struct node* del_at_first(struct node* head) {
    if (head == NULL) {
        printf("There are no nodes to delete at first\n");
        return NULL;
    }
    struct node* temp = head;
    head = head->next;
    free(temp);
    if (head != NULL) {
        head->prev = NULL;
    }
    return head;
}

struct node* del_at_end(struct node* head) {
    if (head == NULL) {
        printf("There are no nodes to be deleted\n");
        return NULL;
    }
    struct node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        // Only one node in the list
        free(temp);
        return NULL;
    }
    free(temp);
    return head;
}

struct node* del_at_specific_pos(struct node* head, int pos) {
    if (pos == 1) {
        return del_at_first(head);
    }

    struct node* temp = head;
    for (int i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position\n");
        return head;
    }

    if (temp->next == NULL) {
        // Deleting the last node
        return del_at_end(head);
    }

    struct node* temp2 = temp->prev;
    temp2->next = temp->next;
    temp->next->prev = temp2;
    free(temp);

    return head;
}

void display(struct node* head) {
    struct node* ptr = head;
    while (ptr != NULL) {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;
    int pos;

    // Add to an empty list
    head = add_to_empty_list(45);

    // Add at the beginning
    head = add_at_beg(head, 12);

    // Add at the end
    head = add_at_end(head, 41);

    printf("Add the position where you need to insert the node: ");
    scanf("%d", &pos);

    // Add at a specific position
    head = add_at_specific_pos(head, 99, pos);

    printf("The original list before deletion at first:\n");
    display(head);

    // Delete at the first position
    head = del_at_first(head);
    printf("The original list after deletion at first:\n");
    display(head);

    // Delete at the end
    printf("The original list after deletion at last:\n");
    head = del_at_end(head);
    display(head);

    printf("Enter the position where you want to delete: ");
    scanf("%d", &pos);

    printf("The node before deletion of the position node:\n");
    display(head);

    // Delete at a specific position
    head = del_at_specific_pos(head, pos);

    printf("The node after deletion at a particular position:\n");
    display(head);

    return 0;
}
