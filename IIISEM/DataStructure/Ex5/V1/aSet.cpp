#include"hSet.h"
using namespace HistoryOfCommands;
main()
{
 SET aTree,bTree,cTree;
 int nStatus,nChoice;
 char cControl;
 Info info;
 cout<<"\n*****************SET OPERATIONS****************\n";
 cout<<"\nGive inputs for SET A: \n";
 do
  {
   cout<<"\nElements in Tree A : \n";
   Node *newNode;
   newNode = aTree.CreateNode();
   if(newNode)
   {
    nStatus = aTree.InsertSET(newNode);
    if(nStatus==1)
    {
     cout<<"\n******Node Has been inserted Succesfully*********\n";
    }
    else if (nStatus=-1)
        cout<<"Duplicate Element...\n";
    else
     cout<<"\n***********Node Has NOT been Inserted**************\n";
   }
   else
    cout<<"\n************MEMORY ERROR**************\n";
  cout<<"Press Y to CONTINUE or Press N to STOP: ";
  cin>>cControl;
  }while(cControl == 'Y' || cControl == 'y');
 aTree.Inorder(aTree.GetRoot());
 
 cout<<"\nGive inputs for SET B: \n";
 do
  {
   cout<<"\nElements in Tree B : \n";
   Node *newNode;
   newNode = bTree.CreateNode();
   if(newNode)
   {
    nStatus = bTree.InsertSET(newNode);
    if(nStatus==1)
     {
       cout<<"\n******Node Has been inserted Succesfully*********\n";
     }
    else if (nStatus=-1)
        cout<<"Duplicate Element...\n";
    else
     cout<<"\n***********Node Has NOT been Inserted**************\n";
   }
   else
    cout<<"\n************MEMORY ERROR**************\n";
  cout<<"Press Y to CONTINUE or Press N to STOP: ";
  cin>>cControl;
  }while(cControl == 'Y' || cControl == 'y');
 bTree.Preorder(bTree.GetRoot());
 cout<<"\n*****************Union Operation************\n";
 do
 {
  cout<<"1.To Perform Union Operation.\n2.Search in Union Tree.\n"
       <<"3.Inorder Traversal.\n4.PreorderTraversal.\n5.PostOrder.\n6.Exit.\n";
  cin>>nChoice;
 switch(nChoice)
 {
  case 1:
    if(!cTree.GetRoot())
    {
     cTree.Union(aTree.GetRoot());
     cTree.Union(bTree.GetRoot());
     cout<<"\n*************Union Operation Done***********\n";
    }
    else if(cTree.GetRoot()==NULL)
     cout<<"\n*************Union Operation Unsuccesfull*********\n";
    else
     cout<<"\n***Union Operation Alredy Done Continue with Some Other Operations****\n";
    break;
  case 2:
    if(cTree.GetRoot())
    {
     cout<<"Name of the Command to search: ";
     cin>>info.CommandName;
     nStatus=cTree.SearchSET(cTree.GetRoot(),info.CommandName);
     if(nStatus==1)
      cout<<"\n*******Node Found with the give Command*******\n";
     else if(nStatus==-1)
      cout<<"\n**************Node Not Found***********\n";
     else
      cout<<"\n*************Tree is Empty*************\n";
    }
    else
      cout<<"\n*********Union is Not Performed*********\n";
     break;
  case 3:
   if(!cTree.IsEmpty())
    {
     cout<<"\n************Inorder Travesal**********\n";
     cTree.Inorder(cTree.GetRoot());
    }
   else
    cout<<"\n*************Tree is Empty*************\n";
   break;
  case 4:
   if(!cTree.IsEmpty())
    {
     cout<<"\n************Preorder Travesal**********\n";
     cTree.Preorder(cTree.GetRoot());
    }
   else
    cout<<"\n*************Tree is Empty*************\n";
   break;
  case 5:
   if(!cTree.IsEmpty())
    {
     cout<<"\n************Postorder Travesal**********\n";
     cTree.Postorder(cTree.GetRoot());
    }
   else
    cout<<"\n*************Tree is Empty*************\n";
   break;
  case 6:
   cout<<"\n******************Thank You*****************\n";
   break;
  default:
   cout<<"\n************Invalid Option****************\n";
  }
 }while(nChoice!=6);
}



