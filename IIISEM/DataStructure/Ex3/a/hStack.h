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
    RetInfo Pop();  //Pop out the element 
    int Push(Info info); //Push the element in the Stack
    RetInfo ReturnTop(); //Retrive the Top Element
    bool IsEmpty();  //To Check the Stack is empty 
    bool IsFull(Node *); //To Check the Stack is Full
private:
    Node *top;
    Node *head;

};
