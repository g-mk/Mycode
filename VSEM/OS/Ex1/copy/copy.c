#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
void main(int argc,char*argv[])
{
 if(argc>1)
 {
  int rd=open(argv[1],O_RDONLY);
  if(rd!=-1)
  {
   int wr=creat(argv[2],S_IRWXU);
   char out;
   while(read(rd,&out,1)!=0)
   {
    write(wr,&out,1); 
   }
   close(wr);
   close(rd);
  }
  else
  printf("copy: command-file not found\n");
 }
 else
  printf("copy: command-invalid number of arguments\n");
}
