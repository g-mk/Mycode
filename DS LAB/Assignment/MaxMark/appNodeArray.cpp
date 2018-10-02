#include"hNodeArray.h"
main()
{
 int nCondition;
 int nChoice,nPosition,nRollNo;
 LinkList List;
 Node * Detail;
 if(List.GetData())
  {
    cout<< "Data is Inserted in the List..\n";
  }
 else
   cout<<"Data is Not Inserted Properly...\n";
 do
 {
   cout <<"\n1)Insert\n2)Delete\n3)Search By Student RollNo\n4)Search By Student Position\n5)Print\n6)Find Topper\n7)Exit...\n";
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
       case 6:
               Detail=List.FindMax();
               if(Detail)
               {
                   List.PrintNode(Detail);
               }
               else
                cout<<"List is Empty....\n";
                break;
       case 7: cout<<"Thank You... :)\n";
               break;
     default : cout <<"Invalid Option.....\nTry Again...\n";
  }
 }while(nChoice!=7);

}
