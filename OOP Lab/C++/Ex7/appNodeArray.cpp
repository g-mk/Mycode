#include"hNodeArray.h"
main()
{
 char nControl;
 int nCondition,nType;
 int nChoice,nPosition,nRollNo;
 LinkList &List;
 do
 {
  cout<<"Enter the type for which you are going to so ADT:\n";
  cout<<"1)Integer.\n2)Float.\n3)Char.\n4)Long.\n5)Double.\n";
  cout<<"Your Choice: ":
  cin>>nType;
  switch(nType)
   {
    case 1: LinkList<int> LList;
            List = LList;
            break;
    case 2: LinkList<float> LList;
            List = LList;
            break;
    case 3: LinkList<char> LList;
            List = LList;
            break;
    case 4: LinkList<long> LList;
            List = LList;
            break;
    case 5: LinkList<double> LList;
            List = LList;
            break;
    default: cout<<"Enter the option which is given in the list....\n";
   }

 Node * Detail;
 if(List.GetData())
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
      case 1: Node *newNode;
             newNode = List.CreateNode();
             cout << "Enter the Position to Insert : ";
             cin >> nPosition;
             nCondition= List.InsertAfterPosition(newNode,nPosition);
             if(nCondition==1)
              cout<<"Insertion Succes...\n";
             else
              cout<<"Insertion Is Failed...\n";
             List.Print();
             break;
  
      case 2: cout<< "Enter the Roll No. to Delete the Student Details: ";
             cin>>nRollNo;
             nCondition=List.DeleteByElement(nRollNo);
             if(nCondition==1)
              cout << "Deletion is Success\n";
             else 
              cout << "Delition is Failed\n";
              List.Print(); 
              break;
      case 3: cout<<"Enter the Student Roll No to search: ";
              cin>>nRollNo;
              Detail = List.FindByElement(nRollNo); 
              if(Detail)
               {
                cout << "Details were Found for the Give Roll No: "<<nRollNo<<endl;
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
 
 cout<<"\nPress Y to continue with other data type or Press N to Stop....\n";
 cin>>nControl;
 }while(nControl != 'n'|| nControl !='N');
} 
