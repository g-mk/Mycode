/*******************************************************************************
**Description   : Executing a new Process/Program using the execv()           **
**                system call.                                                **
**Author        : N. Guru Manikandan.                                         **
**Date Created  : 14/07/2016.                                                 **
**Version       : 0.1                                                         **
*******************************************************************************/
#include <stdio.h>
#include <unistd.h>
void main(int argc,char* argv[])
{
   int flag;
    flag = execv("/bin/date",argv);
    if(flag<0)
      printf("\nCommand Not Found \n");
}
