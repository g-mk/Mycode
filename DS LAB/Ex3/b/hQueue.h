#include<iostream>
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
    friend class Queue;
    Info info;
    Node *next;
};
class Queue
{
public:
    Queue();
    ~Queue();
    RetInfo DeQueue();
    int EnQueue(Info info);
    RetInfo ReturnFront();
    RetInfo ReturnRear();
    void Display();
    bool IsEmpty();
private:
    Node *rear;
    Node *front;

};
