#include"hStudent.h"

CStudent :: CStudent()
{
 m_sName = new char[30];
 m_sName[0]='\0';
 m_nAddmissionNo = 0;
 for(int i=0; i<4; i++)
  m_fMarks[i] = 0;
 m_fCutOff = 0.0;
 m_SBirthDay.m_nDate = 0;
 m_SBirthDay.m_nMonth = 0;
 m_SBirthDay.m_nYear = 0;
}

CStudent :: CStudent(char *sName,int nAddmissionNo,float fMarks[4],int nDay,int nMonth,int nYear)
{
 m_sName = new char [30];
 strcpy(m_sName,sName);
 m_nAddmissionNo = nAddmissionNo;
  for(int i=0; i<4; i++)
  m_fMarks[i] = fMarks[i];
 m_fCutOff = 0.0;
 m_SBirthDay.m_nDate = nDay;
 m_SBirthDay.m_nMonth = nMonth;
 m_SBirthDay.m_nYear = nYear;
}

CStudent :: CStudent (CStudent& Stud )
{
 m_sName = new char [30];
 strcpy(m_sName,Stud.m_sName);
 m_nAddmissionNo = Stud.m_nAddmissionNo;
  for(int i=0; i<4; i++)
   m_fMarks[i] =Stud.m_fMarks[i];
 m_fCutOff = 0.0;
 m_SBirthDay.m_nDate = Stud.m_SBirthDay.m_nDate;
 m_SBirthDay.m_nMonth = Stud.m_SBirthDay.m_nMonth;
 m_SBirthDay.m_nYear = Stud.m_SBirthDay.m_nYear;
}

int CStudent :: CalculateCutOff(int nCategory, int nBonusMark)
{
 switch(nCategory)
  {
   case 1:m_fCutOff = m_fMarks[0] * .5 + ((m_fMarks[1] + m_fMarks[2]) /2) 
                            * 0.25 + m_fMarks[3] * .25;
          return 1;
          break;
   case 2:m_fCutOff = m_fMarks[0] * .45 + ((m_fMarks[1] + m_fMarks[2]) /2) 
                            * 0.2 + m_fMarks[3] * .35;
          return 1;
          break;  
   case 3:m_fCutOff = m_fMarks[0] * .4 + ((m_fMarks[1] + m_fMarks[2]) /2)  
                             * 0.2 + m_fMarks[3] * .4;
          return 1;
          break;
   default: 
          return 0;
  }
}

void CStudent :: SetData(char *sName, int nAddNo, float fMark[4],int nDate, int nMonth, int nYear)
{
 strcpy(m_sName,sName);
 m_nAddmissionNo = nAddNo;
  for(int i=0; i<4; i++)
  m_fMarks[i] = fMark[i];
 m_fCutOff = 0.0;
 m_SBirthDay.m_nDate = nDate;
 m_SBirthDay.m_nMonth = nMonth;
 m_SBirthDay.m_nYear = nYear;
}
void CStudent :: Display ()
{
 cout << "\nName of the Student: " << m_sName << endl;
 cout << "Addmission No: " << m_nAddmissionNo << endl;
 cout << "Maths Mark : " << m_fMarks[0] << endl;
 cout << "Phyiscs Mark : " << m_fMarks[1] << endl;
 cout << "Chemistry Mark :" << m_fMarks[2] << endl;
 cout << "Campus Mark :" << m_fMarks[3] << endl;
 cout << "CutOff Mark: "<< m_fCutOff << endl<<endl;
}
void CStudent :: CategoryDisplay()
{
	int nCategory=0,nLevel;
   cout<<"\nEnter the Category to which you belong:\n";
   cout<<"1.General Category\n2.Sports Category\n3.Physically Challenged\n";
   cout<<"Category:";
   cin>>nCategory;
   switch(nCategory)
    {
     case 1: CalculateCutOff(nCategory);
             Display();
             break;
     case 2: cout<<"\nEnter the Level for which you have played.."<<endl;
             cout<<"1.Intra School Level"<<endl<<"2.Inter School Level"<<endl<<
             "3.District Level"<<endl<<"4.State Level"<<endl<<
             "5.National Level"<<endl<<"Level You Played:";
             cin>>nLevel;
             CalculateCutOff(nCategory, nLevel);
             Display();
             break;
     case 3: cout<<"\n1.10%-20\%Challenged"<<endl<<"2.20-40\% Challenged"<<endl<<
             "3.40-50\% Challenged"<<endl
                  <<"4.50-60\% Challenged"<<endl
                  <<"5.above 60\%Challenged"<<endl;
            cout<<"\nEnter the Physically Challenged Level:";
            cin>> nLevel;
            CalculateCutOff(nCategory, nLevel);
            Display();
            break;
   default: cout<<"There is No Such Category......"<<endl;
            
   }
}

CStudent :: ~CStudent()
{

 
}
