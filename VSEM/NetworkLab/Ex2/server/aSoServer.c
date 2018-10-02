#include"hSocket.h"
int main()
{
 int sid,len=1024,accpt,b=1;
 char data[100],buf[50];
 struct sockaddr_in sin;
 strcpy(buf,"");
 sid=socket(PF_INET,SOCK_STREAM,0);
 if(sid==-1)
  printf("\n\nSocket failure\n\n");
 else
 {
  sin.sin_family = AF_INET;
  sin.sin_port = htons(9963);
  sin.sin_addr.s_addr = htonl(INADDR_ANY);
  while(b!=0)
    b = bind(sid,(struct sockaddr *)&sin,sizeof(sin));
    if(b==0)
    {
      printf("\n\nBinded\n\n");
      listen(sid,10);
      accpt = accept(sid,(struct sockaddr*)&sin,&len);
    if((recv(accpt,data,100,0))==-1)
     printf("\n\nData Received Failed\n\n");
    else
    {
     printf("\n\nData Received Successful\n\n");
     printf("\n\nReceived Data:%s \n",data);
     printf("Enter the Acknowledgement:");
     scanf("%[^\n]",buf);
     send(accpt,buf,strlen(buf),0);
     printf("\nAcknowledgement Send\n");
    }
    }
    else 
     printf("\n\nBinding Failed\n\n");
  }
  close(sid);
}

