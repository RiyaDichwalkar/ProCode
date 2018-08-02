/*Consider a single queueing system for a food joint. There is a single queue of customers.
The customers however, are served by three different counters. The moment a counter is
free, the first customer in the queue is serviced at the counter. It is possible that at a
particular time instant only 2 counters are free to serve customers, so at that point the first
2 customers are removed from the queue for servicing. Simulate this system’s behavior.
Your program must:
i. Create a queue for n customers
ii. At every instant of time ask for how many counters are free(k) and then remove
k customers from the queue accordingly. (Do this till all n customers are serviced.
Assume: There are no new customers adding to the queue.)
iii. Display the queue contents at each instant after removing customer*/




#include<stdio.h>    /*declare the header files*/
#include<stdlib.h>
#include<string.h>
typedef struct queue/* self referencing stucture*/
{
        char name[20];/*structure member name to store the person's name*/
        struct queue*next;
}queue;
queue *enqueue (queue*);/*create a queue*/
queue *dequeue(queue*);/*remove the person from the queue*/
void display(queue*);/*display the queue*/
int main()
{
  	int n,i,s=0;int q=1;/*decdlare the variable*/
      queue *front=NULL,*rear=NULL;/*structure pointers */
      printf("enter the no. of persons in queue\n");
      scanf("%d",&n);/*no.of person*/
      if(n>0)
          {
              for(i=1;i<=n;i++)
                  {   
                      rear=enqueue(rear);/*create a queue*/
                      if(i==1)
                          {
                              front=rear;}/*assignment of the front*/
                          }
                      printf("\nthe queue is\n");
                      display(front);/*display queue */
                      while(q)/*repeat till user will input of q is 0*/
                            {
                                 do
                                   {
                                      printf("how many counters are free?enter 0 or 1 or 2 or 3\n");
                                      scanf("%d",&s);
                                      if(s<0 || s>3)
                                          {
                                             printf("\ninvalid input\n");
                                          }
                                   }
                                   while(s<0 || s>3);/*repeat till the user eill input valid input */
                                   if(s==0)/*none of the counter is free*/
                                      {
                                            printf("sorry the counter is not free.\n");
                                      }
                                   else
                                      {
                                         for(i=1;i<=s;i++)
                                          {   
                                              if(front==NULL)
                                              {
                                                 printf("Queue is empty \n");
                                                  break;
                                              }
                                              printf("%d\t",i);
                                        front=dequeue(front);/*to remove the name of the person from the queue*/
                                          }
                                     }
                               if(front!=NULL)
                                      {
                                         printf("remaining person in queue\n");
                                         display(front);
                                         do
                                          {
                                             printf("\ndo you want to continue? enter 1 to continue 0 to stop\n");
                                             scanf("%d",&q);
                                             if(q<0 || q>1)
                                                    {
                                                            printf("\ninvalid input\n");
                                                    }
                                         }
                                         while(q<0 || q>1);
                                     }
                                  else
                                     {
                                           q=0;
                                     }
                            }
         }
        else 
           {
                printf("queue is empty\n"):
           }
   return 0;
}
queue * enqueue ( queue*m)
{
    queue*temp;
    temp=( queue *)malloc(1*sizeof( queue));/*to allocate the memory */
    printf("enter the name of the person\n");
    scanf("%s",temp->name);/*read the name */
    temp->next=NULL;
    if(m==NULL)
          {
               m=temp;/*if the queue is empty*/
          }
    else
         {
               m->next=temp;/*add the name to the next of the last element of the queue*/
               m=temp;/*shift the last element pointer */
         }
     return (m);
}
void display( queue *front)
{
    queue *p; p=front;
    while(p!=NULL)/*if the queue is not empty*/
       {
         int v=0;
         printf("%d\t%s\n",++v,p->name);
         p=p->next;/*shift the pointer p to next element of the queue*/
       }
}
queue *dequeue( queue *front)
{    queue *p;
     p=front;
     char name[20];
     strcpy(name,p->name);
     printf("%s is being served \n",name);
     front=front->next;/*shift the front pointer while removing the element*/
     free(p);/*deallocate the memory allocated to p pointer*/
     return (front);

}

/*OUTPUT-
student@CC-Lab-007-U07:~/Desktop/riya$ gcc queue.c
student@CC-Lab-007-U07:~/Desktop/riya$ ./a.out
enter the no. of persons in queue
4
enter the name of the person
fg
enter the name of the person
gj
enter the name of the person
fh
enter the name of the person
gk

the queue is
1	fg
1	gj
1	fh
1	gk
how many counters are free?enter 0 or 1 or 2 or 3
2
1	fg is being served 
2	gj is being served 
remaining person in queue
1	fh
1	gk

do you want to continue? enter 1 to continue 0 to stop
1
how many counters are free?enter 0 or 1 or 2 or 3
3
1	fh is being served 
2	gk is being served 
Queue is empty 
student@CC-Lab-007-U07:~/Desktop/riya$ gcc queue.c
student@CC-Lab-007-U07:~/Desktop/riya$ ./a.out
enter the no. of persons in queue
1
enter the name of the person
dtg

the queue is
1	dtg
how many counters are free?enter 0 or 1 or 2 or 3
3
1	dtg is being served 
Queue is empty 
student@CC-Lab-007-U07:~/Desktop/riya$ gcc queue.c 
student@CC-Lab-007-U07:~/Desktop/riya$ ./a.out
enter the no. of persons in queue
0
queue is empty
student@CC-Lab-007-U07:~/Desktop/riya$ 

*/

