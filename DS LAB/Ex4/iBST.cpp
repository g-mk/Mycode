#include"hBST.h"
using namespace HistoryOfCommands;
BST :: BST()
{
 root = NULL;
}
BST :: ~BST()
{
 while(root)
  {
   DeleteBST(root->info.CommandName,root);
  }
}
int BST :: InsertBST(Node* newnode)
{
 Node* Current=root;
 Node* CCurrent=NULL;
 while(Current)
 {
  CCurrent=Current;
  if(strcmp(newnode->info.CommandName,Current->info.CommandName)<0)
   Current=Current->LeftChild;
  else if(strcmp(newnode->info.CommandName,Current->info.CommandName)>0)
   Current=Current->RightChild;
  else
   return -1;
 }
 cout<<"After While\n";
 if(root)
  {
      cout<<"If\n";
 if(strcmp(newnode->info.CommandName,CCurrent->info.CommandName)<0)
    {
        cout<<"Left\n";
        CCurrent -> LeftChild = newnode;
    }
   else
   {
       CCurrent -> RightChild = newnode;
       cout<<"Right\n";
   }
  }
 else
  root=newnode;
}

int BST :: SearchBST(Node* Current ,char *name)
{
 if(!Current)
   return NULL;
 else if(strcmp(name,Current->info.CommandName)<0)
   return SearchBST(Current->LeftChild,name);
 else
   return SearchBST(Current->RightChild,name);
}

void BST::Display(Node* Current)
{
 cout<<"\nCommand Name : "<<Current->info.CommandName;
 cout<<"\nSyntax: "<<Current->info.CommandSyntax;
 cout<<"\nType: "<<Current->info.CommandType;
 cout<<"\nDescription: "<<Current->info.CommandDetails<<endl;
}

Node* BST::DeleteBST(char * name,Node *current)
{
 if(current==NULL)
 {
  return NULL;
 }
 else
 {
  if(strcmp(name,current->info.CommandName)<0)
   current->LeftChild=DeleteBST(name,current->LeftChild);
  else if(strcmp(name,current->info.CommandName)>0)
   current->RightChild=DeleteBST(name,current->RightChild);
  else
  {
   if(current->LeftChild && current->RightChild)
   {
    Node  *temp=FindMin(current->RightChild);
    current->info=temp->info;
    current->RightChild=DeleteBST(current->info.CommandName,current->RightChild);
   }
   else
   {
    Node *temp=current;
    if(current->LeftChild==NULL)
     current=current->RightChild;
    else
     current=current->LeftChild;
     return temp;
    delete temp;
   }
  }
 }
}

void BST::Inorder(Node *current)
{
 if(current)
 {
  Inorder(current->LeftChild);
  Display(current);
  Inorder(current->RightChild);
 }
}
void BST::Preorder(Node *current)
{
 if(current)
 {
  Display(current);
  Preorder(current->LeftChild);
  Preorder(current->RightChild);
 }
}
void BST::Postorder(Node *current)
{
 if(current)
 {
  Preorder(current->LeftChild);
  Preorder(current->RightChild);
  Display(current);
 }
}

Node* BST :: FindMax(Node *current)
{
 if(current -> RightChild==NULL)
   return current;
 else
  return FindMax(current->RightChild);
}

Node* BST :: FindMin(Node *current)
{
 if(current -> LeftChild==NULL)
   return current;
 else
  return FindMin(current->LeftChild);
}

Info BST:: GetInfo()
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

int BST :: IsEmpty()
{
 if(root==NULL)
   return 1;
 else
   return 0;
}

Node* BST :: CreateNode()
{
    Node* newnode = new Node;
    newnode->info=GetInfo();
    newnode->LeftChild=NULL;
    newnode->RightChild=NULL;
    return newnode;
}
