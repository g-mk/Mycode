#include<stdio.h>
#include<stdlib.h>
main()
{
 int n,i,j=0,data[50],count=0,pos[10];
 printf("\nEnter the number of bits\n");
 scanf("%d",&n);
 printf("\nEnter the data\n");
 for(i=1;i<=n;i++)
 {
  scanf("%d",&data[i]);
 }
 for(i=2;i<n;i++)
 {
  if(data[i]==1)
  {
   count++;
  }
  else
   count=0;
  if(count==5)
  {
   for(j=i+1;j<n-1;j++)
   {
    data[j]=data[j+1];
   }
   n--;
   count=0;
  }
 }
 printf("\nThe Data is:\n");
 for(i=2;i<n;i++)
  printf("%d ",data[i]);
}
