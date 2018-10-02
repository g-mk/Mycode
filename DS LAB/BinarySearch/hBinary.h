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
      BST();                          //Constructor
      ~BST();                         //Destructor
      Node * CreateNode();            //To Create a Node
      int InsertBST(Node*);           //To Insert the Node
      Node* DeleteBST(char *,Node*);  //To Delete the Node
      int SearchBST(Node*,char *);    //To Search the Element
      Node* FindMin(Node*);           //To Find the Minimum in the Tree
      Node* FindMax(Node*);           //To Find the Maximum in the Tree
      void Inorder(Node*);            //Inorder Traversal
      void Preorder(Node*);           //Preorder Traversal
      void Postorder(Node*);          //Postorder Traversal
      void Display(Node*);            //To display the content
      Info GetInfo();                 //To Get the information 
      Node * GetRoot();               //To Get the Root of the Tree
      int IsEmpty();
  private:
      Node* root;
 };
}
