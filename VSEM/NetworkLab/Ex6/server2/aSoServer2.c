#include"hSocket.h"
int main()
{
 int sid,len=1024,accpt,b=1;
 char data[50],buf[50],nline;
 char *IP = "172.16.16.24";
 char *MAC = "a1:b2:0c:ds:0d:24";
 struct sockaddr_in sin;
 sid=socket(PF_INET,SOCK_STREAM,0);
 if(sid==-1)
  printf("\n\nSocket failure\n\n");
 else
 {
  sin.sin_family = AF_INET;
  sin.sin_port = htons(9966);
  sin.sin_addr.s_addr = htonl(INADDR_ANY);
  while(b!=0)
    b = bind(sid,(struct sockaddr *)&sin,sizeof(sin));
    if(b==0)
    {
      printf("\n\nBinded\n\n");
      listen(sid,10);
      accpt = accept(sid,(struct sockaddr*)&sin,&len);
      recv(accpt,data,200,0);
      if(strcmp(data,IP)==0)
        strcpy(buf,MAC);
      else
        strcpy(buf,"NULL");
      
      send(accpt,buf,strlen(buf),0);
    }
    else 
     printf("\n\nBinding Failed\n\n");
  }
  close(sid);
}

