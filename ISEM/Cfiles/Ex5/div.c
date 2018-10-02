#include<stdio.h>
main()
{
 int n;
 printf ("Enter the Value:");
 scanf("%d",&n);
  if(n%4==0 && n%6==0)
      printf("Given No. %d is Divisible by 2,3,4&6",n);
  else 
      printf("Given NO. %d is not Divisible by 2,3,4&6",n);
}


