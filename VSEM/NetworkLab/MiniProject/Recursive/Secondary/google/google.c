#include"hSocket.h"

header checkDomain(char *domain)
{
    FILE* fp = fopen("google.txt","r");
    header record;  
    while(!feof(fp))
    {
        fscanf(fp,"%s",record.name);
        fscanf(fp,"%s",record.ipaddr);
        fscanf(fp,"%s",record.type);        
        fscanf(fp,"%s",record.class);
        fscanf(fp,"%d ",&record.ttl);            
        if(strcmp(domain,record.name)==0)
            return record;
    }
    
    fclose(fp);
    strcpy(record.ipaddr,"NULL");
    return record;
}

int main()
{
 int sid,sid1,len=1024,len1,accpt,accpt1,b=1,b1=1,conn;
 header data;
 header buf,buf1;
 struct sockaddr_in sin,sin1;
 sid=socket(PF_INET,SOCK_STREAM,0);

 if(sid==-1)
  printf("\n\nSocket failure\n\n");
 else
 {
  sin.sin_family = AF_INET;
  sin.sin_port = htons(8054);
  sin.sin_addr.s_addr = htonl(INADDR_ANY);
  while(b!=0)
    b = bind(sid,(struct sockaddr *)&sin,sizeof(sin));
  if(b==0)
  {
      printf("\n\nBinded\n\n");
      listen(sid,10);
      len = sizeof(sin);
      do
      {
          accpt = accept(sid,(struct sockaddr*)&sin,&len);
          printf("\nDNS Requested Accepted\n");
          recv(accpt,&data,sizeof(header),0);        
          buf = checkDomain(data.name);
          printf("Name : %s\n",buf.name);
          send(accpt,&buf,sizeof(header),0);
      }while(1);
  }
  else 
     printf("\n\nBinding Failed\n\n");
  close(sid);
  }
}

