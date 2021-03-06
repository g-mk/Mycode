/*******************************************************************************
**Description   : Deploying the Message Queue for the Interprocess            **
**                Communication between two process/program to share the      **
**                information(CLIENT PROGRAM)                                 **
**Author        : N. Guru Manikandan.                                         **
**Date Created  : 04/08/2016.                                                 **
**Version       : 0.1                                                         **
*******************************************************************************/
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * strrev(char *string)
{
    int len = strlen(string),i;
    char *rev = (char*)malloc(sizeof(char)*len);
    
    strcpy(rev,string);
    
    for(i=0;i<len/2;i++)
    {
        char temp = rev[i];
        rev[i] = rev[len-1-i];
        rev[len-1-i] = temp;
    }
    
    return rev;
}

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
    int msgqid,run = 1,pqid;
    char *palin;
    key_t key;
    
    printf("\nEnter the Key:");
    scanf("%d",&key);
    
    msgqid = msgget(key, 0666);
    pqid = msgget(IPC_PRIVATE, 0666);
    
    dSnd.mtype = 1;
    dSnd.data.qid = pqid;
    
    if( msgqid != -1 && pqid != -1 )
    {
        while(run)
        {
            printf("\n\nEnter the message to Send: ");
            scanf("%s",dSnd.data.mtext);
            
            if( msgsnd( msgqid, &dSnd, sizeof(msgbuf), 0 ) != -1 )
            {
                if(strcmp(dSnd.data.mtext,"exit")==0)
                    break;
                printf("\n\nMessage added to the Queue\n\n");
                
                if(msgrcv(pqid, &dRcv, sizeof(msgbuf), 1, 0) != -1)
                {
            
                    palin = strrev(dRcv.data.mtext);
                    printf("\nReceived From Server : %s\n",dRcv.data.mtext);
 
                    if(strcmp(palin,dRcv.data.mtext)==0)
                        printf("\n\nString is Palindrome\n\n");
                    else
                        printf("\n\nString is Not a Palindrome\n\n");
                 }               
            }
            else
            {
                printf("\n\nMessage not added to the Queue\n\n");
                break;
            }
        }
        
        printf("\n\nConnection Lost.....\n\n");
    }
    else
        printf("\n\nMessage Queue Not Created\n\n");
}
