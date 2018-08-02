
/*LINKED LIST
1.Imagine an IPL coach is maintaining the records for the all batsman in his team.The data  which he needs is players name,country and his score.The coach can have 10 to 15 standby                  batsman.Out of this standby coach needs to identify candidate batsman which can play in the tournament.The condition for selection is that the batsman has better score than average of               all standbybatsman. Write a program such that coach should be able to add new batsman,                remove a batsman,display all batsman,display average score and display list of batsman              who qualify based on condition from list.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct data        /*structure to store the data of a batsman*/
  {
     char name[20];
     char country[20];
     int score;
  }data;
typedef struct node         /*self referencing structure to create a linked list*/
  {
      data rec;
      struct node *next;
  }node;
                             /*function prototypes  */
node * nalloc();             /*function to allocate memory and input */
node * addback(node *);      /*create a linked list*/
void display(node *);        /*display all the batsman list*/
float average(node *);       /*display average */
node *display_list(node *,float);/*display qualified list of batsman
list */
node * search(node *,char[]);   /*search for the batsman name*/
node *delete(node *,node *);    /*delete the qualified batsman name*/
node * rem(node *,node *); /*remove the batsman details by taking the name*/
int main()
{
   int n=1,opt;
   float avg;
  int q=1;
  char name[20];
  node *p,*m=NULL;node * HEAD=NULL;      /*structure pointers*/
printf("enter the details of batsman \n");
   while(q)/*To take input as long as the user wants*/
   { 
  
     printf("enter the data of person %d",n);
     m =addback(m); /*adding at the back*/
     if(n==1)
     {
        HEAD=m;/*if m is null it represents the  start of the list */
     }  
     
     printf("do you want to enter the data of new batsman, 0 for no 1 for yes\n") ;    
     scanf("%d",&q);
     n++;
   } 
   printf("The list:\n");
    display(HEAD);/*display the list*/
    printf("\nDo you want to modify the list 1 for yes 2 for no\n");
    scanf("%d",&q);/*To modify the list */
    while(q)
    {
       printf("\nEnter 1 to delete the element\n 2 to add new element \n");
    scanf("%d",&opt);
   switch(opt)
   {
   	case 1:
   	{
   printf("\nDo you want to remove any batsman \n");
   scanf("%s",name);
   p=search(HEAD,name);/*Search by name in list*/
   HEAD=rem(HEAD,p);/*delete function*/
   printf("The modified  list:\n");
    display(HEAD);
   break;
   }
   case 2:
   {
   printf("\nDo you want to add any batsman");
    node *k=NULL;
    if(HEAD!=NULL)/*if the list is not empty  k is the last element of the previous list*/
    {
       k=m;
    }
  // printf("%d \t  %s \t %s \t %d\n",++c,m->rec.name,m->rec.country,m->rec.score);
   k=addback(k);
   if(HEAD==NULL)/*to start a new list if the list is empty */
   {
   	HEAD=k;
   }
   printf("The modified  list:\n");
    display(HEAD);
   break; 
   }
   default :printf("Invalid input\n");
  }
  printf("\nDo you want to modify the list 1 for yes 0 for no\n");
    scanf("%d",&q);
 }
   printf("\nThe final list of all batsman \n");
   
   display(HEAD); /*Display the final list of all batsman */
   avg= average(HEAD);/*find the average of the scores of all batsman*/
   printf("\nThe average of scores of all batsmans is %.2f\n",avg);
  printf("\nThe list of batsman who qualified \n");
   HEAD=display_list(HEAD,avg);
   printf("\nRemaining  batsman  list\n");
   display(HEAD);
   return 0;
}

node *nalloc()/*allocate the memory */
{
    node *temp;
    temp=(node*) malloc (sizeof(node)*1);/*assigning the size to the node*/
   if(temp!=NULL)/*if the memory  is allocated  properly */
   {
   	
       printf("\nenter the name\n");
       scanf("%s",temp->rec.name);
       printf("enter the country\n");
       scanf("%s",temp->rec.country);
       printf("enter the score\n");
       scanf("%d",&temp->rec.score);
       temp->next=NULL;
   }
   else
   {
   	printf("Error  in allocating  memory \n");
   	}
   return temp;
}
node *addback(node *m)
{     
    node *temp;
     temp=nalloc();
     if(m==NULL)
     {
       m=temp;
     }
     else
     {
     m->next=temp;
     m=temp;
     }
     return m;       /*return the last element pointer of the list*/
}

