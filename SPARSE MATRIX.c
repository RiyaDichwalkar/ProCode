#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int rno,cno,data;
    struct node *downptr ,*rightptr ,*next;  //3 pointers for linking
}node;

node* createhead(node *Head,int n);
void getnode(node *head1,int rn,int cn);
void createnode(node *HEAD,int rno,int colno,int data);
node* traversebyheadrow(node *HEAD,int rno);
node* traversebyheadcol(node *HEAD,int colno);
node* traversebyrow(node* HEAD,int rno);
node* traversebycol(node *HEAD,int colno);
void main()
{
    int row,column,element,rowno,colno,q=1;

    printf("Enter total no of rows\n");
    scanf("%d",&row);
    printf("Enter total no. of columns\n");
    scanf("%d",&column);
    int max =(row>column)?row:column;
    node *HEAD =  (node*)malloc(1*sizeof(node));  //create memory space
    HEAD->rno=row;
    HEAD->cno = column;
    HEAD->next =NULL;
    HEAD->downptr =NULL;
    HEAD->rightptr = NULL;
    node *HeadTemp =HEAD;
    for (int i=1;i<=max;i++)
    {
         HeadTemp=  createhead(HeadTemp,i);    //creating head node
    }

    HeadTemp->next =HEAD;      //create a circular linklist

    printf("Do you want enter the elements? 0 for no ,yes otherwise \n");
    scanf("%d",&q);
    if(q!=0)
    {
         printf("\nEnter the non_zero elements in the matrix\n");
         while(q!=0)
          {
             printf("Enter the row no\n");
             scanf("%d",&rowno);
             printf("Enter the column no\n");
             scanf("%d",&colno);
             if(rowno>0 && rowno<=row && colno>0 && colno<=column)       //checking the boundary of the matrix
                 {
                      printf("Enter the element no\n");
                      scanf("%d",&element);
                      if(element!=0)
                      {
                        createnode(HEAD,rowno,colno,element);        //create a node
                      }

                 }
             else
                {
                    printf("invalid input for rows and columns\n");
                }
             printf("Do you want enter the element? 0 for no ,yes otherwise\n");
             scanf("%d",&q);
           }
    }
    else
    {
        printf("It is a NULL matrix\n");
    }
    printf("THE SPARSE MATRIX IS \n");
     getnode(HEAD,row,column);          //printing the sparse matrix
}
 node* createhead(node *Head,int n)
 {
      node* temp;
      temp =(node*)malloc(1*sizeof(node));
      if(temp==NULL)
      {
        printf("No memory allocated!\n");
      }
      else
      {
        Head->next =temp;
        temp->rno = n;
        temp->cno = n;
        temp->rightptr =temp;
        temp->downptr =temp;
        temp->next =NULL;
        Head =temp;
      }
      return (Head);
 }


void createnode(node *HEAD,int rno,int colno,int data)
{
    node *temp,*p ,*r,*head;
    head=HEAD->next;
    temp=(node*)malloc(1*sizeof(node));
    temp->rno =rno;
    temp->cno=colno;
    temp->data =data;
    p=traversebyheadrow(HEAD,rno);    //traversing by the head nodes by using row no.
    if(p->rightptr==p)
    {
         temp->rightptr=p;
         p->rightptr=temp;
    }
    else
    {
         head =p;

        node *s = traversebyrow(head,colno);  //traversing the nodes by the column
        temp->rightptr= s->rightptr;
        s->rightptr =temp;
    }
    r=traversebyheadcol(HEAD,colno);    //traversing the head nodes by using column no.
    if(r->downptr==r)
    {
         temp->downptr=r;
         r->downptr=temp;
    }
    else
    {
        head =r;
        node *t= traversebycol(head,rno);  //traversing the nodes by using row no.
        temp->downptr= t->downptr;
        t->downptr =temp;
    }
}

node* traversebyheadrow(node *HEAD,int rno)
{
      node *head,*p,*temp;
      head=HEAD->next;
      p= head;
      temp=p;
      while(temp!=HEAD && temp->rno<=rno)
      {
         p=temp;
         temp=temp->next;
      }

 return(p);
}

node* traversebyheadcol(node *HEAD,int colno)
{
      node *head,*p,*temp;
      head=HEAD->next;
      p= head;
      temp=p;
      while(temp!=HEAD && temp->cno<=colno)
      {
         p=temp;
         temp=temp->next;
      }

  return(p);
}

node* traversebycol(node *HEAD,int rno)
{
      node *head,*p;
      head=HEAD->downptr;
      p= head;
       if((p->rno)>rno)
      {
          head =HEAD;
      }
      else
      {
      while(p!=HEAD && p->rno<=rno)
      {
          head=p;
         p=p->downptr;
      }
      }

  return(head);
}
node* traversebyrow(node *HEAD,int colno)
{
      node *head, *p ,*temp;
      head=HEAD->rightptr;
      p= head;
      if((p->cno)>colno)
      {
          head =HEAD;
      }
      else
      {
      while((p!=HEAD )&& p->cno<=colno)
      {
          head=p;
         p=p->rightptr;
      }
      }

  return(head);
}
void getnode(node *head1,int rn,int cn)
{

int i,j;
	node *temp;
	for(i=1;i<=rn;i++)
	{
		head1 = head1->next;
		temp = head1->rightptr;

		for (j=1;j<=cn;j++)
		{
			if(temp->cno==j && temp!=head1)
			{
				printf("%d\t",temp->data);

				temp=temp->rightptr ;
			}
			else
				printf("0\t");
		}
		printf("\n");
	}
}
