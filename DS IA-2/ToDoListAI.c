#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node
struct node
{
    char data[100];
    int priority;
    struct node* next;
};

struct node* newNode(char d[], int p)
{
    struct node* temp = malloc(sizeof(struct node));
    strcpy(temp->data, d);
    temp->priority = p;
    temp->next = NULL;
    return temp;
}

char* peek(struct node** head) // Change return type to char*
{
    return (*head)->data;
}

void pop(struct node** head)
{
    struct node* temp = *head;
    (*head) = (*head)->next;
    free(temp);
}

// Function to push according to priority
void push(struct node** head, char d[], int p) // Change data type of 'd' to char[]
{
    struct node* start = (*head);
    struct node* temp = newNode(d, p);

    if ((*head) == NULL || (*head)->priority > p)
    {
        // Insert New Node before head or when the list is empty
        temp->next = *head;
        (*head) = temp;
    }
    else
    {
        // Traverse the list and find a position to insert the new node
        while (start->next != NULL && start->next->priority < p)
        {
            start = start->next;
        }

        temp->next = start->next;
        start->next = temp;
    }
}

// Function to check if the list is empty
int isEmpty(struct node** head)
{
    return (*head) == NULL;
}

// Driver code
int main()
{
    int choice;
    struct node* pq = NULL;

    printf("Welcome to To Do List\n");
    
    while (choice != 6)
    {
        printf("1. Add a Task\n");
        printf("2. Remove a Task\n");
        printf("3. Mark Task as Completed\n");
        printf("4. Display all the Tasks with Priority\n");
        printf("5. Give Highest Priority task to be done\n");
        printf("6. Exit\n");
        printf("Pick a choice\n");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
            {
                char task[100];
                int prior;
                printf("Enter the Task\n");
                scanf("%s", task);
                printf("Enter the priority for %s\n", task);
                scanf("%d", &prior);

                push(&pq, task, prior);
                break;
            }
            
            case 2:
            {
                // Implement task removal
                break;
            }
            
            case 3:
            {
                // Implement marking a task as completed
                break;
            }
        }
    }

    while (!isEmpty(&pq))
    {
        printf("%d: %s\n", pq->priority, peek(&pq));
        pop(&pq);
    }

    return 0;
}
