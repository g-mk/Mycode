#include"hNodeArray.h"

LinkList :: LinkList()
{
 head = NULL;
 Length=0;
}

LinkList :: ~LinkList()
{
 Node *temp;
 temp = head;
 while(head)
 { 
  temp = head->link;
  delete head;
  head = temp;
 }
}
Node * LinkList :: CreateNode()
{
 Node *newNode= new Node;
 cout << "Enter the Student Name: ";
 cin >> newNode -> info.m_sName;
 cout << "Enter the RollNo.: ";
 cin >> newNode -> info.m_nRollNo;
 CutOff:
 cout << "Enter the Students Cuttoff Mark: ";
 cin >> newNode -> info.m_fCutoff;
 if( newNode -> info.m_fCutoff < 0 ||  newNode -> info.m_fCutoff > 200)
   {
    cout << "Entered Cutoff is not a Valid Mark....\n";
    goto CutOff; 
   }
 newNode -> link = NULL;
 return newNode;
}
int LinkList :: GetData()
{
 char c;
 Info info;
 Node *newNode = CreateNode();
 InsertAtFront(newNode);
 do
 {
  
  cout<<"Press Y to Continue or Press N to Stop ";
  cin >> c;
  if( c == 'Y'||c == 'y')
   {
    Node *newNode = CreateNode();
    if(newNode == NULL )
     return 0;
    InsertAtLast(newNode);
   }
 }while( c == 'y'||c == 'Y');
 return 1;
}
int LinkList :: InsertAfterPosition(Node *newNode, int pos)
{
 Node *Current = head;
 int i=1;
 if(newNode==NULL)
  {
   return -1;
  }
 else
  {
   if(pos-1 ==0 || head == NULL )
     return InsertAtFront(newNode);
   else if(pos == Length+1)
     return InsertAtLast(newNode);
  else if(pos <=Length)
   {
    while( Current != NULL && i < pos-1 )
     {
      Current = Current -> link;
      i++;
     }
   newNode -> link = Current -> link; 
   Current -> link = newNode;
   Length++;
   return 1;
    }
  else 
    return 0;
  }
}
int LinkList :: InsertAtFront(Node * newNode )
{
 if(newNode == NULL)
  return -1;
 else
 {
  if(head == NULL)
   {
    head = newNode;
    newNode -> link = NULL;
    Length++;
    return 1;
   }
  else 
   { 
    newNode -> link = head;
    head = newNode;
    Length++;
   }
   return 1;
 }
}
int LinkList :: InsertAtLast(Node *newNode)
{
 if(newNode == NULL)
  return -1;
 else
  {
   Node *Current = head;
     while(Current -> link !=NULL)
        Current = Current -> link;
     Current -> link = newNode;
     newNode -> link = NULL;
     Length++;
     return 1;
  }
}
int LinkList :: DeleteFirstNode()
{
 Node * Current = head;
 head = head -> link;
 delete Current;
 Length--;
 return 1;
} 
int LinkList :: DeleteByElement(int RollNo )
{
 Node * Current;
 Node *temp;
 Current = head;
 
 if(Current -> info.m_nRollNo == RollNo )
  {
   return  DeleteFirstNode();
   
  }
 else 
 {
  while ( Current -> link != NULL && Current -> link -> info.m_nRollNo != RollNo )
   {
    Current == Current -> link;
   }
  if ( Current -> link != NULL ) 
   {
    temp = Current -> link;
    Current -> link = Current -> link -> link;
    delete temp;
    Length--;
    return 1;
   }
  else 
    return 0;
 }
}
Node * LinkList :: FindByElement(int RollNo)
{
 Node *Current = head;
 while(Current -> link != NULL && Current -> info.m_nRollNo != RollNo )
  {
     Current = Current -> link;
  }
  if(Current -> info.m_nRollNo== RollNo)
   return Current;
  else
  return NULL ;
}
int LinkList :: FindByPosition(int Pos)
{
 Node *Current =head;
 int Count =1;
 while(Current != NULL && Count < Pos)
  {
   Current = Current -> link;
   Count++;
  }
 if(Current)
  {
   PrintNode(Current);
   return 1; 
  }
 else
  return 0;
}
void LinkList :: Print()
{
 Node *Current = head;
 while(Current)
  {
   cout<<"\nName: "<< Current -> info.m_sName<<endl;
   cout<<"RollNO: "<< Current -> info.m_nRollNo<<endl;
   cout<<"CutOff: "<<Current -> info.m_fCutoff<<endl;
   Current = Current -> link;
  }
  cout << "Length is "<<Length <<endl;
 }
void LinkList :: PrintNode(Node *Current)
{
 cout<<"\nName: "<< Current -> info.m_sName<<endl;
 cout<<"RollNO: "<< Current -> info.m_nRollNo<<endl;
 cout<<"CutOff: "<<Current -> info.m_fCutoff<<endl;
}
