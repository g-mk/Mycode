#include"hFact.h"
main()
{
 printf("Enter the Value for n: ");
 scanf("%d",&n);
 printf("Enter the Value for r: ");
 scanf("%d",&r);
 printf("Value for %dC%d is: ",n,r);
 printf("%ld \n",(fact(n)/(fact(r)*fact(n-r))));
}
