#include"hStudent.h"
main()
{
 std :: locale loc;
 int nLevel,nCategory;
 int nCount=1000;
 char cControl='y';
 float fTotalCutoff;
 cout << "Cutoff Calculataion of the Student...\n";
 do
  {
   struct SStudent Candidate;
   cout<<"Name of the Candidate:";
   cin>>Candidate.m_sName;
   
   cout<<"Addmission No. is ";
   Candidate.m_nAddmissionNo = ++nCount;
   cout<<Candidate.m_nAddmissionNo<<endl;
   
   cout<<"Enter the Maths Mark:";
   cin>>Candidate.m_fMarks[0];
   
   cout<<"Enter the Physics Mark:";
   cin>>Candidate.m_fMarks[1];
   
   cout<<"Enter the Chemistry Mark:";
   cin>>Candidate.m_fMarks[2];
   
   cout<<"Enter the Campus Entrance Mark:";
   cin>>Candidate.m_fMarks[3];
   
   cout<<"\nEnter the Category to which you belong:\n";
   cout<<"1.General Category\n2.Sports Category\n3.Physically Challenged\n";
   cout<<"Category:";
   cin>>nCategory;
   switch(nCategory)
    { 
     case 1: fTotalCutoff=CalculateCutoff(Candidate,nCategory);
             cout<<"\nCutoff Of the Student "<<Candidate.m_sName<<" is "<<fTotalCutoff<<endl;
             break;
     case 2: cout<<"\nEnter the Level for which you have played.."<<endl;
             cout<<"1.Intra School Level"<<endl<<"2.Inter School Level"<<endl
                 <<"3.District Level"<<endl<<"4.State Level"<<endl
                 <<"5.National Level\n"<<"Level:"<<endl;
             cin>>nLevel;
             fTotalCutoff = CalculateCutoff(Candidate, nCategory, nLevel);
             cout<<"Cutoff Of the Student "<<Candidate.m_sName<<" is "<<fTotalCutoff<<endl;
             break;
    case 3: cout<<"\n1.10%-20\%Challenged"<<endl<<"2.20-40\% Challenged"<<endl<<"3.40-50\% Challenged"<<endl
                <<"4.50-60\% Challenged"<<endl
                <<"5.above 60\%Challenged"<<endl;
            cout<<"\nEnter the Physically Challenged Level:";
            cin>> nLevel;
            fTotalCutoff=CalculateCutoff(Candidate, nCategory, nLevel);
            cout<<"\nCutoff Of the Student "<<Candidate.m_sName<<" is "<<fTotalCutoff<<endl;
            break; 
   default: cout<<"\nThere is No Such Category......"<<endl;
   }
  cout<<"\nDo you wish to Continue.\n";
  cout<<"Press Y to continue or Press N to STOP:";
  cin>>cControl;
  cout<<endl;
  }while ( cControl == 'y' || cControl == 'Y' );
 cout<<"\n***********Thank You*********\n\n";
}
