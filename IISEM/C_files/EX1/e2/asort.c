#include"hSort.h"
main()
{
 int n,i;
 char a[30][30];
 printf("\n Enter the no of cities \n");
 scanf("%d",&n);
 printf("\n Enter city names \n");
 for(i=0;i<n;i++)
 {
  scanf("%s",a[i]);
 }
 swap(a,n);
 printf("\n City names after sorting \n");
 for(i=0;i<n;i++)
 {
  printf("\n%s\n",a[i]);
 }
}

