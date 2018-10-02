#include"hSocket.h"
int main()
{
 int sid,conn,len;
 char data[1024],buf[1024],nline;
 struct sockaddr_in sin;
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
    printf("\n\nConnection Established...\n\n");
    do
    {
      printf("\n\nEnter the File Name with extention: ");
      scanf("%[^\n]%c",data,&nline);
      
      len = strlen(data);
      if((send(sid,data,len,0))==-1)
        printf("\n\nRequest Transmission Failed\n\n");
      else
      {
        printf("\n\nRequest Transmission Successful\n\n");
        recv(sid,buf,1024,0);
        printf("\n\nMessage: %s \n\n",buf);
        if(strcmp(buf,"NOT FOUND")!=0)
        {
          memset(buf,'\0',sizeof(buf));        
          recv(sid,buf,1024,0);
          printf("\n\n************Content of the File**************\n\n");
          printf("\n%s\n",buf);
        }   
      }

      if(strcmp(data,"exit")==0)
      {
          printf("\n\nConnection Terminated\n\n");
          break;
      }
 
      memset(buf,'\0',sizeof(buf));
      memset(data,'\0',sizeof(data));
     }while(conn!=-1);
    }
   else
    printf("\n\nConnection Not Established...\n\n");
 }
 close(sid);
 
}
