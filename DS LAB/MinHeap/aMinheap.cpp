#include"hMinheap.h"

void display(Info info)
{
 cout<<"\nCommand Name : "<<info.CommandName;
 cout<<"\nSyntax: "<<info.CommandSyntax;
 cout<<"\nType: "<<info.CommandType;
 cout<<"\nDescription: "<<info.CommandDetails<<endl;
}

Info GetInfo(FILE *fp)
{
    Info info;
    fscanf(fp,"%s",info.CommandName);
    fscanf(fp,"%s",info.CommandSyntax);
    fscanf(fp,"%s",info.CommandType);
    fscanf(fp,"%s",info.CommandDetails);
    return info;
}

int main()
{
    FILE *fp;
    int nCapacity;
    int nStatus;
    int nFStatus;
    int nControl;
    Info info;
    char sFile[10];
    cout<<"Enter the Input File name(*.txt): ";
    cin >> sFile;
    cout<<"Enter the Heap Capacity: ";
    cin>> nCapacity;
    MinHeap heap(nCapacity);
    fp=fopen(sFile,"r");

    do
    {
        cout<<"\nEnter the Choice:\n1.Insert.\n2.Delete\n3.Display.\n4.Exit.\nOption:";
        cin>>nControl;
        if(fp==NULL)
        {
            cout<<"\n***************Error Opening in File***********\n";
            break;
        }
        switch(nControl)
        {
        case 1:
            nFStatus=feof(fp);
            if(nFStatus==0)
                {
                    info=GetInfo(fp);
                    nStatus=heap.Insert(info);
                    if(nStatus==1)
                        cout<<"\n***********Element Inserted************\n\n";
                    else
                        cout<<"\n***********Heap is Full**********\n";
                }
            else
            {
                cout<<"\n***********No Input is Available in the File**********\n";
                break;
            }
            break;
        case 2:
            nStatus=heap.Delete();
            if(nStatus==1)
                cout<<"\n*************Deletion Success*************\n\n";
            else
                cout<<"\n*************Heap is Empty*********\n\n";
            break;
        case 3:
            nStatus=heap.Display(display);
            if(nStatus!=1)
                cout<<"\n*************Heap is Empty***********\n\n";
            break;
        case 4:
            cout<<"\n************Thank You******************\n\n";
            break;
        default:
            cout<<"\n****************No Such Option***************\n";
        }
    }while(nControl!=4);
}
