#include<stdio.h>
union id
{
 char passport[30];
 char voterid[30];
};
struct employee
{
 union id ids;
 float salary;
 char name[20];
 float exp;
};
main()
{
 struct employee e[5];
 int i,c;
 printf("Enter the Employee Details:\n");
 for(i=0;i<5;i++)
 {
  printf("Enter the Details for Employee %d",i+1);
  printf("\nName:");
  gets(e[i].name);
  printf("Salary:");
  scanf("%f",&e[i].salary);
  printf("Experience:");
  scanf("%f",&e[i].exp);
  printf("Employee Id Type:\n
          1)Passport ID...\n
          2)Voter ID...\n
          Enter your choice:");
  scanf("%d",&c);
  if(c==1)
   scanf("%s",e[i].ids.passport);
  else
   scanf("%s",e[i].ids.voterid);
 }

