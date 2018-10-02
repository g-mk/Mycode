#include"hSocket.h"

int main()
{
 int sid,sid1,sid2,len,len1,accpt,accpt1,b=1,b1=1,conn;
 header h,h2;
 struct sockaddr_in sin,sin1,sin2;
 sid=socket(PF_INET,SOCK_STREAM,0);
 if(sid==-1)
  printf("\n\nSocket failure\n\n");
 else
 {
  sin.sin_family = AF_INET;
  sin.sin_port = htons(8053);
  sin.sin_addr.s_addr = htonl(INADDR_ANY);
  while(b!=0)
    b = bind(sid,(struct sockaddr *)&sin,sizeof(sin));
    if(b==0)
    {
      printf("\n\nBinded\n\n");
      listen(sid,10);
      len = sizeof(sin);
     while(1)
	 {
	   accpt = accept(sid,(struct sockaddr*)&sin,&len);
       printf("\nDNS Requested Accepted\n");
   	   recv(accpt,&h,sizeof(h),0);
       if(strstr(h.name,".google.")!=NULL)
       {
		sid1=socket(PF_INET,SOCK_STREAM,0);
        if(sid1==-1)
            printf("\n\nSocket failure\n\n");
        else
         {
            printf("\n\nSecondary Domain Google\n\n");
            sin1.sin_family = AF_INET;
            sin1.sin_addr.s_addr = htonl(INADDR_ANY);
            sin1.sin_port = htons(8054);
            conn = connect(sid1,(struct sockaddr*)(&sin1),sizeof(sin1));
            if(conn !=-1)
            {   
                send(sid1,&h,sizeof(h),0);

                recv(sid1,&h2,sizeof(header),0);
            }
            send(accpt,&h2,sizeof(h2),0); 
            close(sid1);
		 }  
	   }
       else if(strstr(h.name,".yahoo.")!=NULL)
       {
        sid2=socket(PF_INET,SOCK_STREAM,0);
        if(sid2==-1)
            printf("\n\nSocket failure\n\n");
        else
         {
            printf("\n\nSecondary Domain Yahoo\n\n");
            sin2.sin_family = AF_INET;
            sin2.sin_addr.s_addr = htonl(INADDR_ANY);
            sin2.sin_port = htons(8058);
            conn = connect(sid2,(struct sockaddr*)(&sin2),sizeof(sin2));
            if(conn !=-1)
            {   
                send(sid2,&h,sizeof(h),0); 
                
                recv(sid2,&h2,sizeof(h2),0);
            }
            send(accpt,&h2,sizeof(h),0); 
            close(sid2);
         }
       }
	   else
	   {
	      printf("\nInvalid Domain\n");
		  strcpy(h2.ipaddr,"NULL");
		  send(accpt,&h2,sizeof(h2),0);
	   }
	  } 
  }
  else 
     printf("\n\nBinding Failed\n\n");
  close(sid);
  }
}
 
