#include<iostream>
#include<string.h>
using namespace std;
namespace HistoryOfCommands
{
 typedef struct Info
 {
  char CommandName[20];
  char CommandSyntax[25];
  char CommandDetails[25];
  char CommandType[8];
 }Info;

/* typedef struct RetInfo
 {
  Info info;
  int nStatus;
 }RetInfo;*/

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
      Node * CreateNode();
      int InsertBST(Node*);
      Node* DeleteBST(char *,Node*);
      int SearchBST(Node*,char *);
      Node* FindMin(Node*);
      Node* FindMax(Node*);
      void Inorder(Node*);
      void Preorder(Node*);
      void Postorder(Node*);
      void Display(Node*);
      Info GetInfo();
      int IsEmpty();
 // private:
      Node* root;
 };
}
