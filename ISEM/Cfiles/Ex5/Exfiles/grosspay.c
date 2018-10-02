
#include<stdio.h>
main()
{
 	float hra,da,oa=2000,gp,bp;
	printf("Enter your Basic Pay:");
	scanf("%f",&bp);
	hra = bp*.2;
	da = bp*.1;
	gp = hra+da+oa;
	printf(".............................................");
	printf("\nYour HRA      :%f",hra);
	printf("\nYour Da       :%f",da);
	printf("\nYour OA       :%f",oa);
	printf("\nYour Gross Pay:%f",gp);
	printf("\n..............................................\n\n");
}

