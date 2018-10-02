#include"hsender.h"
main()
{
  int *d,*div,nd,ndiv,c,i,*result;
  
  printf("\nEnter the number of bits for Divident : \n");
  scanf("%d",&nd);

  printf("\nEnter the number of bits for Divisor : \n");
  scanf("%d",&ndiv);

  div=(int*) malloc (sizeof(int)*ndiv);

  d=(int*) malloc (sizeof(int)*(nd+(ndiv-1)));
  
  result=(int*) malloc (sizeof(int)*4);
  c=nd+(ndiv-1);
  for(i=0;i<c;i++)
    d[i]=0;

  printf("\nEnter the Divident bits : ");
  for(i=0;i<nd;i++)
   scanf("%d",&d[i]);
  

  printf("\nEnter the Divisor Bits : ");
  for(i=0;i<ndiv;i++)
   scanf("%d",&div[i]);
  
   result=calculate_CRC(c,d,div);
  
   printf("\nCRC :");
   for(i=1;i<4;i++)
    printf(" %d",result[i]);
   printf("\n");
}
