#include<stdio.h>
main()
{
	int a[5][5];
	int i,j;
	for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
				{
				  printf("Enter the elements a[%d][%d]:",i+1,j+1);
					scanf("%d",&a[i][j]);
				}
		}
	printf("Given Matrix is...\n");

	for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
				{
					printf("%d\t",a[i][j]);

				}	
			printf("\n");
		}

	printf("Transpose of the Given Matrix is....\n");
	
	for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
				{
					printf("%d\t",a[j][i]);
				}
			printf("\n");
    
		}
	printf("\n\n");

}
	
