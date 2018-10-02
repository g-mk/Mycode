#include<stdio.h>
main()
{
 int a,b,c;
 printf("Enter two values:");
 scanf("%d %d",&a,&b);
 printf("Before Swap:\na=%d\nb=%d",a,b);
 c=a;
 a=b;
 b=c;
 printf("\nAfter Swap:\na=%d\nb=%d\n",a,b);
}

 
