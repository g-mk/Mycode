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
