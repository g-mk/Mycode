#include<iostream>
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
         CStudent(char *,int , float *, int,int,int);
         CStudent(CStudent &Stud);
         void SetData(char *,int , float *, int,int,int);
         int CalculateCutOff(int,int BonusMark =0 );
         void Display();
         void CategoryDisplay();
         ~CStudent();
  private:
         char *m_sName;
         int m_nAddmissionNo;
         float m_fMarks[4];
         float m_fCutOff;
         struct SDateOfBirth m_SBirthDay;
 };
