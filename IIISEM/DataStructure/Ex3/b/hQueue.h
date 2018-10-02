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
    Queue();                //Constructor
    ~Queue();               //Destructor
    RetInfo DeQueue();      //Delete the element in the Queue
    int EnQueue(Info info); //Add the Element in the Queue
    RetInfo ReturnFront();  //Retrive the Front element
    RetInfo ReturnRear();   //Retrive the Rear element
    void Display();         //Display the Queue
    bool IsEmpty();         //To check whether the Queue is empty or not
private:
    Node *rear;
    Node *front;

};
