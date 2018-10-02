#include"hGenric.h"
main()
{
 int i,j,ch,n;
 printf("Enter the No. of students:");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
  printf("Enter the Name:");
  scanf("%s",&s[i].name);
  printf("Enter the Addmission no.:");
  scanf("%d",&s[i].adno);
  printf("Section:");
  scanf(" %c",&s[i].sec);
  printf("Enter the Percentage of Mark Scored:");
  scanf("%f",&s[i].avg);
 }
 do
 {
 printf("Enter the Choice on what Basis the names to be Sort:\n");
 printf("1)Based on Names..\n2)Based on Addmision No...\n3)Based on Section..\n4)Based on Percentage..\n5)Exit");
 scanf("%d",&ch);
 if(ch !=5)
{
 sort(s,n,compare,swap,ch);
 printf("Sorted list Based On Choice %d is:",ch);
 for(i=0;i<n;i++)
  {
  printf("Name: %s\n",s[i].name);
  printf("Addmission no.: %d\n",s[i].adno);
  printf("Section: %c\n",s[i].sec);
  printf("Percentage of Mark Scored: %f\n",s[i].avg);
  }
 }

 }while(ch!=5);
}

