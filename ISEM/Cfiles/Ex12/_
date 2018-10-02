#include<stdio.h>
#include<string.h>
struct student
{
 int reg;
 int m[4];
 int total;
 float average;
 char name[30];
};
main()
{
 struct student s[5];
 int i,j;
 for(i=0;i<5;i++)
  {
   s[i].total=0;
   s[i].average=0;
  }
 printf("Enter the Details for 5 Students:\n ");
 for(i=0;i<5;i++)
 {
  printf("Enter the details for Student %d\n ",i+1);
  printf("Name:");
  scanf(" %[^\n]",s[i].name);
  printf("Reg. No.: ");
  scanf("%d",&s[i].reg);
  for(j=0;j<4;j++)
   {
    printf("\nMark %d: ",j+1);
    scanf("%d",&s[i].m[j]);
    s[i].total+=s[i].m[j];
   }
  s[i].average=s[i].total/4;
  }
 printf("Students Who Scored More Than 50 percent average are :\n");
 for(i=0;i<5;i++)
 {
  if(s[i].average>50)
  {
   printf("\nReg.No: %d",s[i].reg);
   printf("\nName: %s",s[i].name);
   printf("\nMark 1: %d",s[i].m[0]);
   printf("\nMark 2: %d",s[i].m[1]);
   printf("\nMark 3: %d",s[i].m[2]);
   printf("\nMark 4: %d",s[i].m[3]);
   printf("\nTotal: %d",s[i].total);
   printf("\nAverage: %f\n",s[i].average);
  }
 }
}

 
