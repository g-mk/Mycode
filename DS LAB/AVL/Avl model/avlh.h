#include<iostream>
using namespace std;

struct Info
{
  int data;
};

class AvlNode
{
  friend class AvlTree;
  Info info;
  AvlNode *left;
  AvlNode *right;
  int height;
};

class AvlTree
{
  public:
   AvlTree();
   ~AvlTree();
   int height(AvlNode*);
   void Insert(Info);
   AvlNode* insert(Info,AvlNode*);
   AvlNode* rotateWithLeftChild(AvlNode*);
   AvlNode* doubleWithLeftChild(AvlNode*);
   AvlNode* rotateWithRightChild(AvlNode*);
   AvlNode* doubleWithRightChild(AvlNode*);
  void Traverse(); 
  void traverse(AvlNode*);
 
  private:
   AvlNode *root;
};

  
