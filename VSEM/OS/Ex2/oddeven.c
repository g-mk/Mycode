/*******************************************************************************
**Description   : Generating the 'n' odd and even numbers in separate process **
**                using the fork() system call.                               **
**Author        : N. Guru Manikandan.                                         **
**Date Created  : 30/06/2016.                                                 **
**Version       : 0.1                                                         ** 
*******************************************************************************/
#include<stdio.h>
#include<unistd.h>
void main()
{
   pid_t p1;
   int odd=1,even=0,count,count1;
   printf("Enter the number of odd and even numbers to display: ");
   scanf("%d",&count);
   count1 = count;
   p1 = fork();
   if(p1==0)
   {
      printf("Child Process\n\n");
      while(count)
      {
         printf("%d ",odd+=2);
         count--;
       }
      printf("\n");
   }
   else
   {
      printf("Parent Process\n\n");
      while(count1)
      {
         printf("%d ",even+=2);
         count1--;
       }
       printf("\n\n");
   }
}
