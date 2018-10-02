#include<stdio.h>
long int fact(int x)
{
 long int f=1;
 if(x==0||x==1)
  return 1;
 else
 return x*fact(x-1);
}

main()
{
 int n,r;
 long int nu,dm;
 printf("Enter the value for n:");
 scanf("%d",&n);
 printf("Enter the value for r:");
 scanf("%d",&r);
 printf("\nValue for %dP%d is: ",n,r);
 nu=fact(n);
 dm=fact(n-r);
 printf("%ld ",(nu/dm));
 printf("\nValue for %dC%d is: ",n,r);
 printf("%ld \n\n",(nu/(dm*fact(r))));
}
