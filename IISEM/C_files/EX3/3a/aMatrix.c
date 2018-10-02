#include"hMatrix.h"
main()
{
 int **a,**b,**c,r1,r2,c1,c2,i,j,f;
 printf("Enter the No. of Rows and Colums of Mat A:");
 scanf("%d%d",&r1,&c1); 
 printf("Enter the No. of Rows and Colums of Mat B:");
 scanf("%d%d",&r2,&c2);
 f=ispossible(c1,r2);
 if(f==1)
 {
  a= (int **)malloc(r1*sizeof(int *));
  b= (int **)malloc(r2*sizeof(int *));
  c= (int **)malloc(r1*sizeof(int *));
  for(i=0;i<r1;i++)
  {
   a[i]=(int *)malloc(c1*sizeof(int ));
  }
  for(i=0;i<r2;i++)
   b[i]=(int *)malloc(c2*sizeof(int ));
  for(i=0;i<r1;i++) 
   c[i]=(int *)malloc(c2*sizeof(int));
  read(a,r1,c1);
  read(b,r2,c2);
  matmul(a,b,c,r1,c2,c1);
  print(c,r1,c2);
 }
 else
  printf("Matrix Multiplication is not Possible.....");
}

