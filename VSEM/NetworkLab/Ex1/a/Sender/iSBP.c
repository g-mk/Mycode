#include"hSBP.h"
void singleBitParity(int size)
{
 int *data;
 int count=0,loop;
 data = (int*)malloc(sizeof(int)*size+1);
 for(loop=0;loop<size;loop++)
  {
   scanf("%d",&data[loop]);
     count+=data[loop];
  }
  data[size]=count%2;
 printf("Data to be transmitted is ");
 for(loop=0;loop<size+1;loop++)
  printf("%d",data[loop]);
 printf("\n");
}
