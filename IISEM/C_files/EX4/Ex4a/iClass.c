#include"hClass.h"
void ranklist(int n[20])
{
 struct student std; 
 int ai,resu[20][20],l;
 int i,x=0,j,k,r[80],temp,rank=0;
 printf("LI\n");
for(i=0;i<3;i++)
 {
  for(j=0;j<n[i];j++)
  {
   r[x]=(s[i][j].t);
   x++;
  }
 }
printf("LII\n");
for(i=0;i<x;i++)
  {
    for(j=i+1;j<x;j++)
    {
      if(r[i]<r[j])
      {
        temp=r[j];
        r[j]=r[i];
        r[i]=temp;
      }
    }
  }
 printf("LIII\n");
 for(i=0;i<3;i++)
 {
  for(j=0;j<n[i];j++)
  {
   for(k=j+1;k<n[i];j++)
     {
      if(s[i][j].t<s[i][k].t)
       {
        std=s[i][j];
        s[i][j]=s[i][k];
        s[i][k]=std;
       }
      }
    }
  }
 printf("LIII %d\n",x);
 for(i=0;i<x;i++)
  {printf("i\n");
   for(j=0;j<3;j++)
    {printf("j\n");
     for(k=0;k<n[i];k++)
      {printf("k\n");
       if(r[i]==s[j][k].t)
        { rank++;
          s[j][k].r=rank;
        }
      }
    }
  }
  printf("LIIII\n");
  printf("Class Toppers are:\n");
 for(i=0;i<3;i++)
  {
   printf("Class topper of Class %c is:",'A'+i);
   printf("Name:%s\n",s[i][0].na);
   printf("Roll No.:%d\n",s[i][0].ro);
   printf("Average:%f\n",s[i][0].av);
   printf("Rank:%d\n",s[i][0].r);
 }
 printf("Ranklist:\n");
 l=1;
 for(i=0;i<3;i++)
 {
  for(j=0;j<n[i];j++)
  {if(l==s[i][j].r)
    {
   printf("Name:%s\n",s[i][0].na);
   printf("Roll No.:%d\n",s[i][0].ro);
   printf("Average:%f\n",s[i][0].av);
   printf("Rank:%d\n",s[i][0].r);
   }l++;
  }
 }

}
 

/*ai=0;

 for(l=0;l<5;l++)
  {
  for(k=x-1;k>=0;k--)
   {
   for(i=0;i<3;i++)
   {
    for(j=0;j<n[i];j++)
    {
    if(s[i][j].ar==l)
     {if(r[k]==-1)
      {rank=rank-1;}
       if(r[k]==s[i][j].t)
       {
        resu[ai][0]=j+1;
        resu[ai][1]=i+1;
        resu[ai][2]=s[i][j].ro;
        resu[ai][3]=rank+1;
        resu[ai][4]=s[i][j].t;
        resu[ai][5]=s[i][j].ar;   
       printf("The student %d of section %d with Rollnumber %d is rank %d\n",j+1,i+1,s[i][j].ro,rank+1);                                     
     rank++; ai++;
      }
     }
    }
   }
  }
 }

  for(i=0;i<3;i++)
  {
   
   for(j=0;j<n[i];j++)   
   { s[i][j].count=0;
    for(l=0;l<5;l++)
    {
    if(s[i][j].ar==l)
    {
     for(k=x-1;k>=0;k--)
     {
      if(r[k]==s[i][j].t)
      {
       printf(" The topper of  section %d is student of Rollnumber %d\n",i+1,s[i][j].ro);
        s[i][j].count=1;
      }
      if(s[i][j].count==1)
      {
        break;
      }
     }

    }
     if(s[i][j].count==1)
    {
     break;
    } 
   }
   if(s[i][j].count==1)
   {
    break;
   }
   }
  }
printf(" student no:-     section      Rollnumber       arrear      total           rank");
for(ai=0;ai<rank;ai++)
{
//printf("The student number      section      Rollnumber       arrear      total     rank");
printf("   %d                  %d             %d             %d         %d             %d\n",resu[ai][0],resu[ai][1],resu[ai][2],resu[ai][5],resu[ai][4],resu[ai][3]);
}
}*/
