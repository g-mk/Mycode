#include<stdio.h>
main()
{
    int **data,row,column=8,size,loop,in,flag=1;
    int count[8]={0,0,0,0,0,0,0,0},parity[8];
    printf("Enter the number of bits to be received:");
    scanf("%d",&size);
    row=size/column;
    data=(int**)malloc(sizeof(int*)*(row));
    for(loop=0;loop<row+1;loop++)
        data[loop]=(int*)malloc(sizeof(int)*(column));
    printf("Enter the bits to be transmitted:\n");
    for(loop=0;loop<row;loop++)
    {
        for(in=0;in<column;in++)
        {
            scanf("%d",&data[loop][in]);
            if(loop!=row-1&&data[loop][in]==1)
                count[in]++;
        }
    }
    for(loop=0;loop<8;loop++)
    {
      parity[loop]=count[loop]%2;
    }

    for(loop=0;loop<8;loop++)
    {
        if(parity[loop]!=data[row-1][loop])
            {
                flag=0;
                break;
            }
    }
    if(flag)
        printf("\nNo Error in the data\n");
    else
        printf("\n Burst Error\n");
}



