#include<iostream>
using namespace std;

template <typename X>
class Node
{
 template<typename T>
 friend class LinkList;
  private:
          X Val;
          Node *link;
};

template<typename T>
class LinkList
{
 public:
        LinkList();
        ~LinkList();
        Node<T> * CreateNode();
        int InsertAfterPosition(Node<T> *newNode, int nPos);
        int InsertAtFront(Node<T> *newNode);
        int InsertAtLast(Node<T> *newNode);
        int DeleteByElement(T Val);
        int DeleteFirstNode();
        Node<T> * FindByElement (T Val);
        int FindByPosition(int nPos);
        int Print();
        void PrintNode(Node<T> *);
        int GetData();
 private:
        Node<T> *head;
        int Length;
};
//Implementation....
template<typename T>

LinkList<T> :: LinkList()
{
 head = NULL;
 Length=0;
}
template<typename T>

LinkList<T> :: ~LinkList()
{
 Node<T> *temp;
 temp = head;
 while(head)
 {
  temp = head->link;
  delete head;
  head = temp;
 }
}

template<typename T>

Node<T> * LinkList<T> :: CreateNode()
{
 Node<T> *newNode = new Node<T>;
 cout << "\nEnter the Value to be stored: ";
 cin >> newNode -> Val;
 newNode -> link = NULL;
 return newNode;
}

template<typename T>

int LinkList<T> :: GetData()
{
 char c;
 Node<T> *newNode = CreateNode();
 InsertAtFront(newNode);
 do
 {

  cout<<"\nPress Y to Continue or Press N to Stop ";
  cin >> c;
  if( c == 'Y'||c == 'y')
   {
    Node<T> *newNode = CreateNode();
    if(newNode == NULL )
     return 0;
    InsertAtLast(newNode);
   }
 }while( c == 'y'||c == 'Y');
 return 1;
}

template<typename T>

