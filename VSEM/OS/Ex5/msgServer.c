/*******************************************************************************
**Description   : Deploying the Shared Memory for the Interprocess            **
**                Communication between two process/program to share the      **
**                information(SERVER PROGRAM)                                 **
**Author        : N. Guru Manikandan.                                         **
**Date Created  : 04/08/2016.                                                 **
**Version       : 0.1                                                         **
*******************************************************************************/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <string.h>
#define MEM 50

void main()
{
    int shmid,stat;
    char * shm;
    key_t key;
    
    
    printf("\nEnter the Key:");
    scanf("%d",&key);
    
    shmid = shmget(key, MEM, 0666 | IPC_CREAT);
    
    if( shmid != -1 )
    {
        printf("\n\nShared Memory Created..........\n\n");
    
        shm = (char *)shmat(shmid,NULL,0);
        if(shm > 0)
        {
             printf("\n\nEnter the Number Sequence: ");
             scanf(" %[^\n]",shm);
             
             printf("\n\nValue Stored in the Shared Memory\n\n");
             
             while(strcmp(shm,"")!=0);
                          
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
