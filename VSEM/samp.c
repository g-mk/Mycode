#include<stdio.h>
main()
{
 int a=120,i;
 for(i=128;i>=1;i=i/2)
  printf("%d ",((a&i)?1:0));
}
