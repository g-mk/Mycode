#include "hcpuSchdl.h"
#include "hQueue.h"

int check(process* p, int n)
{
    int i;
    for(i=1;i<n;i++)
        if(p[0].arrival!=p[i].arrival)
            return 0;
    return 1;
}

void swap(process * p1,process *p2 )
{
    process temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

void copy(process p1[],process p2[],int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        p1[i]=p2[i];
    }
}

void sort(process* t,int size,int flag)
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            switch(flag)
            {
                case ARRIVAL:
                        if(t[i].arrival>t[j].arrival)
                            swap(&t[i],&t[j]);
                        break;
                case JOB     :
                        if(t[i].burst>t[j].burst)
                            swap(&t[i],&t[j]);
                        break;
                case PRIORITY:
                        if(t[i].priority>t[j].priority)
                            swap(&t[i],&t[j]);
                            break;
                case ARRIVAL|JOB:
                        if(t[i].arrival==t[j].arrival)
                            if(t[i].burst>t[j].burst)
                                swap(&t[i],&t[j]);
                             break;
                case ARRIVAL|PRIORITY:
                        if(t[i].arrival==t[j].arrival)
                            if(t[i].priority>t[j].priority)
                                swap(&t[i],&t[j]);
            }
            
        }
    }

}

int findNext(process* temp,int n,int cBurst,int flag)
{
    int i;
    int min = 100;
    int next = -1;
    for(i=0;i<n;i++)
    {
        switch(flag)
        {
            case JOB:
                if((temp[i].stat==0) && (temp[i].arrival <= cBurst) 
                                     && min > temp[i].rem)
                {
                    next = i;
                    min = temp[i].rem;
                }
                break;
            case PRIORITY:
                if((temp[i].stat==0) && (temp[i].arrival <= cBurst) 
                                     && min > temp[i].priority)
                {
                    next = i;
                    min = temp[i].priority;
                }
                break;
        }
    }
    
    return next;
}
//*********************FCFS ALGORITHM IMPLMENTATION***************************//
void fcfs(process* temp,int n)
{
    int *waiting,i;
    int totWait=0,totTround = 0;
    waiting = (int *)malloc(n*sizeof(int));
    waiting[0]=0;
    printf("\n************FCFS Algorithm*********************\n");
    printf("|p%d |",temp[0].id);
    for(i=1;i<n;i++)
    {
        printf(" p%d |",temp[i].id);
        waiting[i] = temp[i-1].burst+waiting[i-1];
    }
    
    for(i=0;i<n;i++)
    {
        totWait += waiting[i] - temp[i].arrival;
        totTround += waiting[i] + temp[i].burst - temp[i].arrival;
    }
        
    printf("\n\nAverage Waiting time %.2fs\n",totWait/(float)n);
    printf("\n\nAverage Turnaround time %.2fs\n",totTround/(float)n);
}

//*********************SJF ALGORITHM IMPLMENTATION***************************//
void sjf(process* temp,int n, int totBurst)
{
    int i,next;
    int totWait=0,totTround = 0;

    printf("\n************SJF Algorithm*********************\n");
    printf("|p%d |",temp[0].id);
    temp[0].stat = 1;
    temp[0].waiting = 0;
    temp[0].tround = temp[0].burst;
    
    for(i=temp[0].burst;i<totBurst;i+=temp[next].burst)
    {
        next = findNext(temp,n,i,JOB);
        printf(" p%d |",temp[next].id);
        temp[next].stat = 1;
        temp[next].waiting = i-temp[next].arrival;
        temp[next].tround = i+temp[next].burst-temp[next].arrival;
    }
    
    for(i=0;i<n;i++)
    {
        totWait += temp[i].waiting;
        totTround += temp[i].tround;
    }
    
    printf("\n\nAverage Waiting time %.2fs\n",totWait/(float)n);
    printf("\n\nAverage Turnaround time %.2fs\n",totTround/(float)n);

}
//*********************SRJF ALGORITHM IMPLMENTATION***************************//
void srjf(process* temp,int n, int totBurst)
{
    int i,next,prev;
    int totWait=0,totTround = 0;

    printf("\n************SRJF Algorithm*********************\n");

    prev = temp[0].id;
    printf("|p%d |",prev);    

    for(i=0;i<totBurst;i++)
    {
        next = findNext(temp,n,i,JOB);
        if(temp[next].id!=prev)
        {
           prev = temp[next].id;        
           printf(" p%d |",prev);
        }
        temp[next].rem--;
        if(temp[next].rem==0)
        {
            temp[next].stat = 1;
            temp[next].waiting = i+1;
        }
    }
    
    for(i=0;i<n;i++)
        {
            temp[i].waiting = temp[i].waiting - temp[i].burst - temp[i].arrival;
            temp[i].tround = temp[i].waiting + temp[i].burst;
            totWait += temp[i].waiting;
            totTround +=temp[i].tround;
        }
        
    printf("\n\nAverage Waiting time %.2fs\n",totWait/(float)n);
    printf("\n\nAverage Turnaround time %.2fs\n",totTround/(float)n);    

}

//*********************Priority(NP) ALGORITHM IMPLMENTATION***********************//
void priority(process* temp,int n, int totBurst)
{
    int i,next;
    int totWait=0,totTround = 0;
    
    printf("\n************Priority Algorithm*********************\n");
    printf("|p%d |",temp[0].id);
    temp[0].stat = 1;
    temp[0].waiting = 0;
    temp[0].tround = temp[0].burst;
    
    for(i=temp[0].burst;i<totBurst;i+=temp[next].burst)
    {
        next = findNext(temp,n,i,PRIORITY);
        printf(" p%d |",temp[next].id);
        temp[next].stat = 1;
        temp[next].waiting = i-temp[next].arrival;
        temp[next].tround = i+temp[next].burst-temp[next].arrival;
        
    }
    
    for(i=0;i<n;i++)
    {
        totWait += temp[i].waiting;
        totTround += temp[i].tround;
    }
    
    printf("\n\nAverage Waiting time %.2fs\n",totWait/(float)n);
    printf("\n\nAverage Turnaround time %.2fs\n",totTround/(float)n);

}

