#include <unistd.h>
#include <sys/types.h> 
#include <sys/stat.h> 
#include <fcntl.h> 
#include <stdio.h>
#include <string.h>
void main(int argc,char*argv[])
{
 if(argc>3&&(strcmp(argv[1],"-c")==0))
 {
  char line[100],temp,pattern[20];
  int i=0,count=0;
  int in=open(argv[3],O_RDONLY);
  strcpy(pattern,argv[2]);
  while(read(in,&temp,sizeof(char))!=0)
  {
    if(temp!='\n')
      line[i++]=temp;
    else
    {
      line[i]='\0';
      if(strstr(line,pattern)!=NULL)
        count++;
      i=0;
     }
   }
   close(in);
   printf("\nCount %d\n",count);
 }
 else if(argc>2)
 {
  char line[100],temp,pattern[20];
  int i=0;
  int in=open(argv[2],O_RDONLY);
  strcpy(pattern,argv[1]);
  while(read(in,&temp,sizeof(char))!=0)
  { 
    if(temp!='\n')
      line[i++]=temp;
    else
    { 
      line[i]='\0';
      if(strstr(line,pattern)!=NULL)
        printf("%s\n",line);
      i=0;
     }
   }
   close(in);
 }

 else
  printf("grep-command:invalic [OPTION] or file");
}
        
