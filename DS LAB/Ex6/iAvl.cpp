#include"hAvl.h"
Node:: Node()
{
 Height=0;
}
AVL::AVL()
{
 root=NULL;
}
AVL::~AVL()
{

}
void AVL::Display(Node* Current)
{
 cout<<"\nCommand Name : "<<Current->info.CommandName;
 cout<<"\nSyntax: "<<Current->info.CommandSyntax;
 cout<<"\nType: "<<Current->info.CommandType;
 cout<<"\nDescription: "<<Current->info.CommandDetails<<endl;
}

void AVL::Postorder(Node *current)
{
 if(current)
 {
  Postorder(current->LeftChild);
  Postorder(current->RightChild);
  Display(current);
 }
}
Info AVL:: GetInfo()
{
  Info info;
 cout<<"\nCommand Name: ";
 cin>>info.CommandName;
 cout<<"\nCommand Syntax: ";
 cin>>info.CommandSyntax;
 cout<<"\nCommand Type: ";
 cin>>info.CommandType;
 cout<<"\nCommand Description: ";
 cin>>info.CommandDetails;
 return(info);
}
Node* AVL :: GetRoot()
{
    return root;
}
void AVL:: SetRoot(Node* current)
{
 root = current;
}
int AVL :: IsEmpty()
{
 if(root==NULL)
   return 1;
 else
   return 0;
}

Node* AVL :: CreateNode()
{
    Node* newnode = new Node;
    newnode->info=GetInfo();
    newnode->LeftChild=NULL;
    newnode->RightChild=NULL;
    return newnode;
}

int AVL::Height(Node *temp)
{
  if(temp==NULL)
    return -1;
  else
    return temp->Height;
}

int AVL :: Insert(Info info)
{
    root=Insert(info,root);
    return 1;
}

Node* AVL:: Insert(Info info,Node* temp)
{
 if(temp ==NULL)
  {
    temp=new Node;
    temp->info=info;
    temp->LeftChild=NULL;
    temp->RightChild=NULL;
  }
 else if(strcmp(info.CommandName,temp->info.CommandName)<0)
  {
    temp->LeftChild=Insert(info,temp->LeftChild);
    if(Height(temp->LeftChild)-Height(temp->RightChild)==2)
    {
     if(strcmp(info.CommandName,temp->LeftChild->info.CommandName)<0)
      temp=SingleLeftRotation(temp);
     else
      temp=DoubleLeftRotation(temp);
    }
  }
 else if(strcmp(info.CommandName,temp->info.CommandName)>0)
  {
    temp->RightChild=Insert(info,temp->RightChild);
    if(Height(temp->RightChild)-Height(temp->LeftChild)==2)
    {
     if(strcmp(info.CommandName,temp->RightChild->info.CommandName)>0)
      temp=SingleRightRotation(temp);
     else
      temp=DoubleRightRotation(temp);
    }
  }
      temp->Height=max(Height(temp->LeftChild),Height(temp->RightChild))+1;
 return temp;
}

Node* AVL :: SingleLeftRotation(Node* N1)
{
 Node* N2;
 N2=N1->LeftChild;
 N1->LeftChild=N2->RightChild;
 N2->RightChild=N1;
 N1->Height=Height(N1->LeftChild)-Height(N1->RightChild);
 N2->Height=Height(N2->LeftChild)-Height(N1->RightChild);
 return N2;
}

Node* AVL :: SingleRightRotation(Node* N1)
{
 Node* N2;
 N2=N1->RightChild;
 N1->RightChild=N2->LeftChild;
 N2->LeftChild=N1;
 N1->Height=Height(N1->RightChild)-Height(N1->LeftChild);
 N2->Height=Height(N2->RightChild)-Height(N1->LeftChild);
 return N2;
}

Node* AVL:: DoubleLeftRotation(Node* N1)
{
 N1->LeftChild=SingleRightRotation(N1->LeftChild);
 return SingleLeftRotation(N1);
}

Node* AVL:: DoubleRightRotation(Node* N1)
{
 N1->RightChild=SingleLeftRotation(N1->RightChild);
 return SingleRightRotation(N1);
}

