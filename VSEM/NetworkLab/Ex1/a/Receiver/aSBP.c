#include<stdio.h>
main()
{
 int *data;
 int size,count=0,loop,parity;
 printf("Enter the number of bits to be received: ");
 scanf("%d",&size);
	parity = ParityCheck(size);
 if(parity==0)
  printf("\nNo Error in the data\n");
 else
  printf("\nSingle Bit Error is Detected\n");
}
