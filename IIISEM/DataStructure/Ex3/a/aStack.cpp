#include"hStack.h"

main()
{
    Stack CStack;
    int nStatus;
    int nChoice;
    Info info;
    RetInfo rinfo;
    do
    {
        cout<<"\nEnter the Choice:\n";
        cout<<"1.Push in Stack\n2.Pop out the Stack\n3.Retrive Top\n4.Exit..\nEnter the Choice :";
        cin>>nChoice;
        switch(nChoice)
        {
            case 1:
                cout<<"\nCommand Name: ";
                cin>>info.CommandName;
                cout<<"\nCommand Syntax: ";
                cin>>info.CommandSyntax;
                cout<<"\nCommand Type: ";
                cin>>info.CommandType;
                cout<<"\nCommand Description: ";
                cin>>info.CommandDetails;
                nStatus=CStack.Push(info);
                if(nStatus==1)
                    cout<<"\n*********Object is Pushed********\n";
                else
                    cout<<"\n*****Object is not pushed ********\n";
                break;
            case 2:
                rinfo=CStack.Pop();
                if(rinfo.status==1)
                {
                    cout<<"\nCommand Name : "<<rinfo.info.CommandName;
                    cout<<"\nSyntax: "<<rinfo.info.CommandSyntax;
                    cout<<"\nType: "<<rinfo.info.CommandType;
                    cout<<"\nDescription: "<<rinfo.info.CommandDetails<<endl;
                }
                else
                {
                    cout<<"\n*********Stack is Empty*********\n";
                }
                break;
            case 3:
                rinfo=CStack.ReturnTop();
                if(rinfo.status==1)
                {
                   cout<<"\nCommand Name : "<<rinfo.info.CommandName;
                   cout<<"\nSyntax: "<<rinfo.info.CommandSyntax;
                   cout<<"\nType: "<<rinfo.info.CommandType;
                   cout<<"\nDescription: "<<rinfo.info.CommandDetails<<endl;
                }
                else
                {
                    cout<<"\n*********Stack is Empty*********\n";
                }
                break;
            case 4:
                cout<<"\n***********Thank You************\n";

        }
    }while(nChoice !=4);
}
