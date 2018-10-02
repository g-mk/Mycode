#include"hSet.h"
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

int stringCompare(Info info,Info cinfo)
{
  return(strcmp(info.CommandName,cinfo.CommandName));
}

int main()
{
 SET aTree,bTree,cTree;
 int nStatus,nChoice,nFStatus;
 char cControl;
 char sFile[10];
 Info info;
 FILE *fp;
 cout<<"Enter the File Name(.txt) :";
 cin>>sFile;
 fp=fopen(sFile,"r+");
 cout<<"\n*****************SET OPERATIONS****************\n";
 cout<<"\nSET A Inputs: \n";
 do
  {
   nFStatus=feof(fp);
   if(nFStatus==0)
   {
   info = GetInfo(fp);
    nStatus = aTree.InsertSET(info,stringCompare);
    if(nStatus==1)
    {
     cout<<"\n******Node Has been inserted Succesfully*********\n\n";
    }
    else if (nStatus==-1)
        cout<<"Duplicate Element...\n";
    else
     cout<<"\n***********Node Has NOT been Inserted**************\n";
   }
   else
   {
    cout<<"\n*************No Input is Available in the File*********\n";
    break;
   }
  cout<<"\nPress Y to CONTINUE or Press N to STOP: ";
  cin>>cControl;
  }while(cControl == 'Y' || cControl == 'y');
 cout<<"\nElements in Tree A : \n";
 aTree.Inorder(aTree.GetRoot(),Display);

 cout<<"\nSET B Inputs: \n";
 do
  {
   nFStatus=feof(fp);
   if(nFStatus==0)
   {
   info = GetInfo(fp);
   nStatus = bTree.InsertSET(info,stringCompare);
   if(nStatus==1)
    {
      cout<<"\n******Node Has been inserted Succesfully*********\n\n";
    }
   else if (nStatus==-1)
       cout<<"Duplicate Element...\n";
   else
    cout<<"\n***********Node Has NOT been Inserted**************\n";
   }
   else
   {
    cout<<"\n*************No Input is Available in the File*********\n";
    break;
   }
  cout<<"\nPress Y to CONTINUE or Press N to STOP: ";
  cin>>cControl;
  }while(cControl == 'Y' || cControl == 'y');
 cout<<"\nElements in Tree B : \n";
 bTree.Preorder(bTree.GetRoot(),Display);
 cout<<"\n*****************Union Operation************\n";
 do
 {
  cout<<"\n1.To Perform Union Operation.\n2.Search in Union Tree.\n"
       <<"3.Inorder Traversal.\n4.PreorderTraversal.\n5.PostOrder.\n6.Exit.\n";
  cin>>nChoice;
 switch(nChoice)
 {
  case 1:
    if(!cTree.GetRoot())
    {
     cTree.Union(aTree.GetRoot(),stringCompare);
     cTree.Union(bTree.GetRoot(),stringCompare);
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
     nStatus=cTree.SearchSET(cTree.GetRoot(),info,stringCompare);
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
     cTree.Inorder(cTree.GetRoot(),Display);
    }
   else
    cout<<"\n*************Tree is Empty*************\n";
   break;
  case 4:
   if(!cTree.IsEmpty())
    {
     cout<<"\n************Preorder Travesal**********\n";
     cTree.Preorder(cTree.GetRoot(),Display);
    }
   else
    cout<<"\n*************Tree is Empty*************\n";
   break;
  case 5:
   if(!cTree.IsEmpty())
    {
     cout<<"\n************Postorder Travesal**********\n";
     cTree.Postorder(cTree.GetRoot(),Display);
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
