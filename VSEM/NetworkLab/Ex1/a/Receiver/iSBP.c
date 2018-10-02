#include"hSBP.h"
int ParityCheck(int size)
{
 int *data;
 int count=0,loop,parity;
 data = (int*)malloc(sizeof(int)*size+1);
 for(loop=0;loop<size;loop++)
  {
   scanf("%d",&data[loop]);
     count+=data[loop];
  }
  parity = count%2;
 return parity;
}

