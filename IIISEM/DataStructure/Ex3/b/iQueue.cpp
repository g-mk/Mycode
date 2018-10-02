#include"hQueue.h"

Queue :: Queue()
{
 front = rear = NULL;
}
Queue :: ~Queue()
{

}
int Queue :: EnQueue(Info info)
{
 Node *newNode = new Node;
 if(newNode == NULL)
  return -1;
else
   {
    if(IsEmpty())
    {
      front = newNode;
      rear = newNode;
      newNode -> next = NULL;
      newNode -> info = info;
      return 1;
    }
   else
     { 
      rear -> next = newNode;
      newNode -> next  = NULL;
      newNode -> info = info;
      rear = newNode;
      return 1;
     }  
}
}
RetInfo Queue :: DeQueue()
{
 RetInfo rinfo;
 if(IsEmpty())
   {
     rinfo.status = -1;
     return rinfo;
   }
 else 
  {
    rinfo.status = 1;
    rinfo.info = front -> info;
    Node *temp = front;
    front = temp -> next;
    delete temp;
    if(front == NULL)
      rear = NULL;
    return rinfo;
   }
}
RetInfo Queue :: ReturnFront()
{
 RetInfo rinfo;
 if(IsEmpty())
  {
   rinfo.status=-1;
   return rinfo;
  }
 else 
  {
   rinfo.status = 1;
   rinfo.info = front -> info;
   return rinfo;
  }
}
RetInfo Queue :: ReturnRear()
{
 RetInfo rinfo;
 if(IsEmpty())
  {
   rinfo.status=-1;
   return rinfo;
  }
 else
  {
   rinfo.status = 1;
   rinfo.info = rear -> info;
   return rinfo;
  }
}
void Queue :: Display()
{
 Node *Current = front;
 while(Current != NULL)
  { cout<<"\n****************************************\n";
    cout<<"\nCommand Name : "<<Current -> info.CommandName;
    cout<<"\nSyntax: "<<Current -> info.CommandSyntax;
    cout<<"\nType: "<<Current -> info.CommandType;
    cout<<"\nDescription: "<<Current -> info.CommandDetails<<endl;
    cout<<"\n****************************************\n";
    Current = Current -> next;

  }
}
bool Queue :: IsEmpty()
{
 if(front == NULL)
   return 1;
 else 
   return 0;
}
