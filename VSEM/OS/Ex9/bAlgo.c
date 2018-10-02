/*******************************************************************************
**Description   : Implementation of Banker's Algorithm for deadlock detection **
**Author        : N. Guru Manikandan.                                         **
**Date Created  : 15/09/2016.                                                 **
**Version       : 0.1                                                         **
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>

int isEligible(int *need ,int * work,int m)
{
    int i,flag=1;
    for(i=0;i<m;i++)
    {
        if(need[i]>work[i])
            flag = 0;
    }
    
    return flag;
}

void add(int * work , int *alloc,int m)
{
    int i;
    for(i=0;i<m;i++)
    {
        work[i] += alloc[i];
    }

}
int bankerAlgol(int *need[],int *max[],int *alloc[],int * work,int n,int m)
{
    int *stat;
    int i,j,flag =1,l=0,loop;
    int *safeseq=(int*) malloc(n*sizeof(int));
    stat = (int*) malloc(n*sizeof(int));
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            need[i][j] = max[i][j]-alloc[i][j];
            if(need[i][j]<0)
            {
                printf("\nThere is no safe sequence\n");
                return 0;
            }
        }
    }
    
    printf("\nNeed Matrix for the Given Process\n");
    for(i=0;i<n;i++)
    {
        printf("\nProcess %d\t",i+1);
        for(j=0;j<m;j++)
        {
            printf("%d\t",need[i][j]);
        }
        printf("\n");
    }
    for(j=0;j<n;j++)
    {
        for(i=0;i<n ;i++)
        {
            if(stat[i]==0)
            {
                    if(isEligible(need[i],work,m))
                    {
                        printf("\nAllocated to Process %d \n",i+1);
                        safeseq[l++]=i+1;
                        add(work,alloc[i],m);
                        printf("\nWork ");
                        for(loop=0;loop<m;loop++)
                            printf("%d\t",work[loop]);
                        printf("\n");
                        stat[i] = 1;
                    }
            }
        }
   }
   
   for(i=0;i<n;i++)
     if(stat[i]!=1)
     {
        flag = 0;     
        break;
     }
    if(flag)
    {
        printf("\nThere Exist a Safe Sequence\n<");
        for(i=0;i<n;i++)
            printf("P%d\t",safeseq[i]);
        printf(">\n");
            
    }
    else
        printf("\nThere Does not Exist a Safe Sequence\n");

}
int main()
{
    int n,m,*available,**max,**alloc,**need,*work;
    int *stat;
    int i,j,flag =1,req;
    
    printf("\nEnter the Number of Process:");
    scanf("%d",&n);
    printf("\nEnter the Number of Resources:");
    scanf("%d",&m);
    
    
    work = (int*) malloc(m*sizeof(int));
    available = (int*) malloc(m*sizeof(int));
    max = (int**) malloc(n*sizeof(int*));
    alloc = (int**) malloc(n*sizeof(int*));    
    need = (int**) malloc(n*sizeof(int*));        
    
    for(i=0;i<n;i++)
    {
        max[i] = (int*) malloc(m*sizeof(int));
        alloc[i] = (int*) malloc(m*sizeof(int));
        need[i] = (int*) malloc(m*sizeof(int));
    }
    
    printf("\nEnter the Allocation Table\n");
    
    for(i=0;i<n;i++)
    {
        printf("\nAllocation for Process %d\n",i+1);
        for(j=0;j<m;j++)
        {
            printf("\nResource %d: ",j+1);
            scanf("%d",&alloc[i][j]);
        }
    }
    
    printf("\nEnter the Max Requirment Table\n");
    
    for(i=0;i<n;i++)
    {
        printf("\nMaximum Resource for Process %d\n",i+1);
        for(j=0;j<m;j++)
        {
            printf("\nResource %d: ",j+1);
            scanf("%d",&max[i][j]);
        }
    }
    
    for(i=0;i<m;i++)
    {
        printf("\nEnter the Instance Availabe for the Resource %d\n",i+1);
        scanf("%d",&available[i]);
        work[i] = available[i];
    }
 
    bankerAlgol(need,max,alloc,work,n,m);
    
    printf("Enter the Process Request for Allocation: ");
    scanf("%d",&req);   
    
    printf("Enter the Request for the Process %d: ",req);
    
    for(j=0;j<m;j++)
    {
        int val;
        printf("\nResource %d: ",j+1);
        scanf("%d",&val);
        alloc[req-1][j] += val;
        available[i] -= val;
    }
    
    
    for(i=0;i<m;i++)
        work[i]=available[i];
        
    bankerAlgol(need,max,alloc,work,n,m);
           
}
