/*******************************************************************************
**Description   : Implementation of Producer Consumer Problem using Semaphoer **
**                (Consumer)                                                  **
**Author        : N. Guru Manikandan.                                         **
**Date Created  : 25/08/2016.                                                 **
**Version       : 0.1                                                         **
*******************************************************************************/
#include "../producer/semProCon.h"

union semaphore
{
    int val;
    struct semid_ds *buf;
    struct seminfo *_buf;
    unsigned short *array;
};

void wait(int sid, int sno)
{
    int a;
    struct sembuf s;
    s.sem_num = sno;
    s.sem_op = -1;
    a = semop(sid,&s,1);
}

void signal(int sid, int sno)
{
    int a;
    struct sembuf s;
    s.sem_num = sno;
    s.sem_op = 1;
    a = semop(sid,&s,1);
}

int main()
{
    
    int shmid,stat,semid;
    union semaphore consumer;
    unsigned short sem[3];
    int *shm;
    int loop = LIMIT;
    int num,in=0;
    key_t key;
    
    printf("\nEnter the Key:");
    scanf("%d",&key);
    
    shmid = shmget( key, MEM, 0666 );
    
    if( shmid != -1 )
    {
        printf("\n\nShared Memory Access is Granted..........\n\n");
        
        shm = (int *)shmat(shmid,NULL,0);
        
        if(shm > 0)
        {   
            semid = semget(SEMKEY,3,0666);
            
            if(semid==-1)
                printf("\nError in creating the semaphore");
            else
            {  
                sem[0] = 1;
                sem[1] = 0;
                sem[2] = SHMSIZE;
                consumer.array = sem;
                
                do
                {
                    wait(semid,FULL);
                    wait(semid,MUTEX);
                    
                    printf("\nValue Produced:  %d\n",shm[in]);
                    in = (in + 1)%SHMSIZE;
                    
                    signal(semid,MUTEX);
                    signal(semid,EMPTY);
                                        
                }while(loop--);
             }
             
             if(shmdt(shm)==0)
                printf("\n\nShared Memory Detached\n\n");
                
             else
                printf("\n\nShared Memory Not Detached\n\n");
         }
          else
            printf("\n\nShared Memory Attachment failed..........\n\n");
            
    }
    else
        printf("\n\nShared Memory is not Created\n\n");
        
         
}
            
