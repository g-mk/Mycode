#include<stdio.h>
#include<math.h>
main()
{
    unsigned char divisor=0x0,crc=0x0;
    int it,temp,max,data[50],length,num,dLength;
    printf("Enter the number of bits to be transmitted: ");
    scanf("%d",&length);
    printf("Enter the Data: \n");
    for(it=0;it<length;it++)
    {
        scanf("%d",&data[it]);
    }
    printf("Enter the length of divisor: ");
    scanf("%d",&dLength);
    max=(int)(pow(2,dLength-1)-1);
    for(it=0;it<dLength;it++)
    {
        divisor<<=1;
        scanf("%x",&num);
        divisor|=num;
    }
    for(it=0;it<dLength-1;it++)
        data[length+it]=0;
    length +=dLength;

    for(it=0;it<dLength;it++)
    {
        crc<<=1;
        crc|=data[it];
    }
    for(it=dLength;it<length;it++)
    {
        if(crc>max)
        {
            crc = crc^divisor;
            if(it+1<length)
            {
                crc<<=1;
                crc|=data[it];
            }
        }
        else
        {
            crc<<=1;
            crc|=data[it];
        }
    }
    crc&=max;
    temp=length-2;
    while(crc!=0)
    {
        data[temp--]=crc%2;
        crc/=2;
    }
    printf("Transmitted Data : ");
    for(it=0;it<length-1;it++)
        printf("%d ",data[it]);
    printf("\n\n");
}
