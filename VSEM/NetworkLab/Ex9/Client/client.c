#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<sys/socket.h>
 
void client()
{
 int sid,i=1,conn,nsend,nrecv,nclose;
 char smsg[50],rmsg[2000],nl;
 struct sockaddr_in server;
 sid=socket(AF_INET,SOCK_STREAM,0);
 if(sid==-1)
 {
  printf("\nSocket failure\n");
 }
 else
 {
  server.sin_addr.s_addr = htonl(INADDR_ANY);
	server.sin_family = AF_INET;
  server.sin_port = htons( 15003 );
  conn=connect(sid,(struct sockaddr *)&server,sizeof(server));
  if(conn==-1)
   printf("Connection Problem\n");
  else
  {
   printf("\nConnected\n");
   printf("\n>>");
   scanf("%s",smsg);
   nsend=send(sid,smsg,strlen(smsg),0);
   nrecv=recv(sid,rmsg,2000,0);
   if(strcmp(rmsg,"File Not Found")==0)
   {
    printf("\n%s\n",rmsg);
   }
   else
   {
    FILE *f;
    f=fopen(smsg,"w");
    fprintf(f,"%s",rmsg);
    fclose(f);
    f=fopen(smsg,"r");
    printf("\nFile Contents:\n");
    nl=fgetc(f);
    while(nl!=EOF)
    {
     printf("%c",nl);
     nl=fgetc(f);
    }
    fclose(f);
   }
  }
 }
 while(i)
  i=close(sid);
}
main()
{
 client();
}
