#include"hPop.h"
int **allocate(int **a,int d, int c)
{ 
 int i;
 a=(int **)malloc(d*sizeof(int *));
 if(&a==NULL)
  printf("Error");
 for(i=0;i<d;i++)
  {
   a[i] = (int*)(malloc(c+1*sizeof(int)));
  }
 printf("%u\n",a);
 return a;
}
long int calc(int **a,int d,int c)
{
 long int total =0;
 int i,j,sum=0;
 for(i=0;i<d;i++)
  {
    sum=0;
   printf("Enter the Population for District %d\n ",i+1);
   for(j=0;j<c;j++)
    {
     printf("Enter the Population for City %d ",j+1);
     scanf("%d",&a[i][j]);
     printf("%d City ok\n",j+1);
     sum+=a[i][j];
    }
   a[i][c]=sum;
   total+=sum;
  }
 return total;
}
void print(int **a,int d,int c)
{
 int i,j;
 for(i=0;i<d;i++)
  {
   printf("District %d ",i+1);
   for(j=0;j<c+1;j++)
    {
     printf("%d\t",a[i][j]);
    }
   printf("\n");
  }
}
