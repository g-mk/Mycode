#include"hSelfArray.h"
main()
{
    int nChoice,nStatus;
    Array arr;
    do
    {
    cout<<"Enter the Option\n1.Insert\n2.Find.\n3.Print.\n4.Exit.\nEnter Your Choice:";
    cin>>nChoice;
    switch(nChoice)
    {
    case 1:
        int nValue;
        cout<<"Enter the Value: ";
        cin>>nValue;
        int nStatus;
        nStatus = arr.InsertAtFirst(nValue);
        if(nStatus == 1)
        {
            cout<<"\n****************Element is Inserted**********\n";
        }
        else
        {
            cout<<"\n***************Element is Not Inserted*********\n";
        }
        break;
    case 2:
        int nKey;
        RetInfo rinfo;
        cout<<"Enter the Key To Find: ";
        cin>>nKey;
        rinfo=arr.Find(nKey);
        if(rinfo.nStatus==1)
        {
            cout<<"\n*******KEY FOUND**********\n";
            arr.DisplayInfo(rinfo.info);
        }
        else
        {
            cout<<"\n*******KEY NOT FOUND********\n";
        }
        break;
    case 3:
        nStatus=arr.Display();
        if(nStatus)
            cout<<"\n*******Elements are Displayed***********\n";
        else
            cout<<"\n***********ARRAY IS EMPTY***************\n";
        break;
    case 4:
        cout<<"\n***********THANK YOU**************\n";
        break;
    default:
        cout<<"No Such Option.......\n";
    }
    }while(nChoice!=4);
}
