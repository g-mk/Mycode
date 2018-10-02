#include<iostream>
using namespace std;
/*typedef struct Infomation
{
 char m_sName[30];
 int m_nRollNo;
 float m_fCutoff;
}Info;*/
template <typename T>
class Node
{
 friend class LinkList;
  private:
          T Val;
          Node *link;
};

template<typename T,typename T1=Node>

class LinkList
{
 public:
        LinkList();
        ~LinkList();
        T1 * CreateNode();
        int InsertAfterPosition(T1 *newNode, int pos);
        int InsertAtFront(T1 *newNode);
        int InsertAtLast(T1 *newNode);
        int DeleteByElement(T Val);
        int DeleteFirstNode();
        T1 * FindByElement (T Val);
        int FindByPosition(int pos);
        void Print();
        void PrintNode(T1 *);
        int GetData();
 private:
        T1 *head;
        int Length;
};

