#include"hMatrix.h"
void matmul(int **a,int **b,int **c,int r,int col,int l)
{
 int i,j,k;
 for(i=0;i<r;i++)
 {
  for(j=0;j<col;j++)
  {
   c[i][j]=0;
  }
 }
 for(i=0;i<r;i++)
 {
  for(j=0;j<col;j++)
  {
   for(k=0;k<l;k++)
   {
   c[i][j]=c[i][j]+a[i][k]*b[k][j];
   }
  }
 }
}

void read(int **a,int r,int c)
{
 int i,j;
 printf("Enter the value fo the array:\n");
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   scanf("%d",&a[i][j]);
  }
 }
}
void print(int **a,int r,int c)
{
 int i,j;
 printf("Resultant matrix:\n");
 for(i=0;i<r;i++)
 {
  for(j=0;j<c;j++)
  {
   printf("%d\t",a[i][j]);
  }
  printf("\n");
 }
}

int ispossible(int r,int c)
{
 if(r==c)
  return 1;
 else return 0;
}

