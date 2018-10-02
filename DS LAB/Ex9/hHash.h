#include<iostream>
#include<string.h>
using namespace std;
typedef struct Info
{
    char CommandName[20];
    char CommandSyntax[25];
    char CommandDetails[25];
    char CommandType[15];
}Info;

class Node
{
    friend class HashTable;
 private:
 Info info;
 Node* pNext;
};

class HashTable
{
 public:
   HashTable();
   HashTable(int num);
   int hash(Info);
   int insert(Info);
   Node * find(Info,int (*fpointer)(Info,Info));
   void displayTable(void (*fpointer)(Info));
 private:
   Node** Bucket;
   int NoOfBuckets;
};
