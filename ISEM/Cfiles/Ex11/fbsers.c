#include<stdio.h>
#include<stdlib.h>
main()
{
 int *a,n,i;
 printf("Enter the No. of terms: ");
 scanf("%d",&n);
 a=(int *)malloc(n*sizeof(int));
 a[0]=0;
 a[1]=1;
 for(i=2;i<n;i++)
 {
  a[i]=a[i-2]+a[i-1];
 }
 printf("\nFibanacci Series:\n");
 for(i=0;i<n;i++)
 {
  printf("%d\n",a[i]);
 }
}

