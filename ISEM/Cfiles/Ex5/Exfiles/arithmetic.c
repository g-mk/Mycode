
#include<stdio.h>
main()
{
 	int a,b,sum,diff,pro,q;

 	printf("Enter the two numbers:");
 	scanf("%d%d",&a,&b);
 	sum=a+b;
 	diff=((a-b)<0)?-(a-b):(a-b);
 	pro=a*b;
 	q= a/b;
 	printf("Sum of %d and %d is %d",a,b,sum);
 	printf("\nDifference of %d and %d is %d",a,b,diff);
 	printf("\nProduct of %d and %d is %d",a,b,pro);
 	printf("\nQuotient of %d and %d is %d\n\n",a,b,q);

}

