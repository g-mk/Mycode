#include"hSelfArray.h"

Array :: Array()
{
    head =NULL;
}
int Array :: InsertAtFirst(int nValue)
{
    Node *newNode = new Node;
    newNode->info.nValue=nValue;
    newNode->pNext=NULL;
    if(head==NULL)
    {
        head = newNode;
        return 1;
    }
    else
    {
        newNode->pNext=head;
        head=newNode;
        return 1;
    }
        return 0;
}
RetInfo Array :: Find(int nValue)
{
    RetInfo rinfo;
    Node * Current = head;
    if(Current->info.nValue==nValue)
    {
        rinfo.info=Current ->pNext->info;
        rinfo.nStatus=1;
        return rinfo;
    }
    while(Current->pNext != NULL && Current ->pNext->info.nValue != nValue)
    {
        Current = Current ->pNext;
    }
    if(Current->pNext!= NULL)
    {

        rinfo.info=Current ->pNext->info;
        Node *temp=Current->pNext;
        Current->pNext=Current->pNext->pNext;
        rinfo.nStatus=InsertAtFirst(temp->info.nValue);
        delete Current;
        return rinfo;
    }

        rinfo.nStatus=0;
        return rinfo;

}
void Array :: DisplayInfo(Info info)
{
    cout<<"Data: "<<info.nValue<<endl;
}
int Array :: Display()
{
    Node *Current = head;
    if(Current == NULL)
        return 0;
    else
    {
        while(Current)
        {
            DisplayInfo(Current->info);
            Current=Current->pNext;
        }
    }
    return 1;
}
Array :: ~Array()
{
    Node* Current = head;
    if(Current)
    {
        Node *temp = Current;
        Current=Current->pNext;
        delete temp;
    }
}
