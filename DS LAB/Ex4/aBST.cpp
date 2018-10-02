#include"hBST.h"
using namespace HistoryOfCommands;
main()
{
 int Choice,Status;
 Info info;
 char *name;
 Node *NodeStatus;
 BST Tree;
 cout<<"\n****************Binary Search Tree****************\n";
 do
 {
 cout<<"Enter the Operation You are going to Perform:\n1)InsertBST.\n"
     <<"2)DeleteBST.\n3)SearchBST.\n4)Inorder.\n"
     <<"5)Preorder.\n6)Postorder.\n7)Exit.";
 cout<<"\nYour Option: ";
 cin>>Choice;
 switch(Choice)
 {
  case 1:
   Node *newnode;
   newnode = Tree.CreateNode();
   if(newnode)
   {
    Status=Tree.InsertBST(newnode);
    if(Status==1)
     cout<<"\n******Node Has been inserted Succesfully*********\n";
    else if (Status=-1)
        cout<<"Duplicate Element...\n";
    else
     cout<<"\n***********Node Has NOT been Inserted**************\n";
   }
   else
    cout<<"\n************MEMORY ERROR**************\n";
    Tree.Display(Tree.root);
    break;
  case 2:
   //info = Tree.GetInfo();
   cout<<"Command Name: ";
   cin>>name;
   NodeStatus= Tree.DeleteBST(name,Tree.root);
   if(NodeStatus)
    cout<<"\n*************Node Has been Deleted*********\n";
   else if(NodeStatus!=NULL)
    cout<<"\n**********Tree is Empty******************\n";
   else
    cout<<"\n*********Deletion Unsuccessful*************\n";
   break;
  case 3:
   cout<<"Enter the name of the Command to search: ";
   cin>>name;
   Status=Tree.SearchBST(Tree.root,name);
   if(Status==1)
    cout<<"\n*******Node Found with the give Command*******\n";
   else if(Status==-1)
    cout<<"\n**************Node Not Found***********\n";
   else
    cout<<"\n*************Tree is Empty*************\n";
   break;
  case 4:
   if(Tree.IsEmpty())
    {
     cout<<"\n************Inorder Travesal**********\n";
     Tree.Inorder(Tree.root);
    }
   else
    cout<<"\n*************Tree is Empty*************\n";
   break;
  case 5:
   if(Tree.IsEmpty())
    {
     cout<<"\n************Preorder Travesal**********\n";
     Tree.Preorder(Tree.root);
    }
   else
    cout<<"\n*************Tree is Empty*************\n";
   break;
  case 6:
   if(Tree.IsEmpty())
    {
     cout<<"\n************Postorder Travesal**********\n";
     Tree.Postorder(Tree.root);
    }
   else
    cout<<"\n*************Tree is Empty*************\n";
   break;
  case 7:
   cout<<"\n******************Thank You*****************\n";
   break;
  default:
   cout<<"\n**********No Such Option***********\n";
  }
 }while(Choice!=7);
}
