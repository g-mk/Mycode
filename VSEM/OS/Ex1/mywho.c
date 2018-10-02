#include<stdio.h>
#include<sys/utsname.h>
#include<utmp.h>
#include<time.h>
#include<string.h>
void main(int argc,char*argv[])
{
 if(argc==1)
 {
  struct utmp *detail;
  struct tm *time,*time1;
  detail = getutent();
  while(detail!=NULL)
  {
   if(strcmp(detail->ut_user,"LOGIN")!=0&&strcmp(detail->ut_user,"")!=0&&
          strcmp(detail->ut_line,"~")!=0)
    {
     printf("%s\t",detail->ut_user);
     printf("%s\t",detail->ut_line);
     printf("(%s)\t",detail->ut_host);
     //time = gmtime(&detail->ut_time);
     time=localtime(&detail->ut_time);
     printf("%d-%d-%d %d:%d\n",time->tm_year+1900,time->tm_mon+1,time->tm_mday,time->tm_hour,time->tm_min);
    }
    detail = getutent();
  }
 }
} 
