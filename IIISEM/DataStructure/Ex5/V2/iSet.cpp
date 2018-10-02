#include"hSet.h"
using namespace HistoryOfCommands;
SET :: SET()
{
 root = NULL;
}
SET :: ~SET()
{
 /*while(root)
  {
   DeleteBST(root->info.CommandName,root);
  }*/
}
int SET :: InsertSET(Node* newnode)
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
 if(root)
  {

 if(strcmp(newnode->info.CommandName,CCurrent->info.CommandName)<0)
    {

        CCurrent -> LeftChild = newnode;
    }
   else
   {
       CCurrent -> RightChild = newnode;
   }
  }
 else
  root=newnode;
  return 1;
}

int SET :: SearchSET(Node* Current ,char *name)
{
 if(IsEmpty())
    return 0;
 if(!Current)
   return -1;
 else if (strcmp(name,Current->info.CommandName)==0)
   return 1;
 else if(strcmp(name,Current->info.CommandName)<0)
   return SearchSET(Current->LeftChild,name);
 else
   return SearchSET(Current->RightChild,name);
}

void SET::Display(Node* Current)
{
 cout<<"\nCommand Name : "<<Current->info.CommandName;
 cout<<"\nSyntax: "<<Current->info.CommandSyntax;
 cout<<"\nType: "<<Current->info.CommandType;
 cout<<"\nDescription: "<<Current->info.CommandDetails<<endl;
}

Node* SET::DeleteSET(char * name,Node *current)
{
 Node* returnNode = new Node;
 if(current==NULL)
 {
  return NULL;
 }
 else
 {
     if(root->LeftChild==NULL&&root->RightChild==NULL)
     {
         delete root;
         root=NULL;
         return returnNode;
     }

  if(strcmp(name,current->info.CommandName)<0)
   current->LeftChild=DeleteSET(name,current->LeftChild);
  else if(strcmp(name,current->info.CommandName)>0)
   current->RightChild=DeleteSET(name,current->RightChild);
  else
  {
   Node *temp;
   if(current->LeftChild && current->RightChild)
   {
    temp=FindMin(current->RightChild);
    current->info=temp->info;
    current->RightChild=DeleteSET(current->info.CommandName,current->RightChild);
    //return current;
   }
   else
   {
    temp=current;
    if(current->LeftChild==NULL)
     current=current->RightChild;
    else
     current=current->LeftChild;
     /*returnNode->info= temp->info;
     returnNode->LeftChild=temp->LeftChild;
     returnNode->RightChild=temp->RightChild;*/
     //return current;
   }
  }
  return current;
 }
 return NULL;
}

void SET::Inorder(Node *current)
{
 if(current)
 {
  Inorder(current->LeftChild);
  Display(current);
  Inorder(current->RightChild);
 }
// else
 // return NULL;
}
void SET::Preorder(Node *current)
{
 if(current)
 {
  Display(current);
  Preorder(current->LeftChild);
  Preorder(current->RightChild);
 }
}
void SET::Postorder(Node *current)
{
 if(current)
 {
  Postorder(current->LeftChild);
  Postorder(current->RightChild);
  Display(current);
 }
}

Node* SET :: FindMax(Node *current)
{
 if(current -> RightChild==NULL)
   return current;
 else
  return FindMax(current->RightChild);
}

Node* SET :: FindMin(Node *current)
{
 if(current -> LeftChild==NULL)
   return current;
 else
  return FindMin(current->LeftChild);
}

Info SET:: GetInfo()
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

Node* SET :: GetRoot()
{
    return root;
}
int SET :: IsEmpty()
{
 if(root==NULL)
   return 1;
 else
   return 0;
}

Node* SET :: CreateNode()
{
    Node* newnode = new Node;
    newnode->info=GetInfo();
    newnode->LeftChild=NULL;
    newnode->RightChild=NULL;
    return newnode;
}
void SET::Union(Node *current)
{
 if(current)
 {
  InsertSET(current);
  Union(current->LeftChild);
  Union(current->RightChild);
 }
}

