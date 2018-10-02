#include"hHamming.h"
int main()
{
    int it,size,*data,position;
    printf("Enter the Number of bits received: ");
    scanf("%d",&size);
    data= (int*)malloc(size*sizeof(int));
    printf("\nEnter the data received: \n\n");
    for(it=size-1;it>=0;it--)
    {
        scanf("%d",&data[it]);
    }
    position=computeHamming(data,size);
    if(position==0)
        printf("\n\nNo Error in the data\n\n");
    else
        printf("\n\nError is detected in position %d\n\n",position);
}
