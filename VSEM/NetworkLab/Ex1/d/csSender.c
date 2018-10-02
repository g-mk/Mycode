#include<stdio.h>
main()
{
    unsigned char data[10],actual[50];
    int length,it,num,size;
    unsigned int sum=0;
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
    actual[length]=0;
    for(it=0;it<size-1;it++)
    {
        sum+=data[it];
    }
    it=7;
    while(sum!=0)
    {
        actual[length+it]=sum%2;
        sum/=2;
        it--;
    }
    printf("\nSender Data: ");
    for(it=0;it<length;it++)
    {
        printf("%d ",actual[it]);
    }
    printf("\n\nCheck Sum: ");
    for(it=length;it<length+8;it++)
    {
        printf("%d ",actual[it]=(actual[it])?0:1);
    }
   printf("\n\n");

}
