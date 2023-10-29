#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

 struct node
{
    char data[100] ;
    int priority;
    int completed;
    struct node* next;
};

struct node* newNode(char d[], int p)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    strcpy(temp->data,d);
    temp->priority = p;
    temp->completed=0;
    temp->next = NULL;
    return temp;
}


void push(struct node** head, char d[], int p)
{
    struct node* starting = (*head);
    struct node* tempvar = newNode(d, p);


    if ((*head)->priority > p) 
    {
        tempvar->next = *head;
        (*head) = tempvar;
    }
    else 
    {
        while (starting->next != NULL && starting->next->priority < p) 
        {
            starting = starting->next;
        }
    
        tempvar->next = starting->next;
        starting->next = tempvar;
    }
}

int isEmpty(struct node** head)
{
    return (*head) == NULL;
}

int main()
{

    printf("Welcome to To Do List\n");
    int choice;
    int i=1;
    int numberOfTask=0;
    int numberOfCompletedTask=0;
    struct node* pq = NULL; 
    while(choice!=7)
    {
    
    
    
    printf("\n\n1. Add a Task\n");
    printf("2. Remove a Task\n");
    printf("3. Mark Task as Completed\n");
    printf("4. Display all the Task with Priority\n");
    printf("5. Show Highest Priority task to be done\n");
    printf("6. Display All Completed Task\n");
    printf("7. Exit\n");
    printf("Pick a choice\n");
    scanf("%d",&choice);



switch(choice)
{
    case 1:
    {
        char task[100];
        int prior;
        printf("Enter the Task:\n");
        scanf("%s",task);

        while (1) 
        {
            printf("Enter the priority for %s (1-10): ", task);
            scanf("%d", &prior);
            if (prior >= 1 && prior <= 10) 
            {
                break;
            } 
            else 
            {
                printf("Invalid priority value. Please enter a value between 0 and 10.\n");
            }
        }
        
        
       
        
       
         if(pq==NULL)
         {
            pq=newNode(task,prior);
         }
         else
         {
            push(&pq,task,prior);
         }
    
        numberOfTask++;
        printf("%s with priorty %d is inserted, To watch all the task Press 4", task, prior);
        break;
       
       
    }
    case 2:
    {
        char remove[100];

        if(!isEmpty(&pq))
        {
            struct node* prev = NULL;
            struct node* curr = pq;

            printf("Enter the Task to be removed\n");
            scanf("%s",remove);
            while(curr!= NULL && strcmp(curr->data, remove) != 0)
            {
                prev=curr;
                curr=curr->next;
            }

            if(curr!=NULL)
            {
                if(prev!=NULL)
                {
                    prev->next=curr->next;
                }
                else
                {
                    pq=curr->next;
                }


                free(curr);
                numberOfTask--;
                printf("%s has been removed from the task\n\n",remove);
            }
            else
            {
                printf("Task not found\n\n");
            }
        }
        else
        {
             printf("\nNo Task Currently Added\n\n");
        }
        break;
    }
    
    case 3:
    {
        char completed[100];
        if(!isEmpty(&pq))
        {
            struct node* ptr = pq;

            printf("Enter the Task to be marked complete\n");
            scanf("%s",completed);

             while(ptr!= NULL && strcmp(ptr->data, completed) != 0)
            {
                ptr=ptr->next;
            }

            ptr->completed=1;
            numberOfCompletedTask++;
            printf("%s is Marked Completed \n", ptr->data);

        }
        break;
    }

    case 4:
    {
        if(!isEmpty(&pq))
        {
            struct node* ptr=pq;
            printf("Total Number of Tasks:  %d",numberOfTask);
            printf("\n\nPriority   Task\n");
            printf("--------   -----------------\n");
            while(ptr!=NULL)
            {
                if(ptr->completed==0)
                {
                     printf("%-10d %s\n",ptr->priority, ptr->data);
                }
                else
                {
                    printf("%-10d %s    **Completed**   \n",ptr->priority, ptr->data);
                }
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
        if (!isEmpty(&pq) && numberOfTask - numberOfCompletedTask != 0) 
        {
            struct node* ptr = pq;
            int highestPriority = -1;
            while (ptr != NULL) 
            {
                if (ptr->completed == 0 && (highestPriority == -1 || ptr->priority < highestPriority)) 
                {
                    highestPriority = ptr->priority;
                }
                ptr = ptr->next;
            }
            
            if (highestPriority == -1) 
            {
                printf("\nNo Task Currently To Be Done.\n");
            } 
            else 
            {
                ptr = pq;
                printf("Highest Priority Tasks:\n");
                while (ptr != NULL) 
                {
                    if (ptr->completed == 0 && ptr->priority == highestPriority) 
                    {
                        printf("%s\n", ptr->data);    
                    }
                    ptr = ptr->next;
                }
            }
        } 
        else 
        {
            printf("\nNo Task Currently To Be Done.\n");
        }
        break;
    }
    case 6:
    {
        
        struct node *ptr2=pq;
        if(numberOfCompletedTask!=0)
        {
            printf("The Completed Task are: \n");
            while(ptr2!=NULL)
            {
                if(ptr2->completed==1)
                {
                    printf("%s \n",ptr2->data);
                }
                ptr2=ptr2->next;
            }
        }
        else
        {
            printf("No completed task yet");
        }
        
        break;
    }
    case 7:
    {
        printf("I hope you complete all your Tasks,Have A Nice Day\n");
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