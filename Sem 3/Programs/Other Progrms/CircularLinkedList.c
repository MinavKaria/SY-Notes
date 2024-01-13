#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node *next;
};

void insert(struct node **head, int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;

    if (*head == NULL) {
        newNode->next = newNode;
        *head = newNode;
    } else {
        struct node *tail = *head;
        while (tail->next != *head) {
            tail = tail->next;
        }
        newNode->next = *head;
        tail->next = newNode;
    }
}

void delete(struct node **head, int data) {
    if (*head == NULL) {
        printf("The list is empty\n");
        return;
    }

    struct node *current = *head, *prev = NULL;

    do {
        if (current->data == data)
            break;
        prev = current;
        current = current->next;
    } while (current != *head);

    if (current == *head && prev != NULL) {
        printf("Element not found in the list\n");
        return;
    }

    if (current == *head) {
        *head = current->next;
    }

    if (prev != NULL) {
        prev->next = current->next;
    }

    free(current);
}

void display(struct node *head) {
    if (head == NULL) {
        printf("The List is Empty\n");
    } else {
        struct node *current = head;
        printf("The Circular Linked List\n");
        do {
            printf("%d -> ", current->data);
            current = current->next;
        } while (current != head);
        printf("...\n");
    }
}

int main() {
    int choice;
    struct node *head = NULL;
    int data;

    while (1) 
    {
        printf("\nCircular Linked List Module\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Print All\n");
        printf("4. Exit\n");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("Enter the number to be inserted: ");
                scanf("%d", &data);
                insert(&head, data);
                break;

            case 2:
                printf("Enter the number to be deleted: ");
                scanf("%d", &data);
                delete(&head, data);
                break;

            case 3:
                display(head);
                break;

            case 4:
                printf("Thank you for using Circular Linked List Module\n");
                exit(0);

            default:
                printf("Invalid Input\n");
        }
    }

    return 0;
}
