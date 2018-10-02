/*******************************************************************************
**Description   : Implementation of the non-contegious memory allocation      **
**Author        : N. Guru Manikandan.                                         **
**Date Created  : 08/09/2016.                                                 **
**Version       : 0.1                                                         **
*******************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h> 
typedef struct
{
    int pid;
    float size;
    int page;
}process;

typedef struct
{
    int stat;
    int page;
}Frame;

int main()
{
    int frame,fSize,pMem,lMem,num,intFrag=0;
    int i,j,k;
    Frame *f;
    process *p;
    
    printf("\nEnter the Physical Memory Size:");
    scanf("%d",&pMem);
    
    /*printf("\nEnter the Logical Memory Size:");
    scanf("%d",&lMem);*/
    
    printf("\nEnter the Frame Size:");
    scanf("%d",&fSize);
    
    frame = pMem/fSize;
    
    f = (Frame*) malloc(frame * sizeof(Frame));
    
    printf("\nNo. of Process:");
    scanf("%d",&num);
    
    p = (process*)malloc(num * sizeof(process));
    
    for(i=0;i<num;i++)
    {
        printf("\nEnter the Id of Process %d: ",i+1);
        scanf("%d",&p[i].pid);
        printf("Enter the Size of Process %d: ",i+1);
        scanf("%f",&p[i].size);
        p[i].page = ceil(p[i].size/fSize);
        int frag = ((int)p[i].size%fSize);
        if(frag !=0)
            intFrag += fSize - frag;
    }
    
    printf("\nNo. of Frames: %d\n",frame);
    
    for(i=0;i<num;i++)
    {
        for(j=0;j<p[i].page;j++)
        {
            do
            {
                k=rand()%frame;
                
            }while(f[k].stat!=0);
            
            f[k].page = j;
            f[k].stat = p[i].pid;

        }
    }
    printf("\n|Frame Number\tContent\t\t\t|\n");
    for(i=0;i<frame;i++)
    {
        printf("\n|%d\t",i+1);
        if(f[i].stat==0)
            printf("\tFree Frame\t\t|\n");
        else
            printf("\tPage %d of Process %d\t|\n",f[i].page,f[i].stat);       
               
    }
    
    printf("\nInternal Fragmentation: %d\n",intFrag);
    
}
