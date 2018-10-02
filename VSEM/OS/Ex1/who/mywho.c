/*******************************************************************************
**Description   : Implementaion of who command using the system call.         **
**Author        : N. Guru Manikandan.                                         **
**Date Created  : 30/06/2016.                                                 **
**Version       : 0.1                                                         **
*******************************************************************************/
#include<stdio.h>
#include<sys/utsname.h>
#include<utmp.h>
#include<time.h>
#include<string.h>
void main(int argc,char*argv[])
{
 if(argc==1)
 {
  char *logintime;
  struct utmp *detail;
  struct tm *t;
  time_t k;
  detail = getutent();
  while(detail!=NULL)
  {
   if(strcmp(detail->ut_user,"LOGIN")!=0&&strcmp(detail->ut_user,"")!=0&&
          strcmp(detail->ut_line,"~")!=0)
    {
     printf("%s\t",detail->ut_user);
     printf("%s\t",detail->ut_line);
     printf("(%s)\t",detail->ut_host);
     time(detail);
     k = detail->ut_tv.tv_sec;
     logintime = (char *)ctime(&k);
     printf("%s\n",logintime);
     
     //printf("%d-%d-%d %d:%d\n",t->tm_year+1900,t->tm_mon+1,t->tm_mday,t->tm_hour,t->tm_min);
    }
    detail = getutent();
  }
 }
} 
