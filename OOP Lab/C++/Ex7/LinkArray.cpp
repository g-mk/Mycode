#include<iostream>
using namespace std;
/*typedef struct Infomation
{
 char m_sName[30];
 int m_nRollNo;
 float m_fCutoff;
}Info;*/
template <typename X>
class Node
{
 template<typename T,typename T1>
 friend class LinkList;
  private:
          X Val;
          Node *link;
};

template<typename T,typename T1>
class LinkList
{
 public:
        LinkList();
        ~LinkList();
        T1 * CreateNode();
        int InsertAfterPosition(T1 *newNode, int pos);
        int InsertAtFront(T1 *newNode);
        int InsertAtLast(T1 *newNode);
        int DeleteByElement(T Val);
        int DeleteFirstNode();
        T1 * FindByElement (T Val);
        int FindByPosition(int pos);
        void Print();
        void PrintNode(T1 *);
        int GetData();
 private:
        T1 *head;
        int Length;
};
//Implementation....
template<typename T,typename T1>

LinkList<T,T1> :: LinkList()
{
 head = NULL;
 Length=0;
}
template<typename T,typename T1>

LinkList<T,T1> :: ~LinkList()
{
 T1 *temp;
 temp = head;
 while(head)
 {
  temp = head->link;
  delete head;
  head = temp;
 }
}
template<typename T,typename T1>
T1 * LinkList<T,T1> :: CreateNode()
{
 T1 *newNode = new T1;
 cout << "Enter the Value to be stored: ";
 cin >> newNode -> Val;
 newNode -> link = NULL;
 return newNode;
}
template<typename T,typename T1>
int LinkList<T,T1> :: GetData()
{
 char c;
 T1 *newNode = CreateNode();
 InsertAtFront(newNode);
 do
 {

  cout<<"Press Y to Continue or Press N to Stop ";
  cin >> c;
  if( c == 'Y'||c == 'y')
   {
    T1 *newNode = CreateNode();
    if(newNode == NULL )
     return 0;
    InsertAtLast(newNode);
   }
 }while( c == 'y'||c == 'Y');
 return 1;
}
template<typename T,typename T1>
int LinkList<T,T1> :: InsertAfterPosition(T1 *newNode, int pos)
{
 T1 *Current = head;
 int i=1;
 if(newNode==NULL)
  {
   return -1;
  }
 else
  {
   if(pos-1 ==0 || head == NULL )
     return InsertAtFront(newNode);
   else if(pos == Length+1)
     return InsertAtLast(newNode);
  else if(pos <=Length)
   {
    while( Current != NULL && i < pos-1 )
     {
      Current = Current -> link;
      i++;
     }
   newNode -> link = Current -> link;
   Current -> link = newNode;
   Length++;
   return 1;
    }
  else
    return 0;
  }
}
template<typename T,typename T1>
int LinkList<T,T1> :: InsertAtFront(T1 * newNode )
{
 if(newNode == NULL)
  return -1;
 else
 {
  if(head == NULL)
   {
    head = newNode;
    newNode -> link = NULL;
    Length++;
    return 1;
   }
  else
   {
    newNode -> link = head;
    head = newNode;
    Length++;
   }
   return 1;
 }
 return 0;
}
template<typename T,typename T1>
int LinkList<T,T1> :: InsertAtLast(T1 *newNode)
{
 if(newNode == NULL)
  return -1;
 else
  {
   T1 *Current = head;
     while(Current -> link !=NULL)
        Current = Current -> link;
     Current -> link = newNode;
     newNode -> link = NULL;
     Length++;
     return 1;
  }
  return 0;
}
template<typename T,typename T1>
int LinkList<T,T1> :: DeleteFirstNode()
{
 T1 * Current = head;
 head = head -> link;
 delete Current;
 Length--;
 return 1;
}
template<typename T,typename T1>
int LinkList<T,T1> :: DeleteByElement(T Val )
{
 T1 * Current;
 T1 *temp;
 Current = head;

 if(Current -> Val == Val )
  {
   return  DeleteFirstNode();

  }
 else
 {
  while ( Current -> link != NULL && Current -> link -> Val != Val )
   {
    Current == Current -> link;
   }
  if ( Current -> link != NULL )
   {
    temp = Current -> link;
    Current -> link = Current -> link -> link;
    delete temp;
    Length--;
    return 1;
   }
  else
    return 0;
 }
}
template<typename T,typename T1>
T1 * LinkList<T,T1> :: FindByElement(T Val)
{
 T1 *Current = head;
 while(Current -> link != NULL && Current -> Val != Val )
  {
     Current = Current -> link;
  }
  if(Current -> Val== Val)
   return Current;
  else
  return NULL ;
}
template<typename T,typename T1>
int LinkList<T,T1> :: FindByPosition(int Pos)
{
 T1 *Current =head;
 int Count =1;
 while(Current != NULL && Count < Pos)
  {
   Current = Current -> link;
   Count++;
  }
 if(Current)
  {
   PrintNode(Current);
   return 1;
  }
 else
  return 0;
}
template<typename T,typename T1>
void LinkList<T,T1> :: Print()
{
 T1 *Current = head;
 while(Current)
  {
   //cout<<"\nValue in Stack: "<< Current -> Val<<endl;
   PrintNode(Current);
   Current = Current -> link;
  }
  cout << "Length is "<<Length <<endl;
 }
