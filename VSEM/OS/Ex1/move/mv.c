#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
void main(int argc,char*argv[])
{
 if(argc>1)
 {
  int rd=open(argv[1],O_RDONLY);
  if(rd!=-1)
  {
   int len = strlen(argv[2]);
   if(argv[2][len-1]=='/')
   {
    char *name=argv[1];
    char file[10],token[30];
    while(strstr(name,"/"))
      {
       name=strstr(name,"/")+sizeof(char);
       strcpy(token,name);
      }
    strcpy(argv[2],token);
   }
   int wr=creat(argv[2],S_IRWXU);
   if(wr==-1)
   {
     wr = open(argv[2],O_WRONLY);
   }
    char out;
    while(read(rd,&out,1)!=0)
    {
     write(wr,&out,1); 
    }
    close(wr);
   }
  close(rd);
  unlink(argv[1]);
 }
}
