#include"hStudent.h"
int Student :: m_nWaitingList = 1;
int Student :: m_nTotalSeat = 1;
int Student :: m_nAssignAddNo = 1;

Student :: Student() 
{
    cout<<"\n*******************Base Class Constructor******************\n";
    m_sName = " ";
    m_nAddmissionNo = Student::GenerateAddNo();
    for(int i=0;i<4;i++)
    {
        m_fMarks[i]=0.0;
    }
    m_fCutOff =0.0;
    m_SBirthDay.m_nDate=0;
    m_SBirthDay.m_nMonth=0;
    m_SBirthDay.m_nYear=0;
}
Student :: ~Student()
{
    cout<<"\n*******************Base Class Destructor****************\n";
}
istream& operator >> (istream &get,Student *Stud)
{
    cout<<"\n*******************Addmission Process**********************\n";
    cout<<"Enter the Name:";
    get>>Stud->m_sName;
    cout<<" Addmission No: "<< Stud->m_nAddmissionNo<<endl;
    cout<<"Enter the Maths Mark:";
    get>>Stud->m_fMarks[0];
    cout<<"Enter the Phyiscs Mark:";
    get>>Stud->m_fMarks[1];
    cout<<"Enter the Chemistry Mark:";
    get>>Stud->m_fMarks[2];
    cout<<"Enter the Campus Entrance Test Mark:";
    get>>Stud->m_fMarks[3];
    cout<<"Enter the Date of Birth\n";
    cout<<"Date:";
    get>>Stud->m_SBirthDay.m_nDate;
    cout<<"Month:";
    get>>Stud->m_SBirthDay.m_nMonth;
    cout<<"Year: ";
    get>>Stud->m_SBirthDay.m_nYear;
    return get;
}
 
ostream& operator << (ostream &print,Student *Stud)
{
    print<<"Name : "<<Stud->m_sName<<endl;
    print<<"Addmission No: "<<Stud->m_nAddmissionNo<<endl;
    print<<"CutOff :"<<Stud -> m_fCutOff<<endl;
    print<<"\nRemaining Seats: "<<Student :: m_nTotalSeat<<endl;
    print<<"\nRemaining Waiting Seats: "<<Student :: m_nWaitingList<<endl;
}
Student* Student :: operator+ (int nBonusMark)
{
 this->m_fCutOff=this->m_fCutOff + nBonusMark;
 if(this->m_fCutOff>200)
  this->m_fCutOff = 200;
 return this;
}
Student* Student :: operator= (Student* Candidate)
{
 this->m_fCutOff = Candidate->m_fCutOff;
 return this;
}
int Student :: IsEligible()
{
    if(this->m_fCutOff>160)
    {
        if(this->m_nTotalSeat)
        {
            this->m_nTotalSeat--;
            return 1;
        }
        else if (this->m_nWaitingList)
        {
            this->m_nWaitingList--;
            return 2;
        }
         else
          return 0;
     }
    else
        return -1;
}

int Student :: GenerateAddNo()
{
    return (SET + m_nAssignAddNo++);
}
/*************GENERAL STUDENTS CLASS METHODS DEFINITOIN**************/
GeneralStudent :: GeneralStudent () : Student()
{
 cout<<"\n************General Students Class Constructor**************\n";
}
GeneralStudent :: ~GeneralStudent()
{
 cout<<"\n**************GeneralStudent Destructor*****************\n";
}
int GeneralStudent :: CalculateCutOff()
{
 this->m_fCutOff =this-> m_fMarks[0]*0.5 + ((this->m_fMarks[1] + this->m_fMarks[2])/2 * 0.25) 
                + this->m_fMarks[3]*0.25;
 if(this->m_fCutOff)
  return 1;
 else 
 	return 0;
}
/*************SPORTS STUDENTS CLASS METHODS DEFINITOIN**************/
SportsStudent :: SportsStudent() : Student()
{
 cout<<"\n**************Sports Student Class Constuctor**************\n";
}
SportsStudent ::~SportsStudent()
{
 cout<<"\n**************Sports Student Destructor*****************\n";
}
int SportsStudent :: CalculateCutOff()
{
 this-> m_fCutOff=this->m_fMarks[0]*0.45 + ((this->m_fMarks[1] + this->m_fMarks[2])/2 * 0.2)
                  + this->m_fMarks[3]*0.35;
 if(this->m_fCutOff) 
	return 1;
 else 
  return 0;
}
/*************PHYSICALLY CHALLENGED CLASS METHODS DEFINITIONS******/
PhysicallyChallenged :: PhysicallyChallenged () : Student()
{
 cout<<"\n******Physically Challenged Student Class Constructor******\n";
}
PhysicallyChallenged :: ~PhysicallyChallenged()
{
 cout<<"\n******Physically Challenged Student Class Destructor******\n";
}
int PhysicallyChallenged :: CalculateCutOff()
{
  this->m_fCutOff = this->m_fMarks[0]*0.4 + ((this->m_fMarks[1] + this->m_fMarks[2])/2 * 0.2)
                  + this->m_fMarks[3]*0.4;
	 if(this->m_fCutOff)
		return 1;
	 else
		return 0;
}

