/*******************************************************************************
**Description   : Implementation of the contegious memory allocation          **
**Author        : N. Guru Manikandan.                                         **
**Date Created  : 01/09/2016.                                                 **
**Version       : 0.1                                                         **
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#define ASCEND 1
#define DESCEND 2

typedef struct{
    int stat;
    int size;
    int number;
}mem;

mem* copy(mem t[],int n)
{
    mem* temp = (mem*) malloc(n*sizeof(mem));
    int i;
    
    for(i=0;i<n;i++)
        temp[i] = t[i];
    
    return temp;
}

void swap(mem *p1,mem *p2 )
{
    mem temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void sort(mem *temp,int size,int flag)
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            switch(flag)
            {
                case ASCEND :
                      if(temp[i].size>temp[j].size)
                        swap(&temp[i],&temp[j]);
                      break;
                case DESCEND:
                      if(temp[i].size<temp[j].size)
                        swap(&temp[i],&temp[j]);
                      break;
            }
        }
    }
}

void firstFit(mem process[],mem holes[],int pSize,int hSize)
{
    
    int i,j=0,flag=1;
    int internal=0,external=0;
    
    printf("\n\n********************First Fit****************************\n\n");    
    printf("\n\n**************Process to Memory Allocation***************\n\n");
    for(i=0;i<pSize;i++)
    {
        for(j=0; (j<hSize) && (process[i].stat!=1) ;j++)
        {
            if( (holes[j].stat==0) && (process[i].size<holes[j].size) )
            {
                printf("\nProcess %d -> Hole %d \n",process[i].number,holes[j].number);
                process[i].stat = holes[j].stat = 1;
                holes[j].size = holes[j].size - process[i].size;
            }
        }
    
    }
    
    
    printf("\n\n****************Unallocated Process**********************\n\n");
    
    for(i=0;i<pSize;i++)
    {
        if(process[i].stat==0)
        {
            printf("\nProcess %d \n",i+1);
            flag = 0;
        }
    }
    
    if(flag)
        printf("\nNo Process are left Unallocated\n");
    for(i=0;i<hSize;i++)
    {
        if(holes[i].stat==0)
            external += holes[i].size;
        else if(holes[i].stat==1)
            internal += holes[i].size;
    }
    
    printf("\nTotal Internal Fragments %d\n",internal);
    printf("\nTotal External Fragments %d\n",external);

}

void bestFit(mem process[],mem holes[],int pSize,int hSize)
{
    int i,j=0,flag = 1;
    int internal=0,external=0;
    
    printf("\n\n********************Best Fit****************************\n\n");    
    
    sort(holes,hSize,ASCEND);
    
    printf("\n\n**************Process to Memory Allocation***************\n\n");
    for(i=0;i<pSize;i++)
    {
        for(j=0; (j<hSize) && (process[i].stat!=1) ;j++)
        {
            if( (holes[j].stat==0) && (process[i].size<holes[j].size) )
            {
                printf("\nProcess %d -> Hole %d \n",process[i].number,holes[j].number);
                process[i].stat = holes[j].stat = 1;
                holes[j].size = holes[j].size - process[i].size;
            }
        }
    
    }
    
    
    printf("\n\n****************Unallocated Process**********************\n\n");
    
    for(i=0;i<pSize;i++)
    {
        if(process[i].stat==0)
        {
            printf("\nProcess %d \n",i+1);
            flag = 0;
        }
    }
    
    if(flag)
        printf("\nNo Process are left Unallocated\n");
    for(i=0;i<hSize;i++)
    {
        if(holes[i].stat==0)
            external += holes[i].size;
        else if(holes[i].stat==1)
            internal += holes[i].size;
    }
    
    printf("\nTotal Internal Fragments %d\n",internal);
    printf("\nTotal External Fragments %d\n",external);

}

void worstFit(mem process[],mem holes[],int pSize,int hSize)
{
    int i,j=0,flag = 1;
    int internal=0,external=0;
    
    printf("\n\n********************Worst Fit****************************\n\n");    
    
    sort(holes,hSize,DESCEND);
    
    printf("\n\n**************Process to Memory Allocation***************\n\n");
    for(i=0;i<pSize;i++)
    {
        for(j=0; (j<hSize) && (process[i].stat!=1) ;j++)
        {
            if( (holes[j].stat==0) && (process[i].size<holes[j].size) )
            {
                printf("\nProcess %d -> Hole %d \n",process[i].number,holes[j].number);
                process[i].stat = holes[j].stat = 1;
                holes[j].size = holes[j].size - process[i].size;
            }
        }
    
    }
    
    
    printf("\n\n****************Unallocated Process**********************\n\n");
    
    for(i=0;i<pSize;i++)
    {
        if(process[i].stat==0)
        {
            printf("\nProcess %d \n",i+1);
            flag = 0;
        }
    }
    
    if(flag)
        printf("\nNo Process are left Unallocated\n");
        
    for(i=0;i<hSize;i++)
    {
        if(holes[i].stat==0)
            external += holes[i].size;
        else if(holes[i].stat==1)
            internal += holes[i].size;
    }
    
    printf("\nTotal Internal Fragments %d\n",internal);
    printf("\nTotal External Fragments %d\n",external);

}
int main()
{
    mem *process,*holes,*pTemp,*hTemp;
    int pSize,hSize;
    int loop,choice;
    
    printf("Enter the Number of Process:");
    scanf("%d",&pSize);
    printf("Enter the Number of Holes: ");
    scanf("%d",&hSize);
    
    process = (mem *) malloc(pSize*sizeof(mem));
    holes = (mem *) malloc(hSize*sizeof(mem));    

    printf("\nEnter the Process size\n");
    
    for(loop=0;loop<pSize;loop++)
    {
        printf("Process %d Size:",loop+1);
        scanf("%d",&process[loop].size);
        process[loop].number = loop+1;
    }
    
    printf("\nEnter the Holes size\n");
    
    for(loop=0;loop<hSize;loop++)
    {
        printf("Hole %d Size:",loop+1);
        scanf("%d",&holes[loop].size);
        holes[loop].number = loop+1;
    }
    
    do
    {
        printf("\n\nAlgorithm\n1)First Fit\n2)Best Fit\n3)Worst Fit\n4)Exit\n");
        printf("\nEnter the Choice for Allocation Process:" );
        scanf("%d",&choice);
        
        pTemp = copy(process,pSize);
        hTemp = copy(holes,hSize);
        
        switch(choice)
        {
            case 1: firstFit(pTemp,hTemp,pSize,hSize);
                    break;
            case 2: bestFit(pTemp,hTemp,pSize,hSize);   
                    break;
            case 3: worstFit(pTemp,hTemp,pSize,hSize);
                    break;
            case 4: printf("\nContiguous Memory Alloction Ended\n");
        }
    }while(choice!=4);
    
    free(process);
    free(holes);
    free(pTemp);
    free(hTemp);
}
