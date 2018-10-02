#include"hHash.h"
HashTable :: HashTable()
{

}

HashTable :: HashTable(int num )
{
 Bucket = new Node*[num];
 for(int i=0;i<num;i++)
    Bucket[i]=NULL;
 NoOfBuckets=num;
}

int HashTable :: hash(Info info)
{
 if(info.CommandName[0]>=97)
  return (info.CommandName[0]-97);
 else
  return (info.CommandName[0]-65);
}

int HashTable :: insert(Info info)
{
 int loc = hash(info);
 Node *newnode = new Node;
 newnode->info= info;
 newnode->pNext=NULL;
 if(!Bucket[loc])
    Bucket[loc]=newnode;
 else
 {
    newnode->pNext=Bucket[loc];
    Bucket[loc] = newnode;
 }
 return 1;
}

Node* HashTable :: find (Info info,int (*fpointer)(Info,Info))
{
 int loc = hash(info);
 Node* current = Bucket[loc];
 while(current)
 {
  if(fpointer(info,current->info))
   return current;
  current = current->pNext;
 }
 return NULL;
}

void HashTable :: displayTable(void (*fpointer)(Info))
{
    Node* current;
    for(int i=0;i<NoOfBuckets;i++)
    {
        current = Bucket[i];
        while(current)
        {
            fpointer(current->info);
            current=current->pNext;
        }
    }
}

