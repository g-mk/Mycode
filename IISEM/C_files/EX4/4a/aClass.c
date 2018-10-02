#include"hClass.h"
main()
{
 int n,i,j,k,p;
 s=(struct student **)malloc(3*sizeof(struct student *));
 printf("Enter the No of Students in class: ");
 scanf("%d",&n);
 for(i=0;i<3;i++)
 {
  s[i]=(struct student *)malloc(n*sizeof(struct student ));
 }
 for(i=0;i<3;i++)
 {
  for(j=0;j<n;j++)
   {
    s[i][j].total=0;
    s[i][j].avg=0;
    s[i][j].p=1;
    s[i][j].ar=0;
   }
  }  
 for(i=0;i<3;i++)
 {
  for(j=0;j<n;j++)
  {
  printf("Enter the Details Of the Student of class %d\n",i+1);
  printf("Name:");
  scanf("%s",s[i][j].name);
  printf("Reg.No:");
  scanf("%d",&s[i][j].rollno);
  for(k=0;k<4;k++)
  {
   printf("Mark %d:",k+1);
   scanf("%d",&s[i][j].m[k]);
   s[i][j].total+=s[i][j].m[k];
   if(s[i][j].m[k]<50)
   {
    s[i][j].p=0;
    s[i][j].ar+=1;
   }
  }
  s[i][j].avg=s[i][j].total/4;
  printf("Average:%f\n",s[i][j].avg);
  }
 }
 printf("Name\tRoll no\tM1\tM2\tM3\tM4\tTotal\tAvg\tPass\n");
 for(i=0;i<3;i++)
 {
  for(j=0;j<n;j++)
  {
   printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%.2f\t%d\n",s[i][j].name,s[i][j].rollno,s[i][j].m[0],s[i][j].m[1],s[i][j].m[2],s[i][j].m[3],s[i][j].total,s[i][j].avg,s[i][j].p);
  }
 }
 rank(s,n);
}
