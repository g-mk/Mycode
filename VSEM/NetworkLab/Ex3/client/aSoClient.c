#include"hSocket.h"
int main()
{
 int sid,conn,len,opt;
 char data[1024],buf[200];
 struct sockaddr_in sin;
 strcpy(buf,"");
 sid=socket(PF_INET,SOCK_STREAM,0);
 if(sid==-1)
  printf("\n\nSocket failure\n\n");
 else
 {
  printf("\n\nSocket Created\n\n");
  sin.sin_family = AF_INET;
  sin.sin_port = htons(9964);
  sin.sin_addr.s_addr = htonl(INADDR_ANY);
  
   conn = connect(sid,(struct sockaddr*)(&sin),sizeof(sin));
   if(conn !=-1)
   {
    printf("\n\nConnection Established\n\n");
    printf("Request Options\n1.Date\n2.Time\n3.Date & Time\n");
    printf("Request: ");
    scanf("%d",&opt);
    if((send(sid,&opt,sizeof(opt),0))==-1)
     printf("\n\nData Transmission Failed\n\n");
    else
    {
     printf("\n\nRequest Transmission Successful\n\n");
     recv(sid,buf,200,0);
      printf("Message: %s\n",buf);
    close(sid);
    }
   }
   else
    printf("\n\nConnection Not Establishment\n\n");
 }
 close(sid);
}
