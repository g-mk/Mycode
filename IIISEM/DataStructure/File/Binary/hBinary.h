#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
namespace HistoryOfCommands
{
 typedef struct Info
 {
  char CommandName[20];
  char CommandSyntax[25];
  char CommandDetails[25];
  char CommandType[10];
 }Info;
 class Node
 {
  public:
       friend class BST;
  private:
       Node* LeftChild;
       Node* RightChild;
       Info info;
 };

 class BST
 {
  public:
      BST();
      ~BST();
      int InsertBST(Info,int (*fpointer)(Info,Info));
      Node* DeleteBST(Info,Node*,int (*fpointer)(Info,Info));
      int SearchBST(Node*,Info,int (*fpointer)(Info,Info));
      Node* FindMin(Node*);
      Node* FindMax(Node*);
      void Inorder(Node*,void (*fpointer)(Info));
      void Preorder(Node*,void (*fpointer)(Info));
      void Postorder(Node*,void (*fpointer)(Info));
      Node * GetRoot();
      int IsEmpty();
  private:
      Node* root;
 };
}
