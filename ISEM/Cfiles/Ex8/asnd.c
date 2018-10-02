#include<stdio.h>
main()
{
	int a[10];
	int i,j,temp;
	for(i=0;i<10;i++)
		{
			printf("Enter the element a[%d]:",i+1);
			scanf("%d",&a[i]);
		}

		for(i=0;i<10;i++)
			{
				for(j=i+1;j<10;j++)
					{
						if(a[i]>a[j])
							{
								temp=a[i];
								a[i]=a[j];
								a[j]=temp;
							}
					}
				}
		printf("Sorted List:");
		for(i=0;i<10;i++)
			printf("%d ",a[i]);
	printf("\n\n");

}

