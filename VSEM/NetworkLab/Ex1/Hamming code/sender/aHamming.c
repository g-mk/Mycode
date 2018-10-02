#include"hamming.h"
int main()
{
    int it,size,totSize,*data,*transData,temp=0;
    printf("Enter the Number of bits to be transmited: ");
    scanf("%d",&size);
    data= (int*)malloc(size*sizeof(int));
    totSize=calcTolBit(size);
    transData = (int*)malloc(totSize*sizeof(int));
    for(it=0;it<totSize;it++)
        transData[it]=0;
    printf("Enter the data to transmit: \n");
    for(it=0;it<size;it++)
    {
        scanf("%d",&data[it]);
    }

    for(it=0;it<totSize;it++)
    {
        if((it+1)!=pow(2,temp))
        {
            transData[it]=data[size-1];
            size--;
        }
        else
            temp++;
    }
    computeHamming(transData,totSize);
    printf("Hamming Code Generated for the given data :\n");
    for(it=totSize-1;it>=0;it--)
    {
        printf("%d ",transData[it]);
    }
    printf("\nRedundancy Bits: ");
    for(temp=1;temp<totSize;temp=pow(2,temp))
      printf("%d  ",transData[temp-1]);
    printf("\n");
}
