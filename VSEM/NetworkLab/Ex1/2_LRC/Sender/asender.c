#include"hsender.h"
main()
{

 int **a,n,i,j,*parity;

  parity=(int*) malloc (sizeof(int)*8);

  a=(int**) malloc (sizeof(int*)*4);
  for(i=0;i<4;i++)
    a[i]=(int*) malloc (sizeof(int)*8);

 printf("\nEnter the number of bits: ");
 scanf("%d",&n);
 n=n/8;

 for(i=0;i<n;i++)
 {
  for(j=0;j<8;j++)
  {
    scanf("%d",&a[i][j]);
  }
 }

 parity=calculate_LRC(a,n);

 printf("\nThe data to be transmitted is: \n");
 for(i=0;i<n;i++)
 {
  for(j=0;j<8;j++)
  {
   printf(" %d",a[i][j]);
  }
   printf("\n");
 }

 for(i=0;i<8;i++)
  printf(" %d",parity[i]);
 printf("\n");
 free(a);
}

