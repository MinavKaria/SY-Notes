#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
    int data;
    struct node* next;
    struct node* prev;
};

void insert(struct node** head, int data) 
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) 
    {
        *head = newNode;
    } 
    else 
    {
        struct node* current = *head;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
}

void delete(struct node** head, int data) 
{
    struct node* current = *head;

    while (current != NULL) 
    {
        if (current->data == data) 
        {
            if (current->prev != NULL) 
            {
                current->prev->next = current->next;
            } 
            else 
            {
                *head = current->next;
            }
            if (current->next != NULL) 
            {
                current->next->prev = current->prev;
            }
            free(current);
            return;
        }
        current = current->next;
    }

    printf("Element not found in the list\n");
}

void display(struct node* head) 
{
    if (head == NULL) 
    {
        printf("The List is Empty\n");
    } 
    else 
    {
        struct node* current = head;
        printf("The Doubly Linked List\n");
        while (current != NULL) {
            printf("%d <-> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() 
{
    int choice;
    struct node* head = NULL;
    int data;

    while (1) 
    {
        printf("\nDoubly Linked List Module\n");
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
                printf("Thank you for using Doubly Linked List Module\n");
                exit(0);

            default:
                printf("Invalid Input\n");
        }
    }

    return 0;
}
