#include<stdio.h>
main()
{
	int n,r,sum=0;
	printf("Enter the Number:");
	scanf("%d",&n);
	do
		{
			r=n%10;
			sum+=r;
			n=n/10;
		}while(n!=0);
	printf("The sum of the given digits is %d\n\n",sum);
}

