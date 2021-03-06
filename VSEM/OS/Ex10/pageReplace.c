/*******************************************************************************
**Description   : Implementation of PAge Replacement Algorithm for            **
**                deadlock detection                                          **
**Author        : N. Guru Manikandan.                                         **
**Date Created  : 22/09/2016.                                                 **
**Version       : 0.1                                                         **
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int search(int *frame,int f,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(f == frame[i])
            return i;
    }
    
    return -1;
}

int searchFrame(int *seq,int val,int cur,int n)
{
    int result = n;
    for(cur=cur+1;cur<n;cur++)
    {
        if(seq[cur]==val)
        {
            result = cur;
            break;
        }
    }
    return result;
}
void look(int * seq,int *stat,int *cFrame,int cur,int n,int fSize)
{
    int i;
    for(i=0;i<fSize;i++)
    {   
        stat[i] = searchFrame(seq,cFrame[i],cur,n);
    }
    
}
void update(int *stat , int cur,int fSize)
{
    int i;
    for(i=0;i<fSize;i++)
    {
        if(cur == i)
            stat[cur]=1;
        else
            stat[i]++;
    }

}

int max(int *stat, int fSize)
{
    int i=0;
    int max=stat[i],pos=0;
    for(i=1;i<fSize;i++)
    {
        if(max<stat[i])
        {
            max = stat[i];
            pos = i;
        }
    }
    
    return pos;
}
void copy (int *f1,int f2[],int n)
{
    int i;
    for(i=0;i<n;i++)
        f1[i] = f2[i];
}
void fcfs(int *seq,int n,int fSize)
{
    int **rep,i,j,pos=0,*cFrame;
    int fault=0;
    rep = (int**)malloc(n* sizeof(int*));
    cFrame = (int*)malloc(fSize* sizeof(int));
    for(i=0;i<fSize;i++)
        cFrame[i] = -1;
        
    for(i=0;i<n;i++)
        rep[i] = (int*) malloc(fSize*sizeof(int));
    
    for(i=0;i<n;i++)
    {
        if(search(cFrame,seq[i],fSize)==-1)
        {
            fault++;
            j= pos%fSize;
            pos++;
            cFrame[j] = seq[i];
            copy(rep[i],cFrame,fSize);
        }   
    }
    
    printf("\nFrame Status\n");
    
    for(i=0;i<fSize;i++)
    {
        for(j=0;j<n;j++)
        {
            if(rep[j][i]!=-1)
                printf("%d ",rep[j][i]);
            else
                printf("- ");
        }
        printf("\n");
    }
    
    printf("\nPage Fault Count: %d\n",fault);
}


void lru(int *seq,int n,int fSize)
{
    int **rep,i,j,pos=3,*cFrame,*stat;
    int fault=0;
    rep = (int**)malloc(n* sizeof(int*));
    cFrame = (int*)malloc(fSize* sizeof(int));
    stat = (int*)malloc(fSize* sizeof(int));    
    for(i=0;i<fSize;i++)
    {
        cFrame[i] = -1;
        stat[i] = pos--;
    }
        
    for(i=0;i<n;i++)
        rep[i] = (int*) malloc(fSize*sizeof(int));
    
    for(i=0;i<n;i++)
    {
        int k =search(cFrame,seq[i],fSize);
        if(k==-1)
        {
            j = max(stat,fSize);
            fault++;
            update(stat,j,fSize);
            cFrame[j] = seq[i];
            copy(rep[i],cFrame,fSize);
        }
        else
            update(stat,k,fSize);
    }
    
    printf("\nFrame Status\n");
    
    for(i=0;i<fSize;i++)
    {
        for(j=0;j<n;j++)
        {
            if(rep[j][i]!=-1)
                printf("%d ",rep[j][i]);
            else
                printf("- ");
        }
        printf("\n");
    }
    
    printf("\nPage Fault Count: %d\n",fault);
}

void optimal(int *seq,int n,int fSize)
{
    int **rep,i,j,pos=3,*cFrame,*stat;
    int fault=0;
    rep = (int**)malloc(n* sizeof(int*));
    cFrame = (int*)malloc(fSize* sizeof(int));
    stat = (int*)malloc(fSize* sizeof(int));    
    for(i=0;i<fSize;i++)
    {
        cFrame[i] = -1;
        stat[i] = -1;
    }
        
    for(i=0;i<n;i++)
        rep[i] = (int*) malloc(fSize*sizeof(int));
    
    for(i=0;i<n;i++)
    {
        int k =search(cFrame,seq[i],fSize);
        if(k==-1)
        {
            look(seq,stat,cFrame,i,n,fSize);
            j = max(stat,fSize);
            fault++;
            cFrame[j] = seq[i];
            copy(rep[i],cFrame,fSize);
        }
        else
            update(stat,k,fSize);
    }
    
    printf("\nFrame Status\n");
    
    for(i=0;i<fSize;i++)
    {
        for(j=0;j<n;j++)
        {
            if(rep[j][i]!=-1)
                printf("%d ",rep[j][i]);
            else
                printf("- ");
        }
        printf("\n");
    }
    
    printf("\nPage Fault Count: %d\n",fault);
}
void main()
{
    int *seq,n,fSize,i,choice;
    
    printf("Enter the Frame Size:");
    scanf("%d",&fSize);
    
    printf("\nEnter the number of sequence:");
    scanf("%d",&n);
    
    seq = (int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
        scanf("%d",&seq[i]);
    do
    {
        printf("\nPage Relacement Algorithms\n");
        printf("1.FCFS.\n2.LRU.\n3.Optimal.\n4.Exit.\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("\n************FCFS Algorithm*******************\n");
                fcfs(seq,n,fSize);
                break;
            case 2:
                printf("\n************LRU Algorithm*******************\n");
                lru(seq,n,fSize);
                break;
            case 3:
                printf("\n************OPTIMAL Algorithm*******************\n");
                optimal(seq,n,fSize);
                break;
            case 4:
                printf("\n************Thank You*******************\n");
                break;
            default:
                printf("\n************Invalid Choice*******************\n");
        }
    }while(choice!=4);
}   
