#include"hreceiver.h"
main()
{
  int *d,*div,nd,ndiv,i,*result;
  
  printf("\nEnter the number of bits for Divident : ");
  scanf("%d",&nd);

  printf("\nEnter the number of bits for Divisor : ");
  scanf("%d",&ndiv);

  div=(int*) malloc (sizeof(int)*ndiv);

  d=(int*) malloc (sizeof(int)*nd);
  
  result=(int*) malloc (sizeof(int)*4);
 
  for(i=0;i<nd;i++)
    d[i]=0;

  printf("\nEnter the Divident bits : ");
  for(i=0;i<nd;i++)
   scanf("%d",&d[i]);
  

  printf("\nEnter the Divisor Bits : ");
  for(i=0;i<ndiv;i++)
   scanf("%d",&div[i]);
  
   result=calculate_CRC(nd,d,div);
   printf("\nCRC :");
   for(i=1;i<4;i++)
    printf(" %d",result[i]);
   if(result[0]==0 && result[1]==0 && result[2]==0 && result[3]==0)
    printf("\nNo Error in Transmission");
   else
    printf("\nError in transmission");
     printf("\n");
}
