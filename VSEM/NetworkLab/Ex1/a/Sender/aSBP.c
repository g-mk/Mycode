#include<stdio.h>
main()
{
 int size;
 printf("Enter the number of bits to be transmitted: ");
 scanf("%d",&size);
 singleBitParity(size);
 printf("\n\nSingle Bit Parity Check completed\n\n");
}
