#include <stdio.h>
#include <unistd.h>
void main(int argc,char* argv[])
{
    int flag;
    flag = execv("/bin/ct",argv);
    if(flag<0)
      printf("\nCommand Not Found :%d \n",flag);
 
}
