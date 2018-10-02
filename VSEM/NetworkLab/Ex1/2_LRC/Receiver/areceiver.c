#include"hreceiver.h"
main()
{
 int **a,n,i,j,result;

 printf("\nEnter the number of bits : \n");
 scanf("%d",&n);
 a=(int**) malloc (sizeof(int*)*5);

 for(i=0;i<5;i++)
  a[i]=(int*) malloc (sizeof(int)*8);
 
 n=n/8;
 for(i=0;i<n;i++)
 {
  for(j=0;j<8;j++)
  {
   scanf("%d",&a[i][j]);
  }
 }
 result=check_LRC(a,n);

 if(result==0)
   printf("\nError in transmission \n");
 else
   printf("\nNo Error in Transmission\n");
  free(a);
}
