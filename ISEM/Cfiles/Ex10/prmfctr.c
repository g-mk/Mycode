#include<stdio.h>
void prime(int);
void factor(int x)
{
 int i;
 for(i=2;i<=x;i++)
  if(x%i==0)
   prime(i);
}
void  prime(int a)
{
 int i,c=0;
 for(i=2;i<a;i++)
 {
  if(a%i==0)
   {
   c++;
   break;
   }
 }
 if(c==0)
 {
 printf("%d ",a);
 }

}

main()
{
 int n;
 printf("Enter the Number:");
 scanf("%d",&n);
 printf("Prime Factor of the given values %d are:  ",n);
 factor(n);
 printf("\n\n");
}
