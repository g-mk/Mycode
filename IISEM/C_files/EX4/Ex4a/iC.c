#include"hClass.h"
void rank(struct student *s,int n)
{
 int i,t,j,k,tot[40],a=0;
  for(j=0;j<n;j++)
   {
    if(s[i].p==1)
     {
      tot[a]=s[i].total;
     a++;
     }
    }
 for(i=0;i<a;i++)
 {
  for(j=i+1;j<a;j++)
   {
    if(tot[i]<tot[j])
     {
      t=tot[i];
      tot[i]=tot[j];
      tot[j]=t;
     }
   }
 }
 for(i=0;i<a;i++)
 {
    for(k=0;k<n;k++)
     {
      if(tot[i]==s[i].total)
       s[i].r=i+1;
     }
 }
 for(i=0;i<n;i++)
 {
  for(j=i+1;j<n;j++)
  {
    if(s[i].r>s[j].r) 
     {
      struct student t;
       t=s[i];
       s[i]=s[j];
       s[j]=t;
     }
   }
  }
} 
}
int classtopper(struct student *std,int n,char c)
{
 int i,j,top,m=0;
 
  for(i=0;i<n;i++)
   { if(s[i].sec==c)
    {
      if(m<std[i].total)
      {
       top=i;
       m=std[i].total;
      }
    }
   }
  return top;
}
  
  
