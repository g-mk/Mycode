#include<iostream>
using namespace std;
typedef struct Info
{
public:
    int nValue;
}Info;
typedef struct RetInfo
{
    int nStatus;
    Info info;
}RetInfo;
class Node
{
public:
    friend class Array;
private:
    Info info;
    Node *pNext;

};
class Array
{
    public:
        RetInfo Find(int);
        int InsertAtFirst(int);
        int Display();
        void DisplayInfo(Info info);
        Array();
        ~Array();
    private:
        Node* head;
};
