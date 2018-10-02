#include"hMsort.h"
main()
{
 int a[20],b[20],m,l,n,i, *c;
 printf("enter the No. of value for array 1:");
 scanf("%d",&m);
 printf("enter the No. of value for array 2:");
 scanf("%d",&n);
 printf("Enter the values for 1st array:");
// c=(int*)malloc(m+n*sizeof(int));
 for(i=0;i<m;i++)
  scanf("%d",&a[i]);
 printf("Enter the values for 2st array:");
 for(i=0;i<n;i++)
  scanf("%d",&b[i]);
 c=merge(a,b,m,n);
 l=sort(c,m+n);
 printf("\nMerged and sorted list:");
 for(i=0;i<l;i++)
  printf("\n%d\n",*(c+i));
}


 

