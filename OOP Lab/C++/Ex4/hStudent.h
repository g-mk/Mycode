#include<iostream>
#define SET 1000
using namespace std;
struct SDateOfBirth
{
    int m_nDate;
    int m_nMonth;
    int m_nYear;

};
class CStudent
{
public:
    CStudent();
    int CalculateCutOff(int);
    static int GenerateAddNo();
    int IsEligible();
    CStudent operator + (int nBonusMark );
    CStudent operator = (CStudent& Stud);
    friend ostream& operator <<(ostream&,CStudent &);
    friend istream& operator >>(istream& , CStudent &);
    ~CStudent();
    static int m_nAssignAddNo;
    static int m_nTotalSeat;
    static int m_nWaitingList;
private:
    string m_sName;
    int m_nAddmissionNo;
    float m_fMarks[4];
    float m_fCutOff;
    struct SDateOfBirth m_SBirthDay;

};

