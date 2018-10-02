#include<iostream>
using namespace std;
class ListArr
{
 public:
  ListArr(int Arrcap);
  int Insert(int ele,int pos);
  int Delet (int pos);
  void Print();
  ~ListArr();
  int FindByEle(int ele);
  int FindByPos(int pos);
  void GetData();
 private:
  int *array,length,capacity;
};
