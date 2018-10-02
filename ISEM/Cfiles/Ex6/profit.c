#include<stdio.h>
main()
{
	int n;
	float cp,sp,pl;
	printf("Enter the Total No. of Items:");
	scanf("%d",&n);
	printf("Enter the Cost of the Items:");
	scanf("%f",&cp);
	printf("Enter the Selling Price:");
	scanf("%f",&sp);
	if(cp==sp)
	{
		printf("\nNeither Profit Nor Loss....\n\n");
	} 
	else if(cp<sp)
	{ 
		printf("\nYou Will Get Profit....");
		pl=(n*sp)-(n*cp);
		printf("\nYour Profit is Rs.%f\n\n",pl);
	}
	else
	{
		printf("\nYou will loss amout....");
		pl=(n*cp)-(n*sp);
		printf("\nYour Loss is Rs.%f\n\n",pl);
	}
}

