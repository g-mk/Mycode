#include"hSocket.h"

header checkDomain(char *domain)
{
    FILE* fp = fopen("cache.txt","r");
    header record;  
    //record = (header*) malloc(sizeof(header));
    while(!feof(fp))
    {
        fscanf(fp,"%s ",record.name);
        fscanf(fp,"%s ",record.ipaddr);
        fscanf(fp,"%s ",record.type);        
        fscanf(fp,"%s ",record.class);
        fscanf(fp,"%d",&record.ttl);           
        if(strcmp(domain,record.name)==0)
            return record;
    }
    
    fclose(fp);
    strcpy(record.ipaddr,"NULL");
    return record;
}

void updateCache(header record)
{
    FILE *fp = fopen("cache.txt","a");
    
    fprintf(fp,"%s ",record.name);
    fprintf(fp,"%s ",record.ipaddr);
    fprintf(fp,"%s ",record.type);        
    fprintf(fp,"%s ",record.class);
    fprintf(fp,"%d\n",record.ttl);   
    
    fclose(fp);
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
  sin.sin_port = htons(8051);
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
          if(strcmp(buf.ipaddr,"NULL")!=0)
          {
              printf("\nCache Hit\n");
              send(accpt,&buf,sizeof(buf),0);
          }
          else
          {
            printf("\nCache Miss\n");            
            sid1=socket(PF_INET,SOCK_STREAM,0);
            if(sid1==-1)
                printf("\n\nSocket failure\n\n");
            else
            {
                sin1.sin_family = AF_INET;
                sin1.sin_addr.s_addr = htonl(INADDR_ANY);
                sin1.sin_port = htons(8052);
                conn = connect(sid1,(struct sockaddr*)(&sin1),sizeof(sin1));
            if(conn !=-1)
            {   
                send(sid1,&data,sizeof(data),0);
                
                recv(sid1,&buf1,sizeof(header),0);
                  
                if(strcmp(buf1.ipaddr,"NULL")!=0)
                    updateCache(buf1);
                send(accpt,&buf1,sizeof(buf1),0); 
                close(sid1);
            }
          }
        }
    }while(1);
  }
  else 
     printf("\n\nBinding Failed\n\n");
  close(sid);
  }
}

