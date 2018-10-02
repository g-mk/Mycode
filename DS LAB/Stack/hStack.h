#include<iostream>
#define ERR_FULL -1
#define ERR_Empty -2
using namespace std;
typedef struct Info
{
    int RollNo;
    char Name[30];
    float CutOff;
}Info;
typedef struct RetInfo
{
    int status;
    Info info;
}RetInfo;
class Node
{
public:
    friend class Stack;
    Info info;
    Node *next;
};
class Stack
{
public:
    Stack();
    ~Stack();
    RetInfo Pop();
    int Push(Info info);
    RetInfo ReturnTop();
    bool IsEmpty();
    bool IsFull(Node *);
private:
    Node *top;
    Node *head;

};
