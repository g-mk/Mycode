#include"hStock.h"
int alloc(struct stock *a,int n,int ch,int l)
{
 int i,j,id,q;
  if(l==1)
  {
  a =(struct stock *)realloc(a,(n+l)*sizeof(struct stock ));
 for(i=n;i<n+l;i++)
 {
 printf("Enter the new stock:");
 printf("Name:");
 scanf("%s",&a[i].n);
 printf("ID:");
 scanf("%d",&a[i].id);
 printf("Price:");
 scanf("%f",&a[i].r);
 printf("Quantity:");
 scanf("%d",&a[i].s);
 }
 return n+l;
 }
 if (l==2)
 {
   printf("Enter the Id to add Stock..");
   scanf("%d",&id);
   printf("Enter the Quantity.:");
   scanf("%d",&q);
   for(i=0;i<n;i++)
    if(a[i].id==id)
       a[i].s+=q;
 return n;
  }
}
int remov(struct stock *a,int n,int c)
{
  int i,j,rm;
  char w='n';
  for(i=0;i<n;i++)
   {
    if(a[i].id==c)
     {
      printf("Quantity to be Removed:");
      scanf("%d",&rm);
      a[i].s-=rm;
      if(a[i].s<=0)
      {
        printf("Do you want to remove the items:y/n");
        scanf(" %c",&w);
        if(w=='y')
         {
         for(j=i;j<n;j++)
          a[j]=a[j+1]; 
         return n-1;
         }
      }
    }
  }
   return n;
}
void print(struct stock *a,int l)
{
 int i;
 for(i=0;i<l;i++)
 {
 printf("Name\tID\tPrice\tQuantity\n");
 printf("%s\t%d\t%.2f\t%d\n",a[i].n,a[i].id,a[i].r,a[i].s);
 /* printf("Name:%s\n",a[i].n);
  printf("ID:%d\n",a[i].id);
  printf("Price: %.2f\n",a[i].r);
  printf("Quantity:%d\n",a[i].s);*/
 }
}
int check(struct stock *a,int item,int n,int q)
{
 int i;
 for(i=0;i<n;i++)
 {
  if(a[i].id==item)
   {
   if(a[i].s>q)
   return 1;
  else
   return 0;
   }
 }
} 
