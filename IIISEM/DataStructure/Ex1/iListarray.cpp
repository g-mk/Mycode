#include"hListarray.h"
ListArr :: ListArr(int Arrcap)        //Constructor 
{
 capacity = Arrcap;
 length=0;
 array=new int [capacity];
}
ListArr :: ~ListArr()             //Destructor
{
 delete []array;
}
void ListArr :: GetData()            //Geting Data for the List
{ char c;

 do
 { 
   if(length<=capacity)
   {
    cout<<"Enter the Element:";
    cin>>array[length++];
   }
  else
   cout << "Limit Exceeds....\n";

   cout<<"\nPress Y to continue giving value or Press N to Stop ";
   cin>>c;
 }while(c == 'y');
 cout<<"Total element in list "<< length<<"\n";
 Print();
}
int ListArr :: Insert(int ele,int pos)    // Insert the element in the list
{
 if(pos==length+1 && pos<=capacity)
 {
  array[pos-1]=ele;                        //Inserting the element at last
  length++;
  Print();
  return 1;
 }
 else
 { 
  if(pos<=length)
   { 
    for(int i=length-1;i>=pos-1;i--)      
      {
        array[i+1]=array[i];
      }
    array[pos-1]=ele;                     // Inserting in the Middle
    length++;
    Print();
    return 1;
   }
  else
   return 0;
 }
}
int ListArr :: Delet(int pos)           // Deleting the element int the list
{
 if(pos<=length)
 {
  int temp=array[pos-1];
  for(int i=pos;i<length;i++)
   array[i-1]=array[i];
  length--;
  Print();
  return temp;
 }
 else
  return -1;
}
int ListArr :: FindByEle(int ele)       //Searching by element in the list
{
 for(int i=0;i<length;i++)
  {
   if(array[i]==ele)
     return i;
  }
 return -1;
}
int ListArr :: FindByPos(int pos)  //Searching the element at the given position
{
 if(pos<=length)
   return array[pos-1];
 else 
   return -1;
} 
void ListArr :: Print()       //Printing the content in the list
{
 cout<<"\nFrom Initial Position"<<endl;
 for(int i=0;i<length;i++)
  {
   cout<<array[i]<<" ";
  }
 cout<<"\nFrom Last Position\n";
 for(int i=length-1;i>=0;i--)
  {
   cout<<array[i]<<" ";
  }
  cout <<"\nLength is "<<length;
  cout <<endl;
} 
