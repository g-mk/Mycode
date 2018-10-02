#include"hBinary.h"
using namespace HistoryOfCommands;
BST :: BST()
{
 root = NULL;
}
BST :: ~BST()
{
 /*while(root)
  {
   DeleteBST(root->info,root);
  }*/
}
int BST :: InsertBST(Info info,int (*fpointer)(Info,Info))
{
 Node* newnode=new Node;
 newnode->info=info;
 newnode->LeftChild=NULL;
 newnode->RightChild=NULL;
 Node* Current=root;
 Node* CCurrent=NULL;
 while(Current)
 {
  CCurrent=Current;
  if(fpointer(newnode->info,Current->info)<0)
   Current=Current->LeftChild;
  else if(fpointer(newnode->info,Current->info)>0)
   Current=Current->RightChild;
  else
   return -1;
 }
 if(root)
  {

 if(fpointer(newnode->info,CCurrent->info)<0)
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

int BST :: SearchBST(Node* Current ,Info info,int (*fpointer)(Info,Info))
{
 if(IsEmpty())
    return 0;
 if(!Current)
   return -1;
 else if (fpointer(info,Current->info)==0)
   return 1;
 else if(fpointer(info,Current->info)<0)
   return SearchBST(Current->LeftChild,info,fpointer);
 else
   return SearchBST(Current->RightChild,info,fpointer);
}

Node* BST::DeleteBST(Info info,Node *current,int (*fpointer)(Info,Info))
{
 
 Node* returnNode =new Node;
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
   current->LeftChild=DeleteBST(info,current->LeftChild,fpointer);
  else if(fpointer(info,current->info)>0)
   current->RightChild=DeleteBST(info,current->RightChild,fpointer);
  else
  {
   Node *temp;
   if(current->LeftChild && current->RightChild)
   {
    temp=FindMin(current->RightChild);
    current->info=temp->info;
    current->RightChild=DeleteBST(current->info,current->RightChild,fpointer);
   }
   else
   {
    temp=current;
     if(current->LeftChild==NULL)
       {
        if(current == root)
        {
         temp = root;
         root = current -> RightChild;
         delete temp;
        }
        else
         current = current->RightChild;
       }
    else if(current->RightChild==NULL)
     {
      if(current == root)
        {
         temp = root;
         root = current -> LeftChild;
         delete temp;
        }
      else
       current = current ->LeftChild;
     }
   }
  }
  return current;
 }
}

void BST::Inorder(Node *current,void (*fpointer)(Info))
{
 if(current)
 {
  Inorder(current->LeftChild,fpointer);
  fpointer(current->info);
  Inorder(current->RightChild,fpointer);
 }
}
void BST::Preorder(Node *current,void (*fpointer)(Info))
{
 if(current)
 {
  fpointer(current->info);
  Preorder(current->LeftChild,fpointer);
  Preorder(current->RightChild,fpointer);
 }
}
void BST::Postorder(Node *current,void (*fpointer)(Info))
{
 if(current)
 {
  Postorder(current->LeftChild,fpointer);
  Postorder(current->RightChild,fpointer);
  fpointer(current->info);
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

Node* BST :: GetRoot()
{
    return root;
}
int BST :: IsEmpty()
{
 if(root==NULL)
   return 1;
 else
   return 0;
}
