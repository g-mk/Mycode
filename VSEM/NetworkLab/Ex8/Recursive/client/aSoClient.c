#include"hSocket.h"
int main()
{
  int sid,conn,len,loop=0;;
  int port = 9964;
  char data[50],buf[50],nline;
  struct sockaddr_in sin;
  strcpy(buf,"NULL");
 
  printf("\nDomain Name:");
  scanf("%s",data);
        
     sid=socket(PF_INET,SOCK_STREAM,0);
     if(sid==-1)
      printf("\n\nSocket failure\n\n");
     else
     {
        printf("\n\nSocket Created\n\n");
        sin.sin_family = AF_INET;
        sin.sin_addr.s_addr = htonl(INADDR_ANY);
        sin.sin_port = htons(9964);
        printf("\nConnecting.....\n");
        conn = connect(sid,(struct sockaddr*)(&sin),sizeof(sin));
        if(conn !=-1)
        {   
            if(send(sid,data,strlen(data),0)<0) 
              printf("\nRequest Not Send\n");
            else
              printf("\nRequest Send\n");
            
            if(recv(sid,buf,200,0)<0)
              printf("\nResponse not Received\n");
            else
              printf("\nResponse Received\n");
            if(!(strcmp(buf,"NULL"))){
              printf("\nDNS Not Found\n");
            }
            close(sid);
         }
        }
  
  printf("\nDNS Response Message: %s\n",buf);
 }
 
