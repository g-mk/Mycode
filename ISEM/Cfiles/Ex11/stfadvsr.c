#include<stdio.h>
#include<stdlib.h>
main()
{
 int *std,n,i,s1[50],s2[50],o=0,e=0;
 printf("Enter the Total Number of Students: ");
 scanf("%d",&n);
 std= (int*)malloc(n*sizeof(int));
 printf("\nEnter the Roll No. For the Students:\n");
 for(i=0;i<n;i++)
 {
  scanf("%d",&std[i]);
 }
 for(i=0;i<n;i++)
 {
  if(std[i]%2==0)
  {
   s2[e]=std[i];
   e++;
  }
  else
  {
   s1[o]=std[i];
   o++;
  }
 }
 printf("Staff Advisor 1:\n");
 for(i=0;i<o;i++)
 {
  printf("%d) %d\n",i+1,s1[i]);
 }
 printf("Staff Advisor 2:\n");
 for(i=0;i<e;i++)
 {
  printf("%d) %d\n",i+1,s2[i]);
 }
}

