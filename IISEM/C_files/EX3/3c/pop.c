#include<stdio.h>
#include<stdlib.h>
main()
{
 int **a;
 int d,c,i,j,n,sum;
 printf("Enter the No. Of Districts: ");
 scanf("%d",&d);
 printf("Enter the No. Of City in each District: ");
 scanf("%d",&c);
 a=(int **)malloc(d*sizeof(int *));
 for(i=0;i<d;i++)
  {
   a[i] = (int*)(malloc(c+1*sizeof(int)));
  }
 for(i=0;i<d;i++)
  { sum=0;
   printf("Enter the Population for District %d\n ",i+1);
   for(j=0;j<c;j++)
    {
     printf("Enter the Population for City %d ",j+1);
     scanf("%d",&a[i][j]);
     sum+=a[i][j];
    }
   a[i][c]=sum;
  }
 for(i=0;i<d;i++)
  {
   printf("District %d ",i+1);
   for(j=0;j<c;j++)
    {
     printf("%d\t",a[i][j]);
    }
   printf("\n");
  }
 printf("Enter the district to know the Population: ");
 scanf("%d",&n);
 if(n<=c)
 {
 printf("Population for the district %d is %d\n\n",n,a[n-1][c]);
 }
 else
  printf("No Such District Exists......\n\n");
}

