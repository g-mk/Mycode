#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<signal.h>
void exit_signal(int num)
{
 printf("\nTime Expires...So Please resend the data\n");
 exit(0);
}
main()
{
 int sid,c,frm,ws,i,num;
 char ab[50],msg[50],msg1[50],n[50];
 FILE *fp,*fp1;
 struct sockaddr_in sin; 
 sid=socket(PF_INET,SOCK_STREAM,0);
 sin.sin_family=AF_INET;
 sin.sin_port=htons(17237);
 sin.sin_addr.s_addr=htonl(INADDR_ANY);
 c=connect(sid,(struct sockaddr*)&sin,sizeof(sin));
 if(c==0)
 {
  printf("\nEnter the frame size :");
 scanf("%d",&frm);
 printf("\nEnter the window size :");
 scanf("%d",&ws);
 i=0;
 printf("\nEnter the no of data need to be send :");
 scanf("%s",n);
 strcpy(msg,"null");
 while(frm!=0)
 {
  strcpy(msg,n);
  send(sid,&msg,50,0);
  sscanf(n,"%d",&num);
  ws-=num;
  printf("\nBefore getting the acknowledgement window size is :%d",ws);
 recv(sid,&msg,50,0);
 signal(SIGALRM,exit_signal);
 alarm(10);
 if(strncmp(msg,"ack",3)==0)
 {
  sscanf(msg,"%d",&num);
  ws+=num;
  printf("\nAfter getting an acknowledgement window size is :%d",ws);
  frm-=num;
  printf("\nSuccess......");
  printf("\nEnter the no of data need to be send :");
  scanf("%s",n);
 }
 else if(strncmp(msg,"nack",4)==0)
 {
  ws+=num;
  printf("\nData retransmitted......");
  printf("\nAfter getting the negative acknowledgement window size is :%d",ws);
  strcpy(msg,n);
  send(sid,&msg,50,0);
 }
 }
 close(sid); 
 } 
 else
  printf("\nConnection is not established\n");
}

