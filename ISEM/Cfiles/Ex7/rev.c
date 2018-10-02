#include<stdio.h>
main()
{
	int rev=0,r,n;
	printf("Enter the Number:");
	scanf("%d",&n);
	while(n!=0)
		{
			r=n%10;
			rev=(rev*10)+r;
			n=n/10;
		}
	printf("The reverse of the given Number is: %d\n",rev);
	printf("The number Given in words is: ");
	while(rev!=0)
		{
			r=rev%10;
			switch(r)
				{
					case 0:printf("ZERO  ");
								break;
					case 1:printf("ONE  ");
								break;
					case 2:printf("TWO  ");
								break;
					case 3:printf("THREE  ");
								break;
					case 4:printf("FOUR  ");
								break;
					case 5:printf("FIVE  ");
								break;
					case 6:printf("SIX  ");
								break;
					case 7:printf("SEVEN  ");
								break;
					case 8:printf("EIGHT  ");
								break;
					case 9:printf("NINE  ");
				}
			rev=rev/10;
		}
	printf("\n\n");
}


