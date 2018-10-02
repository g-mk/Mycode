#include<stdio.h>
#include<stdlib.h>
main()
{
 int **a;
 int d=0,c=0,n,total;
 printf("Enter the No. Of Districts: ");
 scanf("%d",&d);
 printf("Enter the No. Of City in each District: ");
 scanf("%d",&c);
 a=(int **)allocate(a,d,c);
 total=calc(a,d,c);
 print(a,d,c);
 printf("Total Population of Tamil Nadu is %ld\n",total);
 printf("Enter the district to know the Population: ");
 scanf("%d",&n);
 if(n<=d)
 {
 printf("Population for the district %d is %d\n\n",n,a[n-1][c]);
 }
 else
  printf("No Such District Exists......\n\n");
 free(a);
}

