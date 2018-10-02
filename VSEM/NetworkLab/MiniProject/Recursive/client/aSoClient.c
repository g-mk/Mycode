#include"hSocket.h"
int main(int argc,char *argv[])
{
  int sid,conn,len,loop=0;
  int port = 8051;
  header data,buf,nline;
  struct sockaddr_in sin;
  if(argc>1)
  {  
     strcpy(data.name,argv[1]);   
     sid=socket(PF_INET,SOCK_STREAM,0);
     if(sid==-1)
      printf("\n\nSocket failure\n\n");
     else
     {
        sin.sin_family = AF_INET;
        sin.sin_addr.s_addr = htonl(INADDR_ANY);
        sin.sin_port = htons(port);
        conn = connect(sid,(struct sockaddr*)(&sin),sizeof(sin));
        if(conn !=-1)
        {   
            send(sid,&data,sizeof(data),0);
            recv(sid,&buf,sizeof(buf),0);
            
            if(!(strcmp(buf.ipaddr,"NULL"))){
              printf("\nDNS Not Found\n");
            }
            else
            {
                printf("\nHOST NAME: %s\n",buf.name);
                printf("ADDRESS : %s\n",buf.ipaddr);
                printf("TYPE : %s\n",buf.type);
                printf("CLASS : %s\n",buf.class);
                printf("TTL: %d\n\n",buf.ttl);
            }
            close(sid);
         }
      }
    }
    else
        printf("\nInvalid Command\n");
 }
 
