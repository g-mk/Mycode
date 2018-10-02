#include<stdio.h>
void main()
{
    unsigned char data[10],actual[50];
    int length,it,num,size;
    char sum=0x0;
    printf("Enter the Number of bits to be transmitted: ");
    scanf("%d",&length);
    size=length/8+1;
    printf("Enter the Data\n\n");
    for(it=0;it<length;it++)
    {
        data[it/8]<<=1;
        scanf("%x",&num);
        actual[it]=num;
        data[it/8]|=num;
    }

    for(it=0;it<size-1;it++)
    {
        sum+=data[it];
    }
    printf("Received Data: ");
    for(it=0;it<length-8;it++)
    {
        printf("%d ",actual[it]);
    }
    if(~sum)
        printf("\n\nReceived data is InCorrect\n\n");
    else
        printf("\n\nReceived data is Correct\n\n");
}
