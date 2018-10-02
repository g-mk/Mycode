#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
void main()
{
   pid_t p1,p2,p3,p4,p5,p6;
      
      p2=fork();
      if(p2==0)
         {
            p5=fork();
            if(p5==0)
               printf("Process 5, Id %d\n",getpid());
            else
               printf("Process 5 not initiated\n");
            p6=fork();
            if(p6==0)
               printf("Process 6, Id %d \n",getpid());
            else
               printf("Process 6 not initiated\n");
         }
      else
         printf("Process 1, Id %d \n",getpid());
      p3=fork();
      if(p3==0)
         {
            p4=fork();
            if(p4==0)
               printf("Process 4, Id %d \n",getpid());
            else
               printf("Process 3, Id %d \n",getpid());
         }
      else
         printf("Process 1, Id %d \n",getpid());
      
}  

