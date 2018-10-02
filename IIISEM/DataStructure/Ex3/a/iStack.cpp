#include"hStack.h"

Stack::Stack()
{
    top =NULL;
    head =NULL;

}
Stack::~Stack()
{
    while(top)
        Pop();
}
int Stack::Push (Info info)
{
    Node *newNode = new Node;
    if(newNode == NULL )
        return -1;
    if(IsEmpty())
    {
        head = newNode;
        newNode -> info = info;
        newNode ->next = NULL;
        top = newNode;
        return 1;
    }
    else
    {
        newNode -> info = info;
        newNode -> next = NULL;
        top -> next = newNode;
        top = newNode;
        return 1;
    }
}
RetInfo Stack :: Pop()
{
    RetInfo rinfo;
    if(IsEmpty())
    {
        rinfo.status=0;
        return rinfo;
    }
    else
    {
        Node *current = head;
        if(head!=top)
        {
        while(current -> next != top)
        {
            current = current -> next;
        }
        }

        rinfo.status =1;
        rinfo.info=top->info;
        delete top;
        if(head==top)
         top=NULL;
        else
        {
          top = current;
          top->next = NULL;
        }
          return rinfo;
    }
}
RetInfo Stack :: ReturnTop()
{
    RetInfo rinfo;
    if(IsEmpty())
    {
        rinfo.status=0;
        return rinfo;
    }
    else
    {
        rinfo.status=1;
        rinfo.info=top->info;
        return rinfo;
    }
}
bool Stack :: IsEmpty()
{
    if(top == NULL)
        return 1;
    else
        return 0;
}
bool Stack :: IsFull(Node * newNode)
{
    if(newNode==NULL)
        return 1;
    else
        return 0;
}