void display(node * head)/*display the list of all batsman */
{
    node *p =head; int c=0;
    if(p==NULL)
    {
    	printf("The list is empty \n");
    }
    while(p!=NULL)
    {
    	printf("%d \t  %s \t %s \t %d\n",++c,p->rec. name,p->rec.country,p->rec.score);
         p=p->next;
    }
}

float average(node *head)     /*calculate average */
{
     float avg=0, sum=0;
     node *p=head;
     int n=0;             /*n is for no.of elements in list */
     while(p!=NULL)
     {          
          sum +=p->rec.score; 
          p=p->next;
          n++;
     }
     if(n==0)
     {
     	avg=0;
     }
     else
     {
      avg =sum/n;
     }
    return avg;
}
node *display_list(node *head,float avg)/*display qualified list of batsman */
{  


    node *p=head;int c=0; node *start=NULL,*f,*temp,*m=NULL;
    while(p !=NULL)
    {
    	 if(p->rec.score > avg) /*checking each batsman's score with average*/
          { 
            if(m==NULL)
           {  
             temp =p; 
             m=temp;
             temp=temp->next;
             head= delete(head,p);
             p=temp;
             m->next=NULL;
             start=m;
           }
          else
           {
           	 temp=p;
           	 m->next=temp;
           	 m=temp;
           	 temp=temp->next; 
           	 head=delete(head,p);
           	 p=temp;
              m->next=NULL;
          
           }
        }
        else
        {
            p=p->next;
        }
        
      }
         printf("The new list is \n");
   display(start);
   return (head);
}

node * search(node *head,char name[20])/*search for the batsman name*/
{
     node *temp, *p;
     p =head;
     temp=p;
     if(p==NULL)
     {
     	printf("list is empty \n");
     }
     while (p!=NULL)
     {
         if(strcmp(p->rec. name,name)==0)
         {
              return (p);
         }
        temp=p;
        p=p->next;
     }
     return p;
}
node *delete(node *head,node *p) 
/*remove the batsman name to get the qualified batsman list */
{
   node *temp;
   temp=head;
   if(p==NULL)
      {
    printf("name is not found. \n");
      }
   else
   {
       if(p==head)
       {
            head=head->next;
       }
       else
       {
            while(temp->next !=p)
            {
                temp=temp->next ;
            }
            temp->next=p->next;
       }
   }
    return (head);
}

node *rem(node *head,node *p) 
/*remove the batsman name*/
{
   node *temp;
   temp=head;
   if(p==NULL)
      {
    printf("name is not found. \n");
      }
   else
   {
       if(p==head)
       {
            head=head->next;
            free(p);
       }
       else
       {
            while(temp->next !=p)
            {
                temp=temp->next ;
            }
            temp->next=p->next;
            free(p);
       }
   }
    return (head);
}

/*output-
student@CC-Lab-007-U07:~/Desktop/riya$ gcc linkedlist.c
student@CC-Lab-007-U07:~/Desktop/riya$ ./a.out
enter the details of batsman 
enter the data of person 1
enter the name
asd
enter the country
sdfg
enter the score
30
do you want to enter the data of new batsman, 0 for no 1 for yes
1
enter the data of person 2
enter the name
dfrg
enter the country
ghh
enter the score
40
do you want to enter the data of new batsman, 0 for no 1 for yes
1
enter the data of person 3
enter the name
fhy
enter the country
frg
enter the score
27
do you want to enter the data of new batsman, 0 for no 1 for yes
0
The list:
1 	  asd 	 sdfg 	 30
2 	  dfrg 	 ghh 	 40
3 	  fhy 	 frg 	 27

Do you want to modify the list 1 for yes 0 for no
1

Enter 1 to delete the element
 2 to add new element 
1

Do you want to remove any batsman 
dfrg
The modified  list:
1 	  asd 	 sdfg 	 30
2 	  fhy 	 frg 	 27

Do you want to modify the list 1 for yes 0 for no
1

Enter 1 to delete the element
 2 to add new element 
2

Do you want to add any batsman 
enter the name
ff
enter the country
hhj
enter the score
45
The modified  list:
1 	  asd 	 sdfg 	 30
2 	  fhy 	 frg 	 27
3 	  ff 	 hhj 	 45

Do you want to modify the list 1 for yes 0 for no
0

The final list of all batsman 
1 	  asd 	 sdfg 	 30
2 	  fhy 	 frg 	 27
3 	  ff 	 hhj 	 45

The average of scores of all batsmans is 34.00

The list of batsman who qualified 
The new list is 
1 	  ff 	 hhj 	 45

Remaining  batsman  list
1 	  asd 	 sdfg 	 30
2 	  fhy 	 frg 	 27
student@CC-Lab-007-U07:~/Desktop/riya$ 

*/
