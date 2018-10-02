#include"hSocket.h"
int main()
{
 int sid,conn,len;
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
  sin.sin_port = htons(9963);
  sin.sin_addr.s_addr = htonl(INADDR_ANY);
  
   conn = connect(sid,(struct sockaddr*)(&sin),sizeof(sin));
   if(conn !=-1)
   {
    printf("\n\nConnection Established\n\n");
    printf("Enter the data to be transmitted: ");
    scanf("%[^\n]",data);
    len = strlen(data);
    if((send(sid,data,len,0))==-1)
     printf("\n\nData Transmission Failed\n\n");
    else
    {
     printf("\n\nData Transmission Successful\n\n");
     recv(sid,buf,200,0);
      printf("Acknowledge: %s\n",buf);
    close(sid);
    }
   }
   else
    printf("\n\nConnection Not Establishment\n\n");
 }
 close(sid);
}
