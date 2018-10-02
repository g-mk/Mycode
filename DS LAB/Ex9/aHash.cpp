#include"hHash.h"
void dispInfo(Info info)
{
 cout<<"\nCommand Name : "<<info.CommandName;
 cout<<"\nSyntax: "<<info.CommandSyntax;
 cout<<"\nType: "<<info.CommandType;
 cout<<"\nDescription: "<<info.CommandDetails<<endl;
}

int stringCompare(Info info1,Info info2)
{
  if(strcmp(info1.CommandName,info2.CommandName)==0)
    return 1;
  else
    return 0;
}

Info GetInfo()
{
  Info info;
 cout<<"\nCommand Name: ";
 cin>>info.CommandName;
 cout<<"\nCommand Syntax: ";
 cin>>info.CommandSyntax;
 cout<<"\nCommand Type: ";
 cin>>info.CommandType;
 cout<<"\nCommand Description: ";
 cin>>info.CommandDetails;
 return(info);
}

main()
{
    int nCount;
    int nControl,nStatus;
    Info info;
    Node *retNode;
    cout<<"Enter the No. of Bucket:";
    cin>>nCount;
    HashTable hashtable(nCount);
    do
    {
        cout<<"\nEnter the Choice:\n1.Insert.\n2.Find.\n3.Display.\n4.Exit.\nOption:";
        cin>>nControl;
        switch(nControl)
        {
        case 1:
            cout<<"\nEnter the Command Details\n";
            info = GetInfo();
            nStatus=hashtable.insert(info);
            if(nStatus==1)
                {
                    cout<<"\nInfo is Inserted in the Hash Table\n";
                }
            else
                cout<<"\nInfo is not Inserted in the Hash Table\n";
            break;
        case 2:
            cout<<"\nEnter the name of the Command: ";
            cin>>info.CommandName;
            retNode=hashtable.find(info,stringCompare);
            if(retNode)
                {
                    cout<<"\n\n****************Node Found******************\n\n";
                }
            else
                cout<<"\n\nNode with the Give Command Name not Found\n\n";
            break;
        case 3:
            cout<<"\nContent in the Hash Table:\n";
            hashtable.displayTable(dispInfo);
            break;
        case 4:
            cout<<"\n********************Thank You******************\n";
            break;
        default:
            cout<<"\nInvalid Option\n";
        }
    }while(nControl!=4);
}
