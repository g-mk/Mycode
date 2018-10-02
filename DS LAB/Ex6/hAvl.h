#include<iostream>
#include<string.h>
using namespace std;
typedef struct Info
 {
  char CommandName[20];
  char CommandSyntax[25];
  char CommandDetails[25];
  char CommandType[8];
 }Info;
class Node
 {
  public:
       Node();
       friend class AVL;
  private:
       Node* LeftChild;
       Node* RightChild;
       Info info;
       int Height;
 };
class AVL
 {
  public:
    AVL();
    ~AVL();
    int Height(Node*);
    Node* Insert(Info,Node*);
    int Insert(Info);
    Node* CreateNode();
    void Postorder(Node*);
    void Display(Node*);
    Info GetInfo();
    Node * GetRoot();
    void SetRoot(Node *);
    int IsEmpty();
    Node* SingleLeftRotation(Node*);
    Node* DoubleLeftRotation(Node*);
    Node* SingleRightRotation(Node*);
    Node* DoubleRightRotation(Node*);
  private:
    Node* root;
 };