template<typename T,typename T1>
void LinkList<T,T1> :: PrintNode(T1 *Current)
{
 cout<<"\nValue in Stack: "<< Current -> Val<<endl;
}

//Application
main()
{
 char nControl;
 int nCondition,nType;
 int nChoice,nPosition,nValue;
// LinkList *List;
 cout<<"\nInteger Stack....\n";
  /*cout<<"Enter the type for which you are going to so ADT:\n";
  cout<<"1)Integer.\n2)Float.\n3)Char.\n4)Long.\n5)Double.\n";
  cout<<"Your Choice: ";
  cin>>nType;
  switch(nType)
   {
    case 1: Node<int> node;
            LinkList<int,Node> LList;
            List = LList;
            break;
    case 2: Node<float> node;
            LinkList<float,Node> LList;
            List = LList;
            break;
    case 3: Node<char> node;
            LinkList<int,Node> LList;
            List = LList;
            break;
    case 4: Node<long> node;
            LinkList<int,Node> LList;
            List = LList;
            break;
    case 5: Node<double>;
            //List = LList;
            break;
    default: cout<<"Enter the option which is given in the list....\n";
   }*/
 Node<int> node;
 LinkList<int> List;
 Node<int> * Detail;
 if(List->GetData())
  {
    cout<< "Data is Inserted in the List..\n";
  }
 else
   cout<<"Data is Not Inserted Properly...\n";
 do
 {
   cout <<"\n1)Insert\n2)Delete\n3)Search By Student RollNo\n4)Search By Student Position\n5)Print\n6)Exit...\n";
   cout<<"Enter the Choice: ";
   cin>>nChoice;
   switch(nChoice)
    {
      case 1:
             node = List->CreateNode();
             cout << "Enter the Position to Insert : ";
             cin >> nPosition;
             nCondition= List.InsertAfterPosition(newNode,nPosition);
             if(nCondition==1)
              cout<<"Insertion Succes...\n";
             else
              cout<<"Insertion Is Failed...\n";
             List.Print();
             break;

      case 2: cout<< "Enter the Value to Delete the Data: ";
             cin>>nValue;
             nCondition=List.DeleteByElement(nValue);
             if(nCondition==1)
              cout << "Deletion is Success\n";
             else
              cout << "Delition is Failed\n";
              List.Print();
              break;
      case 3: cout<<"Enter the Value to search: ";
              cin>>nValue;
              Detail = List.FindByElement(nRollNo);
              if(Detail)
               {
                cout << "Details were Found........."<<endl;
                List.PrintNode(Detail);
               }
              else
               cout << " There is No Detail for the given Roll No...\n";
              break;
      case 4: cout<< "Enter the Position to find the Details of that Student: ";
              cin >> nPosition;
              nCondition = List.FindByPosition(nPosition);
              if(nCondition)
               {
                cout <<"Student Details was Printed\n";
               }
              else
               cout << "No Student is found in that Position...\n";
               break;
      case 5: cout<<"Student Details...\n";
               List.Print();
               break;
      case 6: cout<<"Thank You... :)\n";
               break;
     default : cout <<"Invalid Option.....\nTry Again...\n";
  }
 }while(nChoice!=6);

 //cout<<"\nPress Y to continue with other data type or Press N to Stop....\n";
 //cin>>nControl;
 }//while(nControl != 'n'|| nControl !='N');

