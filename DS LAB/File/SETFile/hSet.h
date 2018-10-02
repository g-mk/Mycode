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
  char CommandType[15];
 }Info;

 class Node
 {
  public:
       friend class SET;
  private:
       Node* LeftChild;
       Node* RightChild;
       Info info;
 };

 class SET
 {
  public:
      SET();
      ~SET();
      Node * CreateNode();
      int InsertSET(Info);
      Node* DeleteSET(char *,Node*);
      int SearchSET(Node*,char *);
      Node* FindMin(Node*);
      Node* FindMax(Node*);
      void Inorder(Node*,void (*fpointer)(Info));
      void Preorder(Node*,void (*fpointer)(Info));
      void Postorder(Node*,void (*fpointer)(Info));
      Node * GetRoot();
      int IsEmpty();
      void Union(Node* current);
   private:
      Node* root;
 };
}
