#include "avlh.h"
Info getInfo()
{
  Info info;
  cout<<"Enter Data: ";
  cin>>info.data;
  return info;
}

main()
{
  AvlTree a;
  Info info;
  info=getInfo();
  a.Insert(info);
  info=getInfo();
  a.Insert(info);
  info=getInfo();
  a.Insert(info);
  a.Traverse();
}

