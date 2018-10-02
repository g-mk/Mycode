#include"hClass.h"
void rank(struct student **s,int n)
{
 int m=0,top,i,t,f=0,j,k,tot[40],rank=1,a=0;
 for(i=0;i<3;i++)
 {
  for(j=0;j<n;j++)
    {
     if(s[i][j].p==1)
     {
      tot[a]=s[i][j].total;
     a++;
     }
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
  for(j=0;j<3;j++)
   {
    for(k=0;k<n;k++)
     {
      if(tot[i]==s[j][k].total)
       {
        s[j][k].r=i+1;
       // rank++;
       }
     }
   }
 }
 for(i=0;i<3;i++)
 {
  for(j=0;j<n;j++)
  { if(s[i][j].r!=0)
     {
      printf("Name : %s\n",s[i][j].name);
      printf("Roll No: %d\n",s[i][j].rollno);
      printf("Total: %d\n",s[i][j].total);
      printf("Rank: %d\n\n",s[i][j].r);
     }
  }
 }
 printf("NAME          Roll No.        No.of Arrear\n");
for(i=1;i<=4;i++)
 {
  for(j=0;j<3;j++)
   {
    for(k=0;k<n;k++)
    { if(s[j][k].ar==i)
       {
        printf("%s          %d               %d\n",s[j][k].name,s[j][k].rollno,s[j][k].ar);
       }
    }
   }
 }
     
 for(i=0;i<3;i++)
  {m=0;
  // j=classtopper(s,n,i);
   // m=s[i][j].total;
     for(j=0;j<n;j++)
   {
 // printf("\n%d\n",s[i][j].total);
    if(m<s[i][j].total)
      {
       top=j;
       m=s[i][j].total;
      }
   }
   printf("Topper in Class %d\n",i+1);
   printf("Name:%s\n",s[i][top].name);
   printf("Total:%d\n",s[i][top].total);
   printf("Average:%f\n",s[i][top].avg);
  }
}
int classtopper(struct student **s,int n,int c)
{
 int i,j,top,m=s[c][0].total;
  for(i=1;i<n;i++)
   { 
  printf("\n%d\n",s[c][i].total);
    if(m<s[c][i].total)
      {
       top=i;
       m=s[c][i].total;
      }
   }
   return top;
}
