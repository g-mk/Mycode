#include<iostream>
#include<string.h>
#include<stdio.h>
using namespace std;
 typedef struct Info
 {
  char CommandName[20];
  char CommandSyntax[25];
  char CommandDetails[25];
  char CommandType[15];
 }Info;
class MinHeap
{
public:
    MinHeap();
    MinHeap(int nCap);
    ~MinHeap();
    int Insert(Info);
    int Delete();
    int Display(void (*fpointer)(Info));
private:
    int m_nHeapsize;
    int m_nCapacity;
    Info *heap;
};
