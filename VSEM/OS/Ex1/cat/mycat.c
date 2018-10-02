#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
void main(int argc,char *argv[])
{
 if(argc>0)
 {
  int op=open(argv[1],O_RDONLY);
  if(op!=-1)
  {
   char out;
   while(read(op,&out,1)!=0)
   {
     printf("%c",out);
   }
   close(op);
  }
  else
   printf("\ncat: command-file not found\n");
 }
}
