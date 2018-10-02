#include"hSymbol.h"
ht initialize()
{
    ht hash;
    int i;
    hash =(ht)malloc(sizeof(struct Hashtable));
    hash -> lists = (List*)malloc(26*sizeof(List));
    for(i=0;i<26;i++)
    {
        hash -> lists[i] = (List)malloc(sizeof(Symbol));
        hash -> lists[i] -> next = NULL;
    }
    return hash;
}

int hashFunction(int nVal)
{
    if(nVal>=97)
        nVal -= 97;
    else if(nVal>=65)
        nVal -= 65;
    return nVal;
}

List searchSymbol(char* sName,char* sSegName,ht hash)
{
    int nKey;
    nKey = hashFunction(sName[0]);
    List Current = hash -> lists[nKey] -> next;
    if(Current)
    {
        while(Current!= NULL)
        {
           if(strcmp(sName,Current -> m_sName) == 0 &&strcmp(sSegName,Current -> m_sSegName) == 0)
                 return Current;
            else
              Current = Current -> next;


        }
    }
    return NULL;
}

int insertSymbol(char* sName,char* sSegName,char* sType, unsigned int nAddress,unsigned int nLength,ht hash)
{
    List Node = (List)malloc(sizeof(Symbol));
    strcpy(Node->m_sName,sName);
    strcpy(Node->m_sSegName,sSegName);
    strcpy(Node->m_sType,sType);
    Node->m_nAddress=nAddress;
    Node->m_nLength=nLength;
    Node -> next =NULL;

    int nKey = hashFunction(Node->m_sName[0]);
    List Status = searchSymbol(Node->m_sName,Node->m_sSegName,hash);
    if(!Status)
    {
        List Node = (List)malloc(sizeof(Symbol));
        strcpy(Node->m_sName,sName);
        strcpy(Node->m_sSegName,sSegName);
        strcpy(Node->m_sType,sType);
        Node->m_nAddress=nAddress;
        Node->m_nLength=nLength;
        Node -> next =NULL;
        List Current = hash -> lists[nKey];
        while(Current -> next != NULL)
        {
            if(strcmp(Node->m_sName,Current -> next -> m_sName)>0)
                Current = Current -> next;

            else if(strcmp(Node->m_sName,Current -> next -> m_sName)==0)
            {
                if(strcmp(Node->m_sSegName,Current -> next -> m_sSegName)>0)
                    Current = Current -> next;
                else
                    break;
            }
            else
                break;
        }
        Node->next = Current -> next;
        Current -> next = Node;
        return 1;
    }
    else
        return 0;
}

int modifySymbol(Symbol edit,int nOption,ht hash)
{
    List Status;
    Status = searchSymbol(edit.m_sName,edit.m_sSegName,hash);
    if(Status!=NULL)
     {
        switch(nOption)
        {
        case 1:
            strcpy(Status -> m_sType,edit.m_sType);
            break;
        case 2:
            Status -> m_nLength = edit.m_nLength;
            break;
        case 3:
            Status -> m_nAddress = edit.m_nAddress;
        }
        return 1;
    }
   else
        return 0;
}

void displaySymbol(ht hash)
{
    int i;
    printf("\nBUCKET\tNAME\tSEG_NAME\tTYPE\tADDRESS\tLENGTH\n");
    for(i=0;i<26;i++)
    {
        List Current = hash -> lists[i] -> next;
        if(Current != NULL)
        {
            while(Current!=NULL)
            {
                printf("\n%d\t%s\t%s         \t%s\t%x\t%u\n",i+1,Current -> m_sName,Current -> m_sSegName,
                    Current -> m_sType,Current -> m_nAddress,Current -> m_nLength);
                Current = Current -> next;
            }
        }
    }
}
