#include"hsender.h"
int* calculate_LRC(int **a,int n) 
{
 int j,i,count[8],*parity;
 parity=(int *) malloc (sizeof(int)*8);
 for(j=0;j<8;j++)
  count[j]=0;
 for(j=0;j<8;j++)
 {
  for(i=0;i<n;i++)
  {
    if(a[i][j]==1)
     count[j]++;
  }
 }
 for(i=0;i<8;i++)
  parity[i]=1;
 for(i=0;i<8;i++)
 {
  if(count[i]%2==0)
   parity[i]=0;
 }
  return parity;
}
