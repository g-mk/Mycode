#include"hreceiver.h"
int* calculate_CRC(int size,int *d,int*div)
{
  int i,*res,h=4,c=size;
  res=(int*) malloc (sizeof(int)*4);
   for(i=0;i<4;i++)
     res[i]=d[i]^div[i];
  while(h<c)
  {

    if(res[0]==0 && res[1]==0 && res[2==0])
    {
        for(i=0;(i+1)<4;i++)
         res[i]=res[i+1];

       for(i=0;(i+1)<4;i++)
        res[i]=res[i+1];

       for(i=0;(i+1)<4;i++)
        res[i]=res[i+1];

       res[1]=d[h];
       res[2]=d[h+1];
       res[3]=d[h+2];
       h=h+3;
    }
    else if(res[0]==0 && res[1]==0)
    {

      for(i=0;(i+1)<4;i++)
       res[i]=res[i+1];

     for(i=0;(i+1)<4;i++)
        res[i]=res[i+1];

      res[2]=d[h];
      res[3]=d[h+1];
      h=h+2;
    }
    else if(res[0]==0)
    {
       for(i=0;(i+1)<4;i++)
        res[i]=res[i+1];

        res[3]=d[h];
        h=h+1;
   }
   for(i=0;i<4;i++)
    res[i]=res[i]^div[i];
    if(h==c)
      break;
  }
   return res;
}