int LinkList<T> :: InsertAfterPosition(Node<T> *newNode, int nPos)
{
 Node<T> *Current = head;
 int i=1;
 if(newNode==NULL)
  {
   return -1;
  }
 else
  {
   if(nPos-1 ==0 || head == NULL )
     return InsertAtFront(newNode);
   else if(nPos == Length+1)
     return InsertAtLast(newNode);
  else if(nPos <=Length)
   {
    while( Current != NULL && i < nPos-1 )
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

template<typename T>

int LinkList<T> :: InsertAtFront(Node<T> * newNode )
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

template<typename T>

int LinkList<T> :: InsertAtLast(Node<T> *newNode)
{
 if(newNode == NULL)
  return -1;
 else
  {
   Node<T> *Current = head;
     while(Current -> link !=NULL)
        Current = Current -> link;
     Current -> link = newNode;
     newNode -> link = NULL;
     Length++;
     return 1;
  }
  return 0;
}

template<typename T>

int LinkList<T> :: DeleteFirstNode()
{
 Node<T> * Current = head;
 head = head -> link;
 delete Current;
 Length--;
 return 1;
}

template<typename T>

int LinkList<T> :: DeleteByElement(T Val )
{
 Node<T> * Current;
 Node<T> *temp;
 Current = head;
 if(!head)
  return 0;
 else
 {
  if(Current -> Val == Val )
  {
   return  DeleteFirstNode();

  }
 else
 {
  while ( Current -> link != NULL && Current -> link -> Val != Val )
   {
    Current = Current -> link;
   }
  if ( Current -> link != NULL)
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
}

template<typename T>

Node<T>* LinkList<T> :: FindByElement(T Val)
{
 if(!head)
   return 0;
 else
 {
 Node<T> *Current = head;
 while(Current -> link != NULL && Current -> Val != Val )
  {
     Current = Current -> link;
  }
  if(Current -> Val== Val)
   return Current;
  else
  return NULL ;
 }
}

template<typename T>

int LinkList<T> :: FindByPosition(int nPos)
{
 if(!head)
  return 0;
 else
 {
 Node<T> *Current =head;
 int Count =1;
 while(Current != NULL && Count < nPos)
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
}

template<typename T>

int LinkList<T> :: Print()
{
 Node<T> *Current = head;
 if(!Current)
  return 0;
 cout<<"\nDetails in the List\n";
 while(Current)
  {
   PrintNode(Current);
   Current = Current -> link;
  }
  cout << "\nLength is "<<Length <<endl;
  return 1;
 }

template<typename T>

void LinkList<T> :: PrintNode(Node<T> *Current)
{
 cout<<Current -> Val<<"-> ";
}

//Application
main()
{
 char nControl,cValue;
 int nCondition,nType;
 int nChoice,nPosition,nValue;
 Node<int> * Detail;
 Node<int> * pNewnode;
 LinkList<int> List;
 Node<float> * fDetail;
 Node<float> * pfNewnode;
 LinkList<float> fList;
 Node<char> * cDetail;
 Node<char> * pcNewnode;
 LinkList<char> cList;
 Node<long> * lDetail;
 Node<long> * plNewnode;
 LinkList<long> lList;
 do
 {
  cout<<"Enter the type for which you are going to so ADT:\n";
  cout<<"1)Integer.\n2)Float.\n3)Char.\n4)Long.\n";
  cout<<"Your Choice: ";
  cin>>nType;
  switch(nType)
   {
    case 1:
        cout<<"\n********************Integer List****************\n";

        if(List.GetData())
            {
                cout<< "\nData is Inserted in the List..\n";
            }
        else
                cout<<"\nData is Not Inserted Properly...\n";
        do
        {
            cout <<"\n1)Insert\n2)Delete\n3)Search By Value\n4)Retrive Value at Position\n5)Print\n6)Exit...\n";
            cout<<"Enter the Choice: ";
            cin>>nChoice;
            switch(nChoice)
            {
                case 1:
                    pNewnode = List.CreateNode();
                    cout << "Enter the Position to Insert : ";
                    cin >> nPosition;
                    nCondition= List.InsertAfterPosition(pNewnode,nPosition);
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
                        cout << "Deletion is Failed\n";
                    List.Print();
                    break;
                case 3: cout<<"Enter the Value to search: ";
                    cin>>nValue;
                    Detail = List.FindByElement(nValue);
                    if(Detail)
                    {
                        cout << "Details were Found........."<<endl;
                        List.PrintNode(Detail);
                    }
                    else
                        cout << " There is No Detail for the given Value...\n";
                    break;
                case 4: cout<< "Enter the Position to find the Value: ";
                    cin >> nPosition;
                    nCondition = List.FindByPosition(nPosition);
                    if(nCondition)
                    {
                        cout <<"Values at Position was Printed\n";
                    }
                    else
                        cout << "No Value is found in that Position...\n";
                    break;
                case 5: 
                    nCondition=List.Print();
                  if(nCondition == 0)
                   cout<<"\nList Is Empty\n";
                  break;

                case 6: cout<<"Thank You... :)\n";
                    break;
                default : cout <<"Invalid Option.....\nTry Again...\n";
            }
        }while(nChoice!=6);
            break;
    case 2:
        cout<<"\n********************Float List****************\n";

        if(fList.GetData())
        {
            cout<< "\nData is Inserted in the List..\n";
        }
        else
            cout<<"\nData is Not Inserted Properly...\n";
        do
        {
            cout <<"\n1)Insert\n2)Delete\n3)Search By Value\n4)Retrive Value at Position\n5)Print\n6)Exit...\n";
            cout<<"Enter the Choice: ";
            cin>>nChoice;
            switch(nChoice)
            {
            case 1:
                pfNewnode = fList.CreateNode();
                cout << "Enter the Position to Insert : ";
                cin >> nPosition;
                nCondition= fList.InsertAfterPosition(pfNewnode,nPosition);
                if(nCondition==1)
                    cout<<"Insertion Succes...\n";
                else
                    cout<<"Insertion Is Failed...\n";
                fList.Print();
                break;

            case 2:
                cout<< "Enter the Value to Delete the Data: ";
                cin>>nValue;
                nCondition=fList.DeleteByElement(nValue);
                if(nCondition==1)
                    cout << "Deletion is Success\n";
                else
                    cout << "Delition is Failed\n";
                fList.Print();
                break;
            case 3: cout<<"Enter the Value to search: ";
                cin>>nValue;
                fDetail = fList.FindByElement(nValue);
                if(fDetail)
                {
                    cout << "Details were Found........."<<endl;
                    fList.PrintNode(fDetail);
                }
                else
                    cout << " There is No Detail for the given Value...\n";
                break;
            case 4: cout<< "Enter the Position to find the Value: ";
                cin >> nPosition;
                nCondition = fList.FindByPosition(nPosition);
                if(nCondition)
                {
                    cout <<"Values at Position was Printed\n";
                }
                else
                    cout << "No Value is found in that Position...\n";
                break;
            case 5: 
                nCondition=fList.Print();
               if(nCondition == 0)
                cout<<"\nList Is Empty\n";
               break;

            case 6: cout<<"Thank You... :)\n";
                break;
            default : cout <<"Invalid Option.....\nTry Again...\n";
            }
        }while(nChoice!=6);
        break;
    case 3:
        cout<<"\n********************Character Type List****************\n";

        if(cList.GetData())
        {
            cout<< "\nData is Inserted in the List..\n";
        }
        else
            cout<<"\nData is Not Inserted Properly...\n";
        do
        {
            cout <<"\n1)Insert\n2)Delete\n3)Search By Value\n4)Retrive Value at Position\n5)Print\n6)Exit...\n";
            cout<<"Enter the Choice: ";
            cin>>nChoice;
            switch(nChoice)
            {
            case 1:
                pcNewnode = cList.CreateNode();
                cout << "Enter the Position to Insert : ";
                cin >> nPosition;
                nCondition= cList.InsertAfterPosition(pcNewnode,nPosition);
                if(nCondition==1)
                    cout<<"Insertion Succes...\n";
                else
                    cout<<"Insertion Is Failed...\n";
                cList.Print();
                break;

            case 2:
                cout<< "Enter the Value to Delete the Data: ";
                cin>>cValue;
                nCondition=cList.DeleteByElement(cValue);
                if(nCondition==1)
                    cout << "Deletion is Success\n";
                else
                    cout << "Delition is Failed\n";
                cList.Print();
                break;
            case 3: cout<<"Enter the Value to search: ";
                cin>>cValue;
                cDetail = cList.FindByElement(cValue);
                if(cDetail)
                {
                    cout << "Details were Found........."<<endl;
                    cList.PrintNode(cDetail);
                }
                else
                    cout << " There is No Detail for the given Value...\n";
                break;
            case 4: cout<< "Enter the Position to find the Value: ";
                cin >> nPosition;
                nCondition = cList.FindByPosition(nPosition);
                if(nCondition)
                {
                    cout <<"Values at Position was Printed\n";
                }
                else
                    cout << "No Value is found in that Position...\n";
                break;
            case 5:
                nCondition=cList.Print();
                if(nCondition == 0)
                 cout<<"\nList Is Empty\n";
                break;

            case 6: cout<<"Thank You... :)\n";
                break;
            default : cout <<"Invalid Option.....\nTry Again...\n";
            }
        }while(nChoice!=6);
        break;
    case 4:
        cout<<"\n********************Long Type List****************\n";

        if(lList.GetData())
        {
            cout<< "\nData is Inserted in the List..\n";
        }
        else
            cout<<"\nData is Not Inserted Properly...\n";
        do
        {
            cout <<"\n1)Insert\n2)Delete\n3)Search By Value\n4)Retrive Value at Position\n5)Print\n6)Exit...\n";
            cout<<"Enter the Choice: ";
            cin>>nChoice;
            switch(nChoice)
            {
            case 1:
                plNewnode = lList.CreateNode();
                cout << "Enter the Position to Insert : ";
                cin >> nPosition;
                nCondition= lList.InsertAfterPosition(plNewnode,nPosition);
                if(nCondition==1)
                    cout<<"Insertion Succes...\n";
                else
                    cout<<"Insertion Is Failed...\n";
                lList.Print();
                break;

            case 2:
                cout<< "Enter the Value to Delete the Data: ";
                cin>>nValue;
                nCondition=lList.DeleteByElement(nValue);
                if(nCondition==1)
                    cout << "Deletion is Success\n";
                else
                    cout << "Delition is Failed\n";
                lList.Print();
                break;
            case 3: cout<<"Enter the Value to search: ";
                cin>>nValue;
                lDetail = lList.FindByElement(nValue);
                if(lDetail)
                {
                    cout << "Details were Found........."<<endl;
                    lList.PrintNode(lDetail);
                }
                else
                    cout << " There is No Detail for the given Value...\n";
                break;
            case 4: cout<< "Enter the Position to find the Value: ";
                cin >> nPosition;
                nCondition = lList.FindByPosition(nPosition);
                if(nCondition)
                {
                    cout <<"Values at Position was Printed\n";
                }
                else
                    cout << "No Value is found in that Position...\n";
                break;
            case 5:
                nCondition=lList.Print();
                if(nCondition == 0)
                 cout<<"\nList Is Empty\n";
                break;

            case 6: cout<<"Thank You... :)\n";
                break;
            default : cout <<"Invalid Option.....\nTry Again...\n";
            }
        }while(nChoice!=6);
        break;
    default: cout<<"Enter the option which is given in the list....\n";
   }
 cout<<"\nPress Y to continue with other data type or Press N to Stop....\n";
 cin>>nControl;
 }while(nControl == 'y'|| nControl =='Y');
}
