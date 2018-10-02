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
 int sid,len=1024,accpt,b=1;
 char data[50],*buf,nline;
 char *temp = "NULL";
 struct sockaddr_in sin;
 memset(data,'\0',50);
 sid=socket(PF_INET,SOCK_STREAM,0);

 if(sid==-1)
  printf("\n\nSocket failure\n\n");
 else
 {
  sin.sin_family = AF_INET;
  sin.sin_port = htons(9965);
  sin.sin_addr.s_addr = htonl(INADDR_ANY);
  while(b!=0)
    b = bind(sid,(struct sockaddr *)&sin,sizeof(sin));
    if(b==0)
    {
      printf("\n\nBinded\n\n");
      listen(sid,10);
      accpt = accept(sid,(struct sockaddr*)&sin,&len);
      printf("\nDNS Requested Accepted\n");
      recv(accpt,data,50,0);
      
      buf = checkDomain(data);
      
      if(buf != NULL)
          send(accpt,buf,strlen(buf),0);
      else
      {
        send(accpt,temp,strlen(temp),0);
      }
    }
    else 
     printf("\n\nBinding Failed\n\n");
  }
  close(sid);
  
}

