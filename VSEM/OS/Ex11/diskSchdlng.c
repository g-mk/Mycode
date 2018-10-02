/*******************************************************************************
**Description   : Implementation of Disk Scheduling Algorithm                 **
**Author        : N. Guru Manikandan.                                         **
**Date Created  : 29/09/2016.                                                 **
**Version       : 0.1                                                         **
*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void swap (int *a , int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sort (int *req,int n)
{
    int i,j;
    for(i = 0;i<n ;i++)
        for(j=i+1;j<n;j++)
            if(req[i]>req[j])
                swap(&req[i],&req[j]);                
}

void copy(int *a,int b[],int n )
{
    int i;
    for(i=0;i<n;i++)
        a[i] = b[i];
}

int locCurPos(int *req,int cur, int n)
{
    int i;
    for(i=0;i<n;i++)
        if(cur == req[i])
            return i;
}


void fcfs(int *req,int cur,int n)
{
    int totCyln=0,i;
    totCyln = abs(cur - req[0]);
    printf("\n%d -> %d \n",cur,req[0]);
    for(i = 1;i<n;i++)
    {
        printf("\n%d -> %d \n",req[i-1],req[i]);        
        totCyln += abs(req[i] - req[i-1]);
    }
        
    printf("\nTotal Head movement : %d cylinders\n",totCyln);
}
void sstf(int *req,int cur,int n)
{
    int prev,next,cyln = 0,count = 0;
    int diff1,diff2;
    int init = locCurPos(req,cur,n);
    prev = init - 1;
    next = init + 1;
    while(count < n-1 )
    {
        if(prev >= 0 && next < n)
        {
            diff1 = abs(req[init]-req[prev]);
            diff2 = abs(req[init]-req[next]);
            
            if(diff1 < diff2)
            {
                printf("\n%d -> %d \n",req[init],req[prev]);
                cyln += diff1;
                init = prev;
                prev --;
            }
            else
            {
                printf("\n%d -> %d \n",req[init],req[next]);            
                cyln += diff2;
                init = next;
                next++;
            }
            count ++;   
        }
        else if(prev <= 0 )
        {
            cyln += abs(req[init]-req[next]);
            printf("\n%d -> %d \n",req[init],req[next]);            
            init = next;
            next++;
            count++;
        }
        else if(next >= n )
        {
            cyln += abs(req[init]-req[prev]);
            printf("\n%d -> %d \n",req[init],req[prev]);            
            init = prev;
            prev--;
            count++;
        }
    }
    
    printf("\nTotal Head movement : %d cylinders\n",cyln);
}
void scan_look(int *req,int cur,int flag,int n)
{
    int i,j,cyln=0,count=0;
    
    int init = locCurPos(req,cur,n);
    
    i = init;
    do
    {
        j= (i + flag);
        cyln += abs(req[i]-req[j]);
        printf("\n%d -> %d \n",req[i],req[j]);
        count++;
        if(j == n-1 || j==0)
        {
            flag *= -1;
            i = init+flag;
            count++;
            if(count<n)
            {
                printf("\n%d -> %d \n",req[j],req[i]);         
                cyln += abs(req[i]-req[j]);
            }
        }
        else
            i = j;
            
    }while(count<n-1);
    
    printf("\nTotal Head movement : %d cylinders\n",cyln);

}

void c_scan_look(int *req,int cur,int flag,int n)
{
    int i,j,cyln=0;
    
    int init = locCurPos(req,cur,n);
    
    i = init;
    do
    {
        j= (i + flag) % n;
        cyln += abs(req[i]-req[j]);
        printf("\n%d -> %d \n",req[i],req[j]);
        if(flag==-1 && j==0)
        {
            i = n-1;
            cyln += abs(req[i]-req[j]);
            printf("\n%d -> %d \n",req[j],req[i]);
        }
            
        else
            i = j;
            
    }while(i!=init-flag);
    
    printf("\nTotal Head movement : %d cylinders\n",cyln);

}


void main()
{
    int *req,cur,prev,n,i,*temp,tot,flag;
    int choice;
    
    printf("\nEnter the Total No. of Cylinders in Disk:");
    scanf("%d",&tot);
    
    printf("\nEnter the Number of Cylinder requested:");
    scanf("%d",&n);
    req = (int*)malloc(n+3 * sizeof(int));
    temp = (int*)malloc(n+3 * sizeof(int));   
    printf("\nEnter the Cylinder Request Sequence.\n");
    for(i=0;i<n;i++)
        scanf("%d",&req[i]);
    
    printf("\nEnter the Current Head Position:");
    scanf("%d",&cur);
    
    printf("\nEnter the Previous Head Position:");
    scanf("%d",&prev);
    
    do
    {
        printf("\nEnte the Algorithm to perform Disk Scheduling\n");
        printf("1.FCFS.\n2.SSTF.\n3.SCAN.\n4.C-SCAN.\n5.LOOK.\n6.C-LOOK.\n");
        printf("7.Exit.\nEnter your Choice:");
        scanf("%d",&choice);

        flag = ( (prev - cur) < 0 ) ? 1 : -1;
        
        copy(temp,req,n);
        switch(choice)
        {
            case 1:
                printf("\n***************FCFS************************\n");
                fcfs(temp,cur,n);
                break;
            case 2:
                printf("\n****************SSTF************************\n");            
                temp[n] = cur;
                sort(temp,n+1);
                sstf(temp,cur,n+1);
                break;
            case 3:
                printf("\n***************SCAN************************\n");            
                temp[n] = cur;
                if(flag<0)
                    temp[n+1] = 0;
                else
                    temp[n+1] = tot-1;
                sort(temp,n+2);
                scan_look(temp,cur,flag,n+2);
                break;
           case 4:
                printf("\n*****************C-SCAN***********************\n");           
                temp[n] = cur;
                temp[n+1] = 0;
                temp[n+2] = tot-1;
                sort(temp,n+3);
                c_scan_look(temp,cur,flag,n+3);
                break;
           case 5:
                printf("\n***************LOOK************************\n");           
                temp[n] = cur;
                sort(temp,n+1);
                scan_look(temp,cur,flag,n+1);
                 break;
           case 6:
                printf("\n****************C-LOOK************************\n");           
                temp[n] = cur;
                sort(temp,n+1);
                c_scan_look(temp,cur,flag,n+1);
                 break;
                 
           case 7:
                printf("\nThank You\n");
        
        }
    }while(choice != 7);
}
