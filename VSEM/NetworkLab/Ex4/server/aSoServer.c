#include"hSocket.h"
int main()
{
 int sid,len=1024,accpt,b=1;
 char data[50],buf[50],nline;
 struct sockaddr_in sin;
 sid=socket(PF_INET,SOCK_STREAM,0);
 if(sid==-1)
  printf("\n\nSocket failure\n\n");
 else
 {
  sin.sin_family = AF_INET;
  sin.sin_port = htons(9964);
  sin.sin_addr.s_addr = htonl(INADDR_ANY);
  while(b!=0)
    b = bind(sid,(struct sockaddr *)&sin,sizeof(sin));
    if(b==0)
    {
      printf("\n\nBinded\n\n");
      listen(sid,10);
      accpt = accept(sid,(struct sockaddr*)&sin,&len);
      while(!b)
      {
        if((recv(accpt,data,100,0))==-1)
            printf("\n\nData Received Failed\n\n");
        else
        {
          printf("\n\nData Received Successful\n\n");
          printf("\n\nReceived Data:%s \n\n",data);
          if(strcmp(data,"exit")==0)
          {
            strcpy(buf,data);
            send(accpt,buf,strlen(buf),0);
            printf("\n\nConnection Closed\n\n");
            break;
          }
            strcpy(buf,data);
            send(accpt,buf,strlen(buf),0);
            printf("\n\nMessage Echoed\n\n");
         }
         memset(buf,'\0',sizeof(buf));
         memset(data,'\0',sizeof(data));
      }
    }
    else 
     printf("\n\nBinding Failed\n\n");
  }
  close(sid);
}

