/*******************************************************************************
**Description   : Implementation of Producer Consumer Problem using Semaphoer **
**                (Producer)                                                  **
**Author        : N. Guru Manikandan.                                         **
**Date Created  : 25/08/2016.                                                 **
**Version       : 0.1                                                         **
*******************************************************************************/
#include "semProCon.h"

union semaphore
{
    int val;
    struct semid_ds *buf;
    struct seminfo *_buf;
    unsigned short *array;
};

void wait(int sid, short sno)
{
    int a;
    struct sembuf s;
    s.sem_num = sno;
    s.sem_op = -1;
    a = semop(sid,&s,1);
}

void signal(int sid, short sno)
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
    union semaphore producer;
    unsigned short sem[3];
    int * shm;
    int i,loop=LIMIT;
    int num,in=0;
    key_t key;
    
    printf("\nEnter the Key:");
    scanf("%d",&key);
    
    shmid = shmget( key, MEM, 0666 | IPC_CREAT);
    
    if( shmid != -1 )
    {
        printf("\n\nShared Memory Access is Granted..........\n\n");
        
        shm = (int *)shmat(shmid,NULL,0);
        
        if(shm > 0)
        {   
            semid = semget(SEMKEY,3,0666|IPC_CREAT);
            
            if(semid==-1)
                printf("\nError in creating the semaphore");
            else
            {
            
                sem[0] = 1;
                sem[1] = 0;
                sem[2] = SHMSIZE;
                producer.array = sem;
                semctl(semid,0,SETALL,producer);
                
                do
                {
                    wait(semid,EMPTY);
                    wait(semid,MUTEX);
                    
                    printf("\nEnter the value:");
                    scanf("%d",&shm[in]);
                    in = (in + 1)%SHMSIZE;
                    
                    signal(semid,MUTEX);
                    signal(semid,FULL);
                                        
                }while(loop--);
             }
             
             if(shmdt(shm)==0)
                printf("\n\nShared Memory Detached\n\n");
                
             else
                printf("\n\nShared Memory Not Detached\n\n");
             
             stat = shmctl(shmid,IPC_RMID,0);
       
             if( stat !=-1 )
                printf("\n\nShared Memory Deleted\n\n");
             else
                printf("\n\nShared Memory Not Deleted\n\n");  
         }
          else
            printf("\n\nShared Memory Attachment failed..........\n\n");
            
    }
    else
        printf("\n\nShared Memory is not Created\n\n");
        
         
}
