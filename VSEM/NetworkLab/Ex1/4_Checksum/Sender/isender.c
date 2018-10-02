#include"hsender.h"
int* calculate_checksum(int a[],int b[])
{
 int j,i,a_dec=0,b_dec=0,c_dec,*res;

 res=(int*) malloc (sizeof(int)*8);
  printf("\n1\n");
 for(i=7;i>=0;i--)
 {
   a_dec+=a[i]*pow(2,j);
   b_dec+=b[i]*pow(2,j);
   j++;
 }
 printf("\n2\n");
 c_dec=a_dec+b_dec;

for(i=0;c_dec!=1;i++)
 {
   res[i]=(c_dec%2);
   c_dec=c_dec/2;
 }
  printf("\n3\n");
 if(c_dec==1)
   res[i]=1;
 printf("\n4\n");
 for(j=0;j<=i;j++)
 {
   if(res[j]==1)
     res[j]=0;
   else
     res[j]=1;
 }
  printf("\n5\n");

 return res;
}
