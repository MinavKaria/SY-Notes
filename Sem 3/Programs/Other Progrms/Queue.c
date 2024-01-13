// Online C compiler to run C program online
#include <stdio.h>
#define max 5

int queue[max];
int front = -1, rear = -1;


void Enqueue(int queue[])
{
    int val;
    if((front==0 && rear==max-1)||rear==front-1)
    {
        printf("Overflow\n");
    }
    else
    {
        if(front==-1 && rear==-1)
        {
            front=rear=0;
        }
        else if(front!=0 && rear==max-1)
        {
            rear=0;
        }
        else
        {
            rear++;
        }
        printf("Enter the Number in the Queue\n");
        scanf("%d",&val);
        queue[rear]=val;
    }
}

int Dequeue(int queue[])
{
    int val;
    if (front == -1 && rear == -1)
    {
        printf("Underflow\n");
        return -1;
    }
    else
    {
        val = queue[front];

        if (front == rear)
        {
            front = rear = -1;
        }
        else if (front == max - 1)
        {
            front = 0;
        }
        else
        {
            front++;
        }

        return val;
    }
}


int peek(int queue[])
{
    int val;
    if(rear==-1 && front==-1)
    {
        printf("No Elements in the Queue");
    }
    else
    {
        val=queue[front];
    }
    
    return val;
}


void display(int queue[])
{
    if(front ==-1 && rear==-1)
    {
        printf("The Queue is Empty");
    }
    else
    {
        printf("The Queue: \n");
        if(front <=rear)
        {
            for(int i=front;i<=rear;i++)
            {
                printf("%d ",queue[i]);
            }
        }
        else
        {
            for(int i=front;i<=max-1;i++)
            {
                 printf("%d ",queue[i]);
            }
            for(int i=0;i<=rear;i++)
            {
                 printf("%d ",queue[i]);
            }
        }
        printf("\n");
    }
}




int main() 
{
    // Write C code here
    int choice;
    
    
    while(choice!=5)
    {
        
    
        printf("\nEnter the operation for Queue\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Peek\n");
        printf("5. Exit\n");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
            {
                Enqueue(queue);
                break;
            }
            case 2:
            {
                 int val=Dequeue(queue);
                 if(val==-1)
                 {
                     printf("The Queue is Empty");
                 }
                 else
                 {
                     printf("The Element removed from the front is %d",val);
                 }
                break;
            }
            case 3:
            {
                display(queue);
                break;
            }
            case 4:
            {
                int val=peek(queue);
                 if(val==-1)
                 {
                     printf("The Queue is Empty");
                 }
                 else
                 {
                     printf("The Element at the front is %d",val);
                 }
                break;
            }
            case 5:
            {
                printf("Thank you for using MasterQueue");
                break;
            }
            
            default:
            {
                printf("Invalid Input, Try Again!");
            }
        }
    
    }

    return 0;
}