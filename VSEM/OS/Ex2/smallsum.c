/******************************************************************************
**Description   : Finding the smallest number in even position and sum of all**
**                the number in the odd position in two different process    **
**                using the fork() system call.                              **
**Author        : N. Guru Manikandan.                                        **
**Date Created  : 30/06/2016.                                                **
**Version       : 0.1                                                        **
******************************************************************************/
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{
   int *array,size,loop,it,sum=0,small;
   pid_t id;
   printf("Enter the array size: ");
   scanf("%d",&size);
   array = (int *)malloc(sizeof(int)*size);
   for(loop=0;loop<size;loop++)
   {
      printf("Ente the element %d: ",loop+1);
      scanf("%d",&array[loop]);
   }
   
   id = fork();
   if(id==0)
   {
      printf("\n\nChild Process\n\n");
      for(loop=0;loop<size;loop++)
       if(loop%2==0)
         sum+=array[loop];
      printf("Sum of odd place number: %d\n\n",sum);
   }
   else
   {
      printf("\n\nParent Process\n\n");
      small = array[1];
      for(it=2;it<size;it++)
      {
         if(it%2==1)
         {
            if(array[it]<small)
               small=array[loop];
         }
      }
      printf("Smallest number in the even position is %d\n\n",small);
   }      
}

