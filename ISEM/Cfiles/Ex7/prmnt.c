#include<stdio.h>
main()
{
	int n,i=2,c=0;
	printf("Enter the Number:");
	scanf("%d",&n);
	if(n==1)
	{
		printf("Given Number is Neither Prime Nor Composite number\n");
		c=1;
	}

	for(;i<=n/2;i++)
		{
			if(n%i==0)
				{ 
					printf("Given Numberis Not a Prime Number \n ");
					c=1;
					break;
				}
		}
	if(c==0)
		printf("Given Number is Prime Number\n\n");


}

