/*******************************************************************************
**Description   : Creating a Process Hierachy using the fork() system call.   **
**Author        : N. Guru Manikandan.                                         **
**Date Created  : 14/07/2016.                                                 **
**Version       : 0.1                                                         **
*******************************************************************************/
#include<stdio.h>
#include <unistd.h>
#include <sys/types.h>
void main()
{
   pid_t p2,p3,p4,p5,p6;   
      if((p2=fork())==0)
         {
            printf("Process 2 Id : %d Parent Id: %d\n\n",getpid(),getppid());
            if((p5=fork())==0)
            {
               printf("Process 5 Id : %d Parent Id; %d\n\n",getpid(),getppid());
            }
            else
             {
               if((p6=fork())==0)
                {
                 printf("Process 6 Id : %d Parent Id: %d\n\n",getpid(),getppid());
                }
             } 
          }
       else
        {
          printf("Process 1 Id : %d Parent Id: %d\n\n",getpid(),getppid());
          if((p3=fork())==0)
          {
            if((p4=fork())==0)
             printf("Process 4 Id : %d Parent Id: %d\n\n",getpid(),getppid());
            else
             printf("Process 3 Id : %d Parent Id: %d\n\n",getpid(),getppid());
          }
         
        }         

}  

