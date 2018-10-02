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
int SET :: InsertSET(Info info,int (*fpointer)(Info,Info))
{
 Node* newnode = new Node;
 newnode->info=info;
 newnode->LeftChild=NULL;
 newnode->RightChild=NULL;

 Node* Current=root;
 Node* CCurrent=NULL;
 while(Current)
 {
  CCurrent=Current;
  if(fpointer(newnode->info,Current->info)==0)
    return -1;
  else if(fpointer(newnode->info,Current->info)>0)
   Current=Current->RightChild;
  else if(fpointer(newnode->info,Current->info)<0)
   Current=Current->LeftChild;

 }
 if(root)
  {

 if(fpointer(newnode->info,CCurrent->info)<0)
    {

        CCurrent -> LeftChild = newnode;
    }
 else if(fpointer(newnode->info,CCurrent->info)>0)
   {
       CCurrent -> RightChild = newnode;
   }
  }
 else
  root=newnode;
 return 1;
}

int SET :: SearchSET(Node *Current,Info info,int (*fpointer)(Info,Info ))
{
 if(IsEmpty())
    return 0;
 if(!Current)
   return -1;
 else if (fpointer(info,Current->info)==0)
   return 1;
 else if(fpointer(info,Current->info)<0)
   return SearchSET(Current->LeftChild,info,fpointer);
 else
   return SearchSET(Current->RightChild,info,fpointer);
}

Node* SET::DeleteSET(Info info,Node *current,int (*fpointer)(Info,Info))
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

  if(fpointer(info,current->info)<0)
   current->LeftChild=DeleteSET(info,current->LeftChild,fpointer);
  else if(fpointer(info,current->info)>0)
   current->RightChild=DeleteSET(info,current->RightChild,fpointer);
  else
  {
   Node *temp;
   if(current->LeftChild && current->RightChild)
   {
    temp=FindMin(current->RightChild);
    current->info=temp->info;
    current->RightChild=DeleteSET(current->info,current->RightChild,fpointer);
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

void SET::Inorder(Node *current,void (*fpointer)(Info))
{
 if(current)
 {
  Inorder(current->LeftChild,fpointer);
  fpointer(current->info);
  Inorder(current->RightChild,fpointer);
 }
}
void SET::Preorder(Node *current,void (*fpointer)(Info))
{
 if(current)
 {
  fpointer(current->info);
  Preorder(current->LeftChild,fpointer);
  Preorder(current->RightChild,fpointer);
 }
}
void SET::Postorder(Node *current,void (*fpointer)(Info))
{
 if(current)
 {
  Postorder(current->LeftChild,fpointer);
  Postorder(current->RightChild,fpointer);
  fpointer(current->info);
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


void SET::Union(Node *current,int(*fpointer)(Info,Info))
{
 if(current)
 {
  InsertSET(current->info,fpointer);
  Union(current->LeftChild,fpointer);
  Union(current->RightChild,fpointer);
 }
}

