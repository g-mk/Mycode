#include"hSocket.h"
int main()
{
 int sid,conn,len;
 char data[100],buf[100],nline,temp[100];
 struct sockaddr_in sin;
 struct sockaddr_in sout;
 sid=socket(PF_INET,SOCK_DGRAM,0);
 if(sid==-1)
  printf("\n\nSocket failure\n\n");
 else
 {
  printf("\n\nSocket Created\n\n");
  
  sin.sin_family = AF_INET;
  sin.sin_port = htons(9968);
  sin.sin_addr.s_addr = htonl(INADDR_ANY);
  
  sout.sin_family = AF_INET;
  sout.sin_port = htons(9977);
  sout.sin_addr.s_addr = htonl(INADDR_ANY);
  
  len = sizeof(sin);
   if(bind(sid,(struct sockaddr*)&sout,sizeof(sout))>0)
    printf("\nError in Binding\n");
  else
  {
      if(fork()==0)
      {
            do
            {
              memset(buf,'\0',sizeof(buf)); 
              recvfrom(sid,buf,100,0,(struct sockaddr*)&sin,&len);
              if(strcmp(temp,"exit")==0)
                return 0;
              printf("\n\n%s \n\n",buf); 
              strcpy(temp,buf);      
            }while(1);
      }
      else
      {      
            do
            {
              memset(data,'\0',sizeof(data));
              printf("\n\n");
              scanf("%[^\n]%c",data,&nline);
              sendto(sid,data,100,0,(struct sockaddr*)&sin,sizeof(sin));
              if(strcmp(data,"exit")==0)
                return 0;
               
            }while(1);
            
      }
  }
 }
 close(sid);
 
}
