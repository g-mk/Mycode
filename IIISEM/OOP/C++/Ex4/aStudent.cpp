#include"hStudent.h"
main()
{
    int nCategory=0,nLevel=0,nStatus,nSeat;
    char cControl;
    cout<<"Enter the Total No. of Seats Available: ";
    cin>>nSeat;
    CStudent::AssignTotalSeat(nSeat);
    cout<<"Enter the Waiting List Available: ";
    cin>>nSeat; 
    CStudent::AssignWaitingList(nSeat);
    do
    {
        CStudent Stud;
        Stud.GetData();
        cout<<"\nEnter the Category in which You Belong....\n";
        cout<<"\n1.General Category...\n2.Sports Category...\n3.Physically Challenged Category...\n";
        cout<<"Category: ";
        cin>>nCategory;
        switch(nCategory)
        {
            case 1:
                nStatus = Stud.CalculateCutOff(nCategory);
                if(nStatus)
                cout<<"\nCutOff Calculated...\n";
                else
                cout<<"\nCutOff is Not Calculated Properly...\n";
            break;
            case 2: do
            {
                if(nLevel>5)
                    cout<<"\nThere is No Such Level...\n";
                cout<<"\nEnter the Level for which You have Played...\n";
                cout<<"1.Intra School Level...\n2.Inter School Level...\n"<<
                "3.District Level...\n4.State Level...\n5.National Level...\n";
                cout<<"Level:";
                cin>>nLevel;
            }while(nLevel>5);
            nStatus = Stud.CalculateCutOff(nCategory, nLevel);
            if(nStatus)
                cout<<"\nCutOff Calculated...\n";
            else
                cout<<"\nCutOff is Not Calculated Properly...\n";
            break;
            case 3: do
            {
                if(nLevel>5)
                    cout<<"\nThere is no such level in the list...\n";
                cout<<"\nEnter the Percentage of Disability...\n";
                cout<<"1.10=20\% Challenged...\n2.20-30\% Challenged...\n"<<
                      "3.30-50\% Challenged...\n4.50-60\% Challenged...\n"<<
                      "5.Above 60\% Challenged...\n";
                cout<<"Level:";
                cin>>nLevel;
            }while(nLevel>5);
            nStatus = Stud.CalculateCutOff(nCategory,nLevel);
            if(nStatus)
                cout<<"\nCutOff Calculated...\n";
            else
                cout<<"\nCutOff is Not Calculated Properly...\n";
            break;
            default: cout<<"\nNo Such Category Exists....\n";

        }
        nStatus = Stud.IsEligible();
        if(nStatus==1)
        {
            Stud.Display();
            cout<<"\nSeat is Alloted for the Student";
        }
        else if(nStatus==2)
        {
            Stud.Display();
            cout<<"\nStudent id in Waiting List...\n";
        }
        else if (nStatus == 0)
        {
            cout<<"\nSeat are Over to Allot...\n ";
        }
        else
        {
            Stud.Display();
            cout<<"\nThis Student is not Eligible to give the Seat...\n";
        }
        cout<<"\nPress 'Y' to Continue or Press 'N' to Stop: ";
        cin>>cControl;
    }while((cControl == 'Y'||cControl == 'y')&& (nStatus!=0));
      if(!nStatus)
       cout<<"\nSorry You Can't Continue Seats has been filled..\n";
      cout<<"\n*********************Thank You**********************\n";
    return 0;
}
