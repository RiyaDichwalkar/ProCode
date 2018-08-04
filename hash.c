#include<stdio.h>
int linear(int [],int,int);
int qaudratic(int [],int,int);
void display(int[],int);
void main()
{
   int size, key,c,q=1;
    int choice;
   do{
        printf("Enter the size of hash table which is a prime no\n");
        scanf("%d",&size);
        for(int i=2;i<size/2;i++)
           {
                if(size%i==0)
                   {c=1;printf("size is not prime no!!\n");break;}
                else{c=0;}
           }
     }
    while(c==1);
     int hash[size];
      for(int i=0;i<size;i++)
       {
              hash[i]=-1;                            //assigning each element in the array to -1
       }
       do{
   printf("Enter 1 to LINEAR probing \n   2 to QUDRATIC probing\n");
   scanf("%d",&choice);
   if(choice<1 || choice >2){printf("Invalid Input\n");}
   }
   while(choice<1 || choice >2);
   printf("Enter the positive key \n");
   printf("Enter -1 to stop\n");
   scanf("%d",&key);
   if(key!=-1)
   {
     do
       {
              if(choice==1){ q= linear(hash,key,size);}
              else{q= qaudratic(hash,key,size);}
           if(q)
            {
               printf("Enter the key \n");
               printf("Enter -1 to stop\n");
               scanf("%d",&key);
            }
       }
      while(key!=-1 && q);
      printf("The hash table is\n");
      display(hash,size);
   }

}
int linear(int a[],int no,int s)                      //linear probing
{

    int j,q,c;
    q=c=0;int k=no;
    while(q==0 && c<s)                      //c= no. of collision and q denotes whether the key is successfully filled inside the array or not
    {
         int r=k%s;
         if(a[r]==-1)                       //-1 denotes array position is empty
         {
             a[r]=no;
             q=1;
             j=1;
         }
    else
        {  k=no;
           c++;
           k+=c;                          //linear probing
        }
    }
     if(c==s)
        {
          printf("Array is fulled\n");j=0;
        }
   return j;
}
int qaudratic(int a[],int no,int s)
{

    int j,q,c;
    q=c=j=0;int k=no;
    while(q==0 && c<s)
    {
         int r=k%s;
         if(a[r]==-1)
         {
             a[r]=no;
             q=1;
             j=1;
         }
    else
        {
            k=no;
            j=0;
           c++;
           k+=(c*c);               //qaudratic probing
        }
    }

     if(c==s &&j==0)
        {
          printf("Sorry The element can't be filled inside the array\n");j=0;
        }
   return j;
}
void display(int a[],int size)
{
   for(int i=0;i<size;i++)
      {
          printf("%d\n",a[i]);
      }
}
