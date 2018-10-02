#include<stdio.h>
main()
{
    int **data,row,column=8,size,loop,in;
    int count[8]={0,0,0,0,0,0,0,0};
    printf("Enter the number of bits to be transmitted:");
    scanf("%d",&size);
    row=size/column;
    data=(int**)malloc(sizeof(int*)*(row+1));
    for(loop=0;loop<row+1;loop++)
        data[loop]=(int*)malloc(sizeof(int)*(column));
    printf("Enter the bits to transmit:\n");
    for(loop=0;loop<row;loop++)
    {
        for(in=0;in<column;in++)
        {
            scanf("%d",&data[loop][in]);
            if(data[loop][in]==1)
                count[in]++;
        }
    }
    for(loop=0;loop<8;loop++)
    {
      data[row][loop]=count[loop]%2;
    }
    printf("\nTransmitted Data\n");
    for(loop=0;loop<row+1;loop++)
    {
        for(in=0;in<column;in++)
        {
            printf("%d\t",data[loop][in]);
        }
        printf("\n");
    }
}
