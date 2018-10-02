#include<iostream>
#define SET 1000
using namespace std;
struct SDateOfBirth
{
    int m_nDate;
    int m_nMonth;
    int m_nYear;

};


class Student
{
 public:
  Student ();
  virtual ~Student();
  virtual int CalculateCutOff()=0;
  Student* operator + (int nBonusMark );
  Student* operator = (Student *Stud);
  static int GenerateAddNo();
  int IsEligible();
  friend ostream& operator <<(ostream&,Student*);
  friend istream& operator >>(istream& ,Student*);
 protected:
  static int m_nAssignAddNo;
  static int m_nTotalSeat;
  static int m_nWaitingList;
  string m_sName;
  int m_nAddmissionNo;
  float m_fMarks[4];
  float m_fCutOff;
  struct SDateOfBirth m_SBirthDay;
};

class GeneralStudent: public Student
{
 public :
  GeneralStudent();
 ~GeneralStudent();
  int CalculateCutOff();
};
class SportsStudent : public Student 
{
 public:
  SportsStudent();
 ~SportsStudent();
  int CalculateCutOff();
};
class PhysicallyChallenged : public Student
{
 public:
  PhysicallyChallenged();
 ~PhysicallyChallenged();
  int CalculateCutOff();
};
  
