#include<stdio.h>
#include<stdlib.h>
main()
{
 int n,i,j=0,data[50],count=0,pos[10];
 printf("\nEnter the number of bits\n");
 scanf("%d",&n);
 printf("\nEnter the data\n");
 data[0]=0;
 for(i=1;i<=n;i++)
 {
  scanf("%d",&data[i]);
 }
 for(i=1;i<=n;i++)
 { 
  if(data[i]==1)
  {
   count++;
  }
  else
   count=0;
  if(count==5)
  {
   for(j=n;j>=i+1;j--)
   {
    data[j+1]=data[j];
   }
   data[i+1]=0;
   n++;
   count=0;
  }
 }
 data[n+1]=0;
 printf("\nThe Data is:\n");
 for(i=0;i<=n+1;i++)
  printf("%d ",data[i]);
}
