#include"hEmp.h"
main()
{
 FILE *fp1;
 char op[20];
 int i,n,ch,ep;
 float s;
 printf("Entr the Output File Name To Store:");
 scanf("%s",&op);
 fp1=fopen(op,"wb");
 printf("Enter the No. of Employee:");
 scanf("%d",&n);
 e=(struct employee *)malloc(n*sizeof(struct employee));
 xtr=(struct employee *)malloc(n*sizeof(struct employee));

 for(i=0;i<n;i++)
 {
  printf("Name:");
  scanf("%s",e[i].name);
  printf("ID:");
  scanf("%d",&e[i].eid);
  printf("Basic Pay:");
  scanf("%f",&e[i].BP);
 }
 calc(e,fp1,n);
 fclose(fp1);
 fp1=fopen(op,"rb");
 free(e);
 printf("Memory Deallocated for Structure Variable..\n");
 printf("Testing after free\n");
 do
 {
  printf("Enter the Choice:\n");
  printf("1)Display the Employee Details..\n2)Display the nth record...\n3)Extract the Employee Detail based on Salarry...\n4)Exit..\n:");
 scanf("%d",&ch);
 switch(ch)
 {
  case 1: display(fp1,xtr,n);
          rewind(fp1);
          break;
  case 2: printf("Enter the Employee No.to print:");
          scanf("%d",&ep); 
          if(ep<=n)
          print(fp1,n,ep);
          else
           printf("There is Only %d Employee in the list\n",n);
          rewind(fp1);
          break;
  case 3: printf("Enter the Salary to extract Greater than that amout:");
          scanf("%f",&s);
          extract(fp1,xtr,n,s);
          rewind(fp1);
          break;
  case 4: printf("Thank You\n");
         break;
  default:printf("Invalid Option...\n");
  }
 }while(ch!=4);
 fcloseall();
}
