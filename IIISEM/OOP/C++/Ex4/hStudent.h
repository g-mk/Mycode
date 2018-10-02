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
    void GetData();
    int CalculateCutOff(int,int nBonusMark=0);
    void Display();
    static int GenerateAddNo();
    int IsEligible();
    ~CStudent();
    static void AssignTotalSeat(int);
    static void AssignWaitingList(int);
private:
    string m_sName;
    int m_nAddmissionNo;
    float m_fMarks[4];
    float m_fCutOff;
    struct SDateOfBirth m_SBirthDay;
    static int m_nAssignAddNo;
    static int m_nTotalSeat;
    static int m_nWaitingList;


};

