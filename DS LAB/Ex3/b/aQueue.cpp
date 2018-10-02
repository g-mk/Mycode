#include"hQueue.h"

main()
{
    Queue CQueue;
    int nStatus;
    int nChoice;
    Info info;
    RetInfo rinfo;
    do
    {
        cout<<"\nEnter the Choice:\n";
        cout<<"1.Enqueue..\n2.Dequeue\n3.Display Queue..\n4.Retrive Front\n5.Retrive Last.\n6.Exit..\nEnter the Choice :";
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
                nStatus=CQueue.EnQueue(info);
                if(nStatus==1)
                    cout<<"\n*********Object is Queued********\n";
                else
                    cout<<"\n*****Object is not Queued ********\n";
                break;
            case 2:
                rinfo=CQueue.DeQueue();
                if(rinfo.status==1)
                {
                    cout<<"\nCommand Name : "<<rinfo.info.CommandName;
                    cout<<"\nSyntax: "<<rinfo.info.CommandSyntax;
                    cout<<"\nType: "<<rinfo.info.CommandType;
                    cout<<"\nDescription: "<<rinfo.info.CommandDetails<<endl;
                }
                else
                {
                    cout<<"\n*********Queue is Empty*********\n";
                }
                break;
            case 3:
                if(CQueue.IsEmpty())
                  {
                    cout<< "\n*************Queue is Empty**********\n";
                  }
                else 
                 {
                    cout<<"\n***************List in Queue*************\n";
                    CQueue.Display();
                 }
                 break;
            case 4:
                rinfo=CQueue.ReturnFront();
                if(rinfo.status==1)
                {
                    cout<<"\nCommand Name : "<<rinfo.info.CommandName;
                    cout<<"\nSyntax: "<<rinfo.info.CommandSyntax;
                    cout<<"\nType: "<<rinfo.info.CommandType;
                    cout<<"\nDescription: "<<rinfo.info.CommandDetails<<endl;
                }
                else
                {
                    cout<<"\n*********Queue is Empty*********\n";
                }
                break;
            case 5:
                rinfo=CQueue.ReturnRear();
                if(rinfo.status==1)
                {
                    cout<<"\nCommand Name : "<<rinfo.info.CommandName;
                    cout<<"\nSyntax: "<<rinfo.info.CommandSyntax;
                    cout<<"\nType: "<<rinfo.info.CommandType;
                    cout<<"\nDescription: "<<rinfo.info.CommandDetails<<endl;
                }
                else
                {
                    cout<<"\n*********Queue is Empty*********\n";
                }
                break;

            case 6:
                cout<<"\n***********Thank You************\n";

        }
    }while(nChoice !=6);
}
