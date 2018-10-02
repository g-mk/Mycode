#include "avlh.h"
AvlTree::AvlTree()
{
  root=NULL;
}

AvlTree::~AvlTree()
{
  root=NULL;
}

int AvlTree::height(AvlNode *t)
{
  if(t==NULL)
    return -1;
  else
    return t->height;
}

void AvlTree::Insert(Info x)
{
  root=insert(x,root);
}

AvlNode* AvlTree::insert(Info x, AvlNode *t)
{
  if(t==NULL)
  {
    t=new AvlNode;
    t->info=x;
    t->left=t->right=NULL;
  }
  else if(x.data<t->info.data)
  {
    t->left=insert(x,t->left);
    if(height(t->left)-height(t->right)==2)
      if(x.data<t->left->info.data)
        t=rotateWithLeftChild(t);
      else
        t=doubleWithLeftChild(t);
  }
  else if(x.data>t->info.data)
  {
    t->right=insert(x,t->right);
    if(height(t->right)-height(t->left)==2)
      if(t->right->info.data<x.data)
        t=rotateWithRightChild(t);
      else
        t=doubleWithRightChild(t);
  }
  else
    ;  // Duplicate do nothing
  t->height=max(height(t->left),height(t->right))+1;
  return t;
}

AvlNode* AvlTree::rotateWithLeftChild(AvlNode *k1)
{
  AvlNode *k2=k1->left;
  k1->left=k2->right;
  k2->right=k1;
  k1->height=max(height(k1->left),height(k2->right))+1;
  k2->height=max(height(k2->left),k1->height)+1;
  return k2;
}

AvlNode* AvlTree::doubleWithLeftChild(AvlNode *k1)
{
  rotateWithRightChild(k1->left);
  return rotateWithLeftChild(k1);
}

AvlNode* AvlTree::rotateWithRightChild(AvlNode *k1)
{
  AvlNode *k2=k1->right;
  k1->right=k2->left;
  k2->left=k1;
  k1->height=max(height(k1->left),height(k2->right))+1;
  k2->height=max(height(k2->left),k1->height)+1;
  return k2;
}

AvlNode* AvlTree::doubleWithRightChild(AvlNode *k1)
{
  rotateWithRightChild(k1->left);
  return rotateWithLeftChild(k1);
}

void AvlTree::Traverse()
{
  traverse(root);
//  cout<<root->info.data;
}

void AvlTree::traverse(AvlNode* current)
{
  if(current)
  {
    traverse(current->left);
    traverse(current->right);
    cout<<current->info.data<<endl;
  }
}

