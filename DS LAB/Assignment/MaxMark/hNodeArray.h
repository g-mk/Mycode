#include<iostream>
using namespace std;
typedef struct Infomation
{
 char m_sName[30];
 int m_nRollNo;
 float m_fCutoff;
}Info;

class Node
{
 friend class LinkList;
  private:
          Info info;
          Node *link;
};

class LinkList
{
 public:
        LinkList();
        ~LinkList();
        Node * CreateNode();
        int InsertAfterPosition(Node *newNode, int pos);
        int InsertAtFront(Node *newNode);
        int InsertAtLast(Node *newNode);
        int DeleteByElement(int RollNo);
        int DeleteFirstNode();
        Node * FindByElement (int RollNo);
        int FindByPosition(int pos);
        void Print();
        void PrintNode(Node *);
        int GetData();
        Node* FindMax();
 private:
        Node *head;
        int Length;
};

