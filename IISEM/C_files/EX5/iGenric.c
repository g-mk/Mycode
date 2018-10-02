#include"hGenric.h"
void sort(void *a,int n,int (*cmptr)(void *,int,int,int),void (*swptr)(struct student *,int, int),int ch)
{
 printf("SORT>>>\n");
 int i,j;
 for(i=0;i<n;i++)
  {
   for(j=0;j<n;j++)
   {
    if(cmptr(a,i,j,ch)==1)
     { 
      swptr(a,i,j);
     }
    }
   }
}
int compare(void *std,int i,int j,int ch)
{
 struct student *a;
 a=(struct student *)std;
 switch(ch)
 {
   case 1: if(strcmp(a[i].name,a[j].name)<0)
             return 1;
           else
             return 0;
            break;
   case 2: if(s[i].adno<a[j].adno)
            return 1;
           else 
             return 0;
            break;
   case 3: if(a[i].sec<a[j].sec)
            return 1;
           else 
            return 0;
           break;
   case 4: if(a[i].avg<a[j].avg)
            return 1;
           else 
            return 0;
 }
}
  
void swap(struct student *std,int i,int j)
{ 
 struct student temp;
 temp =std[i];
 std[i]=std[j];
 std[j]=temp;
}


