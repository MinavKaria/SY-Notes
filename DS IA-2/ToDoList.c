// C code to implement Priority Queue
// using Linked List
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Node
 struct node
{
    char data[100] ;
    int priority;
    struct node* next;
};


 struct node* newNode(char d[], int p)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    strcpy(temp->data,d);
    temp->priority = p;
    temp->next = NULL;
    return temp;
}


char* peek(struct node** head)
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
void push(struct node** head, char d[], int p)
{
    struct node* start = (*head);
    struct node* temp = newNode(d, p);


if ((*head)->priority > p) 
{
    // Insert New Node before head
    temp->next = *head;
    (*head) = temp;
}
else 
{
// Traverse the list and find a
// position to insert new node
    while (start->next != NULL && start->next->priority < p) 
    {
        start = start->next;
    }
 
    temp->next = start->next;
    start->next = temp;
}
}

int isEmpty(struct node** head)
{
    return (*head) == NULL;
}


int main()
{

    printf("Welcome to To Do List\n\n\n");
    int choice;
    int i=1;
    struct node* pq = NULL; 
    while(choice!=6)
    {
    
    
    
    printf("1. Add a Task\n");
    printf("2. Remove a Task\n");
    printf("3. Mark Task as Completed\n");
    printf("4. Display all the Task with Priority\n");
    printf("5. Give Highest Priority task to be done\n");
    printf("6. Exit\n");
    printf("Pick a choice\n");
    scanf("%d",&choice);



switch(choice)
{
    case 1:
    {
        char task[100];
        int prior;
        printf("Enter the Task\n");
        scanf("%s",task);
        printf("Enter the priority for %s \n",task);
        scanf("%d",&prior);
        
       
         if(pq==NULL)
         {
            pq=newNode(task,prior);
         }
         else
         {
            push(&pq,task,prior);
         }
    
        break;
       
       
    }
    case 2:
    {
        char remove[100];
        printf("Enter the Task to be removed");
        scanf("%s",remove);
        // if(!isEmpty(&pq))
        // {
        //     struct node *ptr=pq;
        //     while(ptr->data!=remove)
        //     {
        //         ptr=ptr->next;
        //     }
        //     printf("%s",ptr->data);
        // }
        // else
        // {
        //      printf("\nNo Task Currently Added\n\n");
        // }
        break;
    }
    
    case 3:
    {
        
    }

    case 4:
    {
        if(!isEmpty(&pq))
        {
            struct node* ptr=pq;
            printf("\n\nPriority   Task\n");
            printf("--------   -----------------\n");
            while(ptr!=NULL)
            {
                
                printf("%-10d %s\n",ptr->priority, ptr->data);
                ptr=ptr->next;
            }

            printf("\n\n\n");
            
        }
        else
            {
                printf("\nNo Task Currently Added\n\n");
            }
        break;
    }
    case 5:
    {
        if(!isEmpty(&pq))
        {
            struct node* ptr=pq;
            int highestPriority=pq->priority;
            printf("Highest Priority Tasks\n");
            while(ptr != NULL && ptr->priority == highestPriority)
            {
                printf("%s \n",ptr->data);
                ptr=ptr->next;
            }
        }
        else
        {
            printf("\nNo Task Currently Added\n\n");
        }
        break;
    }
    case 6:
    {
        printf("I hope you complete all your Tasks,Have A Nice Day Goodbye\n");
        exit(0);
    }

    default:
    {
         printf("Invalid choice. Please select a valid option.\n");
    }
}



}

return 0;
}