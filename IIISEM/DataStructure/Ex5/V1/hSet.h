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
      int InsertSET(Node*);
      Node* DeleteSET(char *,Node*);
      int SearchSET(Node*,char *);
      Node* FindMin(Node*);
      Node* FindMax(Node*);
      void Inorder(Node*);
      void Preorder(Node*);
      void Postorder(Node*);
      void Display(Node*);
      Info GetInfo();
      Node * GetRoot();
      int IsEmpty();
      void Union(Node* current);
   private:
      Node* root;
 };
}
