#include"hreceiver.h"

int check_LRC(int **a,int n)
{ 
 int i,j,count[8],parity[8];
 for(i=0;i<8;i++)
 {
   parity[i]=1;
   count[i]=0;
 }
 for(j=0;j<8;j++)
 {
  for(i=0;i<n-1;i++)
  {
    if(a[i][j]==1)
     count[j]++;
  }
 }

  for(i=0;i<8;i++)
  {
   if(count[i]%2==0)
    parity[i]=0;
 }

 for(i=0;i<8;i++)
 {
   if(parity[i]!=a[n-1][i])
    break;
 }

 if(i==8)
  return 1;
 else
  return 0;
}
