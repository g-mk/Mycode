#include"hSocket.h"

char * checkDomain(char *domain)
{
    FILE* fp = fopen("DNS.txt","r");
    char name[50],*ip;  
    ip = (char*) malloc(15*sizeof(char));
    while(!feof(fp))
    {
        fscanf(fp,"%s ",name);
        fscanf(fp,"%s",ip);
        if(strcmp(domain,name)==0)
            return ip;
    }
    
    fclose(fp);
    return NULL;

}
int main()
{
 int sid,sid1,len=1024,len1,accpt,accpt1,b=1,b1=1,conn;
 char data[50],*buf,*buf1,nline;
 char* temp ="NULL";
 struct sockaddr_in sin,sin1;
 memset(data,'\0',50);
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
      len = sizeof(sin);
      accpt = accept(sid,(struct sockaddr*)&sin,&len);
      printf("\nDNS Requested Accepted\n");
      recv(accpt,data,50,0);
      
      buf = checkDomain(data);
      
      if(buf != NULL)
          send(accpt,buf,strlen(buf),0);
      else
      {
        sid1=socket(PF_INET,SOCK_STREAM,0);
        if(sid1==-1)
            printf("\n\nSocket failure\n\n");
        else
         {
            printf("\n\nSocket Created\n\n");
            sin1.sin_family = AF_INET;
            sin1.sin_addr.s_addr = htonl(INADDR_ANY);
            sin1.sin_port = htons(9965);
            printf("\nConnecting.....\n");
            conn = connect(sid1,(struct sockaddr*)(&sin1),sizeof(sin1));
            if(conn !=-1)
            {   
                if(send(sid1,data,strlen(data),0)<0) 
                  printf("\nRequest Not Send\n");
                else
                  printf("\nRequest Send\n");
                
                if(recv(sid1,buf1,50,0)<0)
                  printf("\nResponse not Received\n");
                else
                  printf("\nResponse Received\n");
                if(!(strcmp(buf1,"NULL"))){
                  send(accpt,temp,strlen(temp),0);
                }
                else
                   send(accpt,buf1,strlen(buf1),0); 
             close(sid1);
         }
      }
    }
  }
  else 
     printf("\n\nBinding Failed\n\n");
  close(sid);
  }
}

