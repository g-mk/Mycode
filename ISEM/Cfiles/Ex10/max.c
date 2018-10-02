#include<stdio.h>
void max(int a[],int n)
{
 int i=0,max=0;
 for(i=0;i<n;i++)
 {
  if(max<a[i])
   max=a[i];
 }
 printf("%d\n\n",max);
}

main()
{
 int x[5][5],i,j;
 printf("Enter the element in rowwise manner:\n");
 for(i=0;i<5;i++)
  {
   printf("Enter the element for %d Row: ",i+1);
   for(j=0;j<5;j++)
    {
      scanf("%d",&x[i][j]);
    }
   }
 printf("Given Matrix is:\n");
 for(i=0;i<5;i++)
  {
   for(j=0;j<5;j++)
    {
     printf("%d\t",x[i][j]);
    }
   printf("\n");
  }
 for(i=0;i<5;i++)
  {
   printf("Maximum value in %d Row:",i+1);
   max(x[i],5);
  }
}

