#include "hFile.h"
long int sum(FILE *f,int n)
{
 long int sum=0;
 int i,d;
 for(i=0;i<n;i++)
  {
   fscanf(f,"%d",&d);
   printf("%d\n",d);
   sum += d;
  }
 return sum;
}

