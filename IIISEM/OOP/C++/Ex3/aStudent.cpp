#include"hStudent.h"
main()
{
 char sName[30];
 int nAddmission;
 float fMarks[4];
 int nDate,nMonth,nYear;
 CStudent Candidate1;
 cout<<"**********Using Default Constructor************\n";
 cout << "\nEnter the name of the Student: ";
 cin >> sName;
 cout << "Enter the Addmission No: ";
 cin >> nAddmission;
  cout << "Enter the Maths Mark :";
  cin>> fMarks[0];
  cout << "Enter the Phyiscs Mark :";
  cin>> fMarks[1];
  cout << "Enter the Chemistry Mark :";
  cin>> fMarks[2];
  cout << "Enter the Campus Mark :";
  cin >> fMarks[3];
 cout << "Enter Your Date OF Birth.....\n";
  cout << "Date: ";
  cin >> nDate;
  cout << "Month: ";
  cin >> nMonth;
  cout << "Year: ";
  cin >> nYear;
   Candidate1.SetData(sName,nAddmission,fMarks,nDate,nMonth,nYear);
   Candidate1.CategoryDisplay();
 cout<<"\n***********Using Parametarised Consructor********\n";
 cout << "\nEnter the name of the Student: ";
 cin >> sName;
 cout << "Enter the Addmission No: ";
 cin >> nAddmission;
  cout << "Enter the Maths Mark :";
  cin>> fMarks[0];
  cout << "Enter the Phyiscs Mark :";
  cin>> fMarks[1];
  cout << "Enter the Chemistry Mark :";
  cin>> fMarks[2];
  cout << "Enter the Campus Mark :";
  cin>>fMarks[3];
  cout << "Date: ";
  cin >> nDate;
  cout << "Month: ";
  cin >> nMonth;
  cout << "Year: ";
  cin >> nYear;
 CStudent Candidate2(sName,nAddmission,fMarks,nDate,nMonth,nYear);
 Candidate2.CategoryDisplay();
 cout<<"Details of Student 2 was copied...\nNow Check CutOff in Other Category..\n"; 
 cout<<"***********Using Copy Consructor********\n";
 CStudent Candidate3(Candidate2);
 Candidate3.CategoryDisplay();
 cout<<"**********Thank You***********\n";
}

