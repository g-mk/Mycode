#include<iostream>
using namespace std;
struct SStudent 
 {
 char m_sName[30];
 int m_nAddmissionNo;
 float m_fMarks[4];
 };

float CalculateCutoff(struct SStudent Candidate, int nCategory, int nBonus=0);

