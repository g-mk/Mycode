#include"hBinary.h"
using namespace HistoryOfCommands;
Info GetInfo(FILE *fp)
{
    Info info;
    fscanf(fp,"%s",info.CommandName);
    fscanf(fp,"%s",info.CommandSyntax);
    fscanf(fp,"%s",info.CommandType);
    fscanf(fp,"%s",info.CommandDetails);
    return info;
}
void Display(Info info)
{
 cout<<"\nCommand Name : "<<info.CommandName;
 cout<<"\nSyntax: "<<info.CommandSyntax;
 cout<<"\nType: "<<info.CommandType;
 cout<<"\nDescription: "<<info.CommandDetails<<endl;
}

int stringCompare(Info info1,Info info2)
{
  return strcmp(info1.CommandName,info2.CommandName);
}

main()
{
 int Choice,Status;
 Info info;
 int Count;
 char *name;
 Node *NodeStatus;
 BST Tree;
 FILE *fp;
 FILE *fpDel;
 char sFile[10];
 int nFStatus;
 do
 {
     cout<<"Enter the File Name(.txt) for Input :";
     cin>>sFile;
     fp=fopen(sFile,"r+");
 }while(fp==NULL);
 fscanf(fp,"%d",&Count);
 for(int i=0;i<Count;i++)
 {
   nFStatus=feof(fp);
   if(nFStatus==0)
   {
    info = GetInfo(fp);
    Status=Tree.InsertBST(info,stringCompare);
   }
 }
 if(Status==1)
     cout<<"\n******Node Has been inserted Successfully*********\n";


 cout<<"\n\n****************Binary Search Tree****************\n";
 do
 {
 cout<<"\nEnter the Operation You are going to Perform:\n1)InsertBST.\n"
     <<"2)DeleteBST.\n3)SearchBST.\n4)Inorder.\n"
     <<"5)Preorder.\n6)Postorder.\n7)Exit.\n";
 cout<<"\nYour Option: ";
 cin>>Choice;
 switch(Choice)
 {
  case 1:
   nFStatus=feof(fp);
   if(nFStatus==0)
   {
   info = GetInfo(fp);
    Status=Tree.InsertBST(info,stringCompare);
    if(Status==1)
     cout<<"\n******Node Has been inserted Succesfully*********\n";
    else if (Status=-1)
        cout<<"Duplicate Element...\n";
    else
     cout<<"\n***********Node Has NOT been Inserted**************\n";
   }
   else
    cout<<"\n**************No Input Is Available*****************\n";
    break;
  case 2:
   if(!Tree.IsEmpty())
   {
   cout<<"\nCommand Name: ";
   cin>>info.CommandName;
   NodeStatus= Tree.DeleteBST(info,Tree.GetRoot(),stringCompare);
   if(NodeStatus)
   {
      cout<<"\n*************Node Has been Deleted*********\n";
   }
   else
    cout<<"\n*********Deletion Unsuccessful*************\n";
   }
   else
    cout<<"\n**********Tree is Empty******************\n";
   break;
  case 3:
   cout<<"Enter the name of the Command to search: ";
   cin>>info.CommandName;
   Status=Tree.SearchBST(Tree.GetRoot(),info,stringCompare);
   if(Status==1)
    cout<<"\n*******Node Found with the give Command*******\n";
   else if(Status==-1)
    cout<<"\n**************Node Not Found***********\n";
   else
    cout<<"\n*************Tree is Empty*************\n";
   break;
  case 4:
   if(!Tree.IsEmpty())
    {
     cout<<"\n************Inorder Travesal**********\n";
     Tree.Inorder(Tree.GetRoot(),Display);
    }
   else
    cout<<"\n*************Tree is Empty*************\n";
   break;
  case 5:
   if(!Tree.IsEmpty())
    {
     cout<<"\n************Preorder Travesal**********\n";
     Tree.Preorder(Tree.GetRoot(),Display);
    }
   else
    cout<<"\n*************Tree is Empty*************\n";
   break;
  case 6:
   if(!Tree.IsEmpty())
    {
     cout<<"\n************Postorder Travesal**********\n";
     Tree.Postorder(Tree.GetRoot(),Display);
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
 fclose(fp);
}