//*********************Priority(P) ALGORITHM IMPLMENTATION***********************//
void priorityP(process* temp,int n, int totBurst)
{
    int i,j=1,next,prev;
    int totWait=0,totTround = 0;

    printf("\n************Priority(P) Algorithm*********************\n");

    prev = temp[0].id;
    printf("|p%d |",prev);    

    for(i=0;i<totBurst;i++)
    {
        next = findNext(temp,n,i,PRIORITY);
        if(temp[next].id!=prev)
        {
           prev = temp[next].id;        
           printf(" p%d |",prev);
        }
        temp[next].rem--;
        if(temp[next].rem==0)
        {
            temp[next].stat = 1;
            temp[next].waiting = i+1;
        }
    }
    
    for(i=0;i<n;i++)
        {
            temp[i].waiting = temp[i].waiting - temp[i].burst - temp[i].arrival;
            temp[i].tround = temp[i].waiting + temp[i].burst;
            totWait += temp[i].waiting;
            totTround +=temp[i].tround;
        }
        
    printf("\n\nAverage Waiting time %.2fs\n",totWait/(float)n);
    printf("\n\nAverage Turnaround time %.2fs\n",totTround/(float)n);    
}

//**************************ROUND ROBIN IMPLMENTATION*************************//
void roundRobin(process* p, int n,int totBurst,int ts)
{
    Queue *q;
    int i,comp=0,totWait=0,totTround=0;
    q = (Queue*)malloc(sizeof(Queue));
    initialize(q,6);
    enqueue(q,0);
    p->stat = 1;
    printf("\n****************Round Robin**************************\n");
    while(q->count!=0)
    {
        int cur;
        cur = dequeue(q);
        printf("|p%d ",p[cur].id);
        p[cur].rem -= ts;
        if(p[cur].rem>=0)
            comp+=ts;   
        else
            comp+=ts+p[cur].rem;
        p[cur].waiting = comp;
        for(i=0;i<n;i++)
        {
            if(p[i].stat==0 && p[i].arrival < comp && p[i].rem >0)
            {
                enqueue(q,i);
                p[i].stat = 1;
            }       
        }
        if(p[cur].rem >0 )
            enqueue(q,cur);
    }
    printf("|");
    for(i=0;i<n;i++)
    {
        p[i].waiting = p[i].waiting - p[i].burst - p[i].arrival;
        p[i].tround = p[i].waiting + p[i].burst;
        totWait+=p[i].waiting;
        totTround+=p[i].tround;
    }
    
    printf("\n\nAverage Waiting time %.2fs\n",totWait/(float)n);
    printf("\n\nAverage Turnaround time %.2fs\n",totTround/(float)n);
    
}

int main()
{
    int i,n,j,tmslc,totBurst=0,choice;
    process *p,*temp;
    
    printf("\nEnter the Number of Processor:\n");
    scanf("%d",&n);
    
    p = (process*)malloc(n*sizeof(process));
    temp = (process*)malloc(n*sizeof(process));
    
    for(i=0;i<n;i++)
    {
        printf("\nProcess Name:");
        scanf("%d",&p[i].id);
        printf("\nBurst Time:");
        scanf("%d",&p[i].burst);
        p[i].rem = p[i].burst;
        totBurst+=p[i].burst;
        printf("\nArrival Time:");
        scanf("%d",&p[i].arrival);
        printf("\nPriority:");
        scanf("%d",&p[i].priority);
        p[i].stat = 0;
    }
    printf("\nTotal Burst Time: %d\n",totBurst);

    
    do
    {
        printf("\nChoose the Algorithm to Execute.......\n1.FCFS Algorithm.\n");
        printf("2.SJF Algorithm.\n3.SRJF Algorithm\n4.Priority(NP)Algorithm\n");
        printf("5.Priority(P) Algorithm.\n6.Round Robin\n");
        printf("7.Exit\nEnter the Choice:");
        scanf("%d",&choice);
        copy(temp,p,n);
        sort(temp,n,ARRIVAL);
        switch(choice)
        {
            case 1:
                fcfs(temp,n);
                break;
            case 2:
                if(check(p,n))
                    sort(temp,n,JOB);
                else
                    sort(temp,n,ARRIVAL|JOB);
                sjf(temp,n,totBurst);
                break;
            case 3:
                if(check(p,n))
                    sort(temp,n,JOB);
                else
                    sort(temp,n,ARRIVAL|JOB);
                srjf(temp,n,totBurst);
                break;
            case 4:
                if(check(p,n))
                    sort(temp,n,PRIORITY);
                else
                    sort(temp,n,ARRIVAL|PRIORITY);
                priority(temp,n,totBurst);
                break;
            case 5:
                if(check(p,n))
                    sort(temp,n,PRIORITY);
                else
                    sort(temp,n,ARRIVAL|PRIORITY);
                priorityP(temp,n,totBurst);
                break;
            case 6:
                printf("\nTime Slice:");
                scanf("%d",&tmslc);
                roundRobin(temp,n,totBurst,tmslc);
                break;
            case 7:
                printf("\nThank You\n");
                break;
            default:
                printf("\nInvalid Choice....\n");
                
        }
    }while(choice != 7);
    
}
