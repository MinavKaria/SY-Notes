/* Program to create a ascending order list using circular linked list 
#include <stdio.h>
#include<stdlib.h>
//structure of the node
struct node{
int data;
struct node *next;
} ;

//Function to insert the element in the ascending order list 
void insert(struct node **l, int ele)
{
  struct node * temp, *current,*prev ;
  //creating a node to store data
  temp=(struct node *) malloc(sizeof(struct node));
  temp->data =ele;
  //if list is empty
  if(*l==NULL)
  {
    *l=temp;
    temp->next=temp;
    
  } //otherwise  identify appropriate location to insert data 
  else
  {
    current=(*l)->next;
    if(current->data >=ele)  //insertion at the beginning 
    {
      temp->next=current;
      (*l)->next=temp;
    }
    else if ((*l)->data<=ele) //insertiona at end 
    {
      temp->next=(*l)->next;
      (*l)->next=temp;
      *l=temp;
    }
    else  //insertion between 
    {
      prev=*l;
      while(current!=l && current->data < ele)
        {
           prev=current;
          current=current->next;
        }
      temp->next=current;
      prev->next=temp;
      
    }
  }
  
  
}

//function to display the ascending order list 
void displaycl(struct node *l)
{
  struct node *p=l;
  if(p==NULL)
  {
    printf("list is empty");
    
  }
  else
  {
    while(p->next!=l)
      {
        printf("%d \n",p->next->data);
        p=p->next;
      }
    printf("%d",l->data);
  }
}

//delete a element in the ascending order list 
void delete(struct node ** l, int ele)
  {
   struct node * temp, *p=*l; 
   if(p==NULL)
      printf("list is empty")    ;
    else
   {
    do {
        if(ele==p->next->data)  
        {
          temp=p->next;
          if(p->next==p) //only one node
          {
            *l=NULL;
          }
          else
          {
            if(p->next==*l) //last node
          {
            *l=p;
          }
           p->next=p->next->next; 
          }
          free(temp);
          
        }
        else{
          p=p->next;
        }
    } while(p!=*l);

     /* need to write code to delete all occurance of element 
     and also the case if the element is not found in the list */
   }
  }

int main(void) {
struct node * last=NULL; //LIST IS EMPTY
  //inserting multiple element
  insert(&last,89);
   insert(&last,8);
  insert(&last,99);
  insert(&last,90);
   insert(&last,90);
   insert(&last,8);
   insert(&last,92);
   insert(&last,91);

  //displaying list after inserttion 
printf("list\n");
  displaycl(last);

  printf("list after deletion");
 delete(&last,8);
  
  displaycl(last);
  
  
 

  return 0;
}