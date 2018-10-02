#include"hStudent.h"
int CStudent :: m_nWaitingList =3;
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
void CStudent :: GetData()
{
    cout<<"****************Addmission Process***************\n";
    cout<<"Enter the Name:";
    cin>>m_sName;
    cout<<" Addmission No: "<< CStudent::m_nAddmissionNo<<endl;
    cout<<"Enter the Maths Mark:";
    cin>>m_fMarks[0];
    cout<<"Enter the Phyiscs Mark:";
    cin>>m_fMarks[1];
    cout<<"Enter the Chemistry Mark:";
    cin>>m_fMarks[2];
    cout<<"Enter the Campus Entrance Test Mark:";
    cin>>m_fMarks[3];
    cout<<"Enter the Date of Birth\n";
    cout<<"Date:";
    cin>>m_SBirthDay.m_nDate;
    cout<<"Month:";
    cin>>m_SBirthDay.m_nMonth;
    cout<<"Year: ";
    cin>>m_SBirthDay.m_nYear;
}
int CStudent :: CalculateCutOff(int nCategory,int nBonusMark)
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
    m_fCutOff += nBonusMark;
    return 1;
}
void CStudent :: Display()
{
    cout<<"Name : "<<m_sName<<endl;
    cout<<"Addmission No: "<<m_nAddmissionNo<<endl;
    cout<<"CutOff :"<<m_fCutOff;
    cout<<"Remaining Seats :"<<CStudent::m_nTotalSeat<<endl;
    cout<<"Waiting List :"<<CStudent::m_nWaitingList<<endl;
    cout<<"****************************************************";
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

void CStudent :: AssignTotalSeats(int nSeat)
{
    m_nTotalSeat=nSeat;
}

void CStudent :: AssignWaitingList(int nSeat)
{
    m_nWaitingList=nSeat;
}
CStudent :: ~CStudent()
{


}
