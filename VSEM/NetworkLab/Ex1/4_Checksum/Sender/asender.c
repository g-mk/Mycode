#include"hsender.h"
main()
{
 int j=0,a[8],b[8],*res,i;

 res=(int*) malloc (sizeof(int)*8);
 printf("\nEnter the first 8 bits: ");
 for(i=0;i<8;i++)
   scanf("%d",&a[i]);

 printf("\nEnter the second 8 bits: ");
 for(i=0;i<8;i++)
   scanf("%d",&b[i]);


 printf("\nThe data to be transmitted is: \n");
 for(i=0;i<8;i++)
  printf(" %d",a[i]);
  printf("\n");

 for(i=0;i<8;i++)
  printf(" %d",b[i]);
 printf("\n");

 res=calculate_checksum(a,b); 

 printf("\nCheck Sum: ");
 for(i=7;i>=0;i--)
 {
   printf(" %d",res[i]);
 }
 printf("\n");
 free(res);
}
