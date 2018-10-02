#include"hClass.h"
main()
{
 int i,j,k,n[3];
 for(i=0;i<3;i++)
 {
  printf("Enter the number of students in section %c\n",'A'+i);
  scanf("%d",&n[i]);
 }
 for(i=0;i<3;i++)
 {
  printf("Enter details of students in section %c\n",'A'+i); 
  for(j=0;j<n[i];j++)
  {printf("Name:");
   scanf("%s",s[i][j].na);
   printf("Roll Number:");
   scanf("%d",&s[i][j].ro);
   s[i][j].ar=0;
   s[i][j].t=0;
   s[i][j].av=0;
   s[i][j].r=0;
   for(k=0;k<4;k++)
   {
     printf("Mark %d:",k+1);
     scanf("%d",&s[i][j].m[k]);
     s[i][j].t+=s[i][j].m[k];
     if(s[i][j].m[k]<50)
        s[i][j].ar++;
   }
   s[i][j].av=s[i][j].t/4;
  printf("AVERAGE:%f\n",s[i][j].av);
  }
 printf("YYYY");
 }
 printf("III\n");
 ranklist(n);
 /*printf("Class Toppers are:\n");
 for(i=0;i<3;i++)
  {
   printf("Class topper of Class %c is:",'A'+i);
   printf("Name:%s\n",s[i][0].na);
   printf("Roll No.:%d\n",s[i][0].ro);
   printf("Average:%f\n",s[i][0].av);
   printf("Rank:%d\n",s[i][0].r);*/
  
}
