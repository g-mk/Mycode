/*******************************************************************************
**Description   : Deploying the Message Queue for the Interprocess            **
**                Communication between two process/program to share the      **
**                information(SERVER PROGRAM)                                 **
**Author        : N. Guru Manikandan.                                         **
**Date Created  : 04/08/2016.                                                 **
**Version       : 0.1                                                         **
*******************************************************************************/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>

typedef struct msg
{
    int qid;
    char mtext[50];
}msg;

typedef struct msgbuf
{
    long mtype;
    msg data;
}msgbuf;

void main()
{
    msgbuf dSnd,dRcv;
    int msgqid,run = 1,it,loop,client_id;
    key_t key;
    
    dSnd.mtype = 1;
    
    printf("\nEnter the Key:");
    scanf("%d",&key);
    
    msgqid = msgget(key, 0666 | IPC_CREAT);
    
    if( msgqid != -1 )
    {
        printf("\n\nMessage Queue Created..........\n\n");
    
        while(run)
        {
            printf("\n\nWaiting for the Message.........\n\n");
    
            if( msgrcv( msgqid, &dRcv, sizeof(msgbuf), 1, 0 ) != -1 )
            {
                if(strcmp(dRcv.data.mtext,"exit")==0)
                    break;
                
                printf("\n\nMessage Receievd from the Queue\n\n");
                printf("Data Received is %s",dRcv.data.mtext);
    
                loop = 0;
                it = 0;
    
                while(dRcv.data.mtext[loop]!='\0')
                {
                    switch(dRcv.data.mtext[loop])
                    {
                        case 'a':
                        case 'A':
                        case 'e':
                        case 'E':
                        case 'i':
                        case 'I':
                        case 'o':
                        case 'O':
                        case 'u':
                        case 'U': break;
                        default : dSnd.data.mtext[it++] = dRcv.data.mtext[loop];
                    }
                    loop++;
                }
    
                dSnd.data.mtext[it]='\0';
                client_id = dRcv.data.qid;
                
                printf("\n\nData to be Transmitted : %s\n\n",dSnd.data.mtext);
                
                if(msgsnd(client_id,&dSnd,sizeof(msgbuf),0)==-1)
                {
                    printf("\n\nError in Enqueue\n\n");
                    break;
                }
            }
            else
                printf("\n\nMessage not Received from the Queue\n\n");
        }
        
        printf("\n\nClosing the Server........\n\n");
 
        if( msgctl(msgqid, IPC_RMID, NULL) != -1)
            printf("\n\nMessage Queue Removed\n\n");
        else
            printf("\n\nMessage Queue Not Removed\n\n");
    }
    else
        printf("\n\nMessage Queue Not Created\n\n");
}
