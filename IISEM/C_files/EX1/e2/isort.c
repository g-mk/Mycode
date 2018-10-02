#include"hSort.h"
void swap(char a[30][30],int n)
{
 int i,j;
 char b[30];
 for(i=0;i<n;i++)
 {
  for(j=i+1;j<n;j++)
  {
   if(strcmp(a[i],a[j])>0)
   {
    strcpy(b,a[i]);
    strcpy(a[i],a[j]);
    strcpy(a[j],b);
   }
  }
 }
}
