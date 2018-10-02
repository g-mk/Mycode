#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<signal.h>
void give_signal(int num)
{
 printf("\nTime Expires...You have to resend the data\n");
 exit(0);
}
main()
{
 int sid,a,l,b,len,n,num,ws,frm,flag=0;
 char msg[50],msg1[50],c;
 FILE *fp1;
 struct sockaddr_in sin,sin1; 
  sid=socket(PF_INET,SOCK_STREAM,0);
  if(sid<0)
   printf("\nError in Socket creation\n");
  printf("\nSocket created successfully\n");
  sin.sin_family=AF_INET;
  sin.sin_port=htons(17237);
  sin.sin_addr.s_addr=htonl(INADDR_ANY);
  b=bind(sid,(struct sockaddr*)&sin,sizeof(sin));
  len=sizeof(sin);
  l=listen(sid,2);
  a=accept(sid,(struct sockaddr*)& sin,&len);
  if(a!=-1)
  {
   printf("\nEnter the frame size :");
   scanf("%d",&frm);
   printf("\nEnter the window size :");
   scanf("%d",&ws);
   recv(a,&msg,50,0);
    while(flag!=frm)
    {
     sscanf(msg,"%d",&num);
     ws+=num;
     printf("\nBefore sending an acknowledgement window is :%d",ws);
     printf("\nWhether I need to send an acknowledgement or not?(yes/no) :");
     scanf("%s",msg1);
     signal(SIGALRM,give_signal);
     alarm(10);
     if((strncmp(msg1,"yes",3)==0))
     {
      flag+=num;
      ws-=num;
      printf("After sending the acknowledgement window size is :%d",ws);
      strcpy(msg,"ack");
      send(a,&msg,50,0);
     recv(a,&msg,50,0);
    }
    else if((strncmp(msg1,"no",2)==0))
    {
     ws-=num;
     printf("Before sending negative acknowledgement window size is :%d",ws);
     strcpy(msg,"nack");
     send(a,&msg,50,0);
     recv(a,&msg,50,0);
    }
    }
    close(sid);
  }
  else
   printf("\nConnection is not yet established\n");
}


