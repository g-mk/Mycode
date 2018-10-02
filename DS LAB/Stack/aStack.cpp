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
                cout<<"Name :";
                cin>>info.Name;
                cout<<"Roll No: ";
                cin>>info.RollNo;
                cout<<"CutOff: ";
                cin>> info.CutOff;
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
                    cout<<"\nName : "<<rinfo.info.Name;
                    cout<<"\nRoll No : "<<rinfo.info.RollNo;
                    cout<<"\nCutOff: "<<rinfo.info.CutOff<<endl;
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
                    cout<<"\nName : "<<rinfo.info.Name;
                    cout<<"\nRoll No : "<<rinfo.info.RollNo;
                    cout<<"\nCutOff: "<<rinfo.info.CutOff<<endl;
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
