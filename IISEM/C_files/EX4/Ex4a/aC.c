#include"hClass.h"
main()
{
 int n,i,j,k,p;
 //s=(struct student**)malloc(3*sizeof(struct student *));
 printf("Enter the No of Students in class: ");
 scanf("%d",&n);
/* for(i=0;i<n;i++)
 {
  s[i]=(struct student *)malloc(n*sizeof(struct student ));
 }*/
  for(j=0;j<n;j++)
   {
    s[i].total=0;
    s[i].avg=0;
    s[i].p=1;
   }  
  for(i=0;i<n;i++)
  {
  printf("Enter the Details Of the Student of class %d\n",i+1);
  printf("Name:");
  scanf("%s",s[i].name);
  printf("Reg.No:");
  scanf("%d",&s[i].rollno);
  printf("Section:");
  scanf("%d",&s[i].sec);
  for(k=0;k<4;k++)
  {
   printf("Mark %d:",k+1);
   scanf("%d",&s[i].m[k]);
   s[i].total+=s[i].m[k];
   if(s[i].m[k]<50);
    {
    s[i].p=0;
    s[i].ar++;
    }
  }
  s[i].avg=s[i].total/4;
  printf("Average:%f\n",s[i].avg);
  }
  printf("TESTING\n");
 }
 
  for(j=0;j<n;j++)
  {
   printf("NameRoll noM1M2M3M4TotalAvgpass");
   printf("%s\t%d\t%d\t%d\t%d\t%d\t%d\t%f\t%d",s[i].name,s[i].rollno,s[i].m[0],s[i].m[1],s[i].m[2],s[i].m[3],s[i].total,s[i].avg,s[i].p);
  }

 rank(s,n);
 int a=0;
  for(i=0;i<n;i++)
  { if(a==s[i].r)
     {
      printf("Name : %s\n",s[i].name);
      printf("Roll No: %d\n",s[i].rollno);
      printf("Total: %d\n",s[i].total);
      printf("Rank: %d\n",s[i].r);
     }
  }
   printf("Topper in Class A:");
   i=classtoper(s,n,'a');
   printf("Name:%s\n",s[i].name);
   printf("Total:%d\n",s[i].total);
   printf("Average:%f\n",s[i].avg);
 
   printf("Topper in Class B:");
   i=classtoper(s,n,'b');
   printf("Name:%s\n",s[i].name);
   printf("Total:%d\n",s[i].total);
   printf("Average:%f\n",s[i].avg);
 
   printf("Topper in Class C:");
   i=classtoper(s,n,'c');
   printf("Name:%s\n",s[i].name);
   printf("Total:%d\n",s[i].total);
   printf("Average:%f\n",s[i].avg);
  
