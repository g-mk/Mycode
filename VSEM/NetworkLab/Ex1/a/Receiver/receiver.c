#include<stdio.h>
main()
{
 int *data;
 int size,count=0,loop,parity;
 printf("Enter the number of bits to be received: ");
 scanf("%d",&size);
 data = (int*)malloc(sizeof(int)*size+1);
 for(loop=0;loop<size;loop++)
  {
   scanf("%d",&data[loop]);
     count+=data[loop];
  }
	parity = count%2;
 if(parity==0)
  printf("\nNo Error in the data\n");
 else
  printf("\nSingle Bit Error is Detected\n");
}
