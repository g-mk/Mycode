#include"hStudent.h"

int CStudent :: m_nWaitingList = 3;
int CStudent :: m_nTotalSeat = 10;
int CStudent :: m_nAssignAddNo = 1;

CStudent :: CStudent()
{
    m_sName = " ";
    m_nAddmissionNo = CStudent::GenerateAddNo();
    for(int i=0;i<4;i++)
    {
        m_fMarks[i]=0.0;
    }
    m_fCutOff =0.0;
    m_SBirthDay.m_nDate=0;
    m_SBirthDay.m_nMonth=0;
    m_SBirthDay.m_nYear=0;
}
istream& operator >> (istream &get,CStudent &Stud) 
{
    cout<<"****************Addmission Process***************\n";
    cout<<"Enter the Name:";
    get>>Stud.m_sName;
    cout<<" Addmission No: "<< Stud.m_nAddmissionNo<<endl;
    cout<<"Enter the Maths Mark:";
    get>>Stud.m_fMarks[0];
    cout<<"Enter the Phyiscs Mark:";
    get>>Stud.m_fMarks[1];
    cout<<"Enter the Chemistry Mark:";
    get>>Stud.m_fMarks[2];
    cout<<"Enter the Campus Entrance Test Mark:";
    get>>Stud.m_fMarks[3];
    cout<<"Enter the Date of Birth\n";
    cout<<"Date:";
    get>>Stud.m_SBirthDay.m_nDate;
    cout<<"Month:";
    get>>Stud.m_SBirthDay.m_nMonth;
    cout<<"Year: ";
    get>>Stud.m_SBirthDay.m_nYear;
    return get;
}
int CStudent :: CalculateCutOff(int nCategory)
{
    switch(nCategory)
    {
        case 1: m_fCutOff = m_fMarks[0]*0.5 + ((m_fMarks[1] + m_fMarks[2])/2 * 0.25) + m_fMarks[3]*0.25;
        break;
        case 2: m_fCutOff = m_fMarks[0]*0.45 + ((m_fMarks[1] + m_fMarks[2])/2 * 0.2) + m_fMarks[3]*0.35;
        break;
        case 3: m_fCutOff = m_fMarks[0]*0.4 + ((m_fMarks[1] + m_fMarks[2])/2 * 0.2) + m_fMarks[3]*0.4;
        break;
        default: return 0;
    }
    return 1;
}
ostream& operator << (ostream &print,CStudent &Stud)
{
    print<<"Name : "<<Stud.m_sName<<endl;
    print<<"Addmission No: "<<Stud.m_nAddmissionNo<<endl;
    print<<"CutOff :"<<Stud.m_fCutOff;
    return print;
}
CStudent CStudent :: operator + (int nBonusMark)
{
 m_fCutOff=m_fCutOff + nBonusMark;
 return *this;
}
CStudent CStudent :: operator= (CStudent &Candidate)
{
 m_fCutOff = Candidate.m_fCutOff;
 return Candidate;
}
 
int CStudent :: IsEligible()
{
    if(m_nTotalSeat)
    {
        if(m_fCutOff>160)
        {
            m_nTotalSeat--;
            return 1;
        }
        else if(m_fCutOff==160)
        {
            if(m_nWaitingList)
            {
                m_nWaitingList--;
                return 2;
            }

        }
        else
            return -1;
    }
    else
        return 0;
}
int CStudent :: GenerateAddNo()
{
    return (SET + m_nAssignAddNo++);
}
CStudent :: ~CStudent()
{


}
