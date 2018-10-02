#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
void main(int argc,char* argv[])
{
 DIR *dir;
 int flag=0;
 struct stat mystat;
 struct dirent *resfile;
 char path[1024];
  getcwd(path,1024);
  if(argc==1)
   {
    dir = opendir(path);
   }
  else if(argc<=2 && strcmp(argv[1],"-l")!=0)
   dir = opendir(argv[1]);
  else if(argc<=2 && strcmp(argv[1],"-l")==0)
  {
   dir=opendir(path);
   flag=1;
  }
  else if(argc<=3 && strcmp(argv[1],"-l")==0)
  {
   dir = opendir(argv[2]);
   flag=1;
  }
   while((resfile = readdir(dir))!=NULL)
   {
     if(flag)
     {
      stat(resfile->d_name,&mystat);
      printf((S_ISDIR(mystat.st_mode)) ? "d" : "-");
      printf((mystat.st_mode & S_IRUSR) ? "r" : "-");
      printf((mystat.st_mode & S_IWUSR) ? "w" : "-");
      printf((mystat.st_mode & S_IXUSR) ? "x" : "-");
      printf((mystat.st_mode & S_IRGRP) ? "r" : "-");
      printf((mystat.st_mode & S_IWGRP) ? "w" : "-");
      printf((mystat.st_mode & S_IXGRP) ? "x" : "-");
      printf((mystat.st_mode & S_IROTH) ? "r" : "-");
      printf((mystat.st_mode & S_IWOTH) ? "w" : "-");
      printf((mystat.st_mode & S_IXOTH) ? "x" : "-");
      printf("  %d  ",(int)mystat.st_nlink);
      printf("%d  ",mystat.st_size);
      printf("%s  ", ctime(&mystat.st_atime));

     }
     printf("%s\n",resfile->d_name);
   }
 closedir(dir);
}
