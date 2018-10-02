package payrollmanagement;
import java.io.*;
import java.util.*;

class Date
 {
  public Date()
  {
      m_nDate=0;
      m_nMonth=0;
      m_nYear=0;
  }
  public Date(int nDate,int nMonth,int nYear)
  {
      m_nDate=nDate;
      m_nMonth=nMonth;
      m_nYear=nYear;
  }
  public Date(Date Dob)
  {
      m_nDate=Dob.m_nDate;
      m_nMonth=Dob.m_nMonth;
      m_nYear=Dob.m_nYear;
  }
  public void setDate(int nDate)
  {
   m_nDate = nDate;
  }
  public void setMonth(int nMonth)
  {
   m_nMonth = nMonth;
  }
  public void setYear(int nYear)
  {
   m_nYear = nYear;
  }
 public int getDate()
  {
   return m_nDate;
  }

  public int getMonth()
  {
   return m_nMonth;
  }

  public int getYear()
  {
   return m_nYear;
  }

  private int m_nDate;
  private int m_nMonth;
  private int m_nYear;
 }

 class CEmployee
 {
   public CEmployee()
   {
     m_sName =" ";
     m_nSalary = 0;
     m_nAadharNo = m_nAssignAadhar++;
     m_nDOB = new Date();
   }
   public CEmployee(String sName,int nDate,int nMonth,int nYear)
   {

     m_sName = sName;
     m_nSalary = 0;
     m_nAadharNo=m_nAssignAadhar++;
     m_nDOB = new Date(nDate,nMonth,nYear);

   }
  public CEmployee(CEmployee Emp)
   {

     m_sName = Emp.m_sName;
     m_nSalary = 0;
     m_nAadharNo=m_nAssignAadhar++;
    m_nDOB= new Date(Emp.m_nDOB);
   }

   public static void setBonus(int nBonus)
   {
    m_nBonus = nBonus;
   }
   public static void setOTAmount(int nOT)
   {
    m_nOTAmount = nOT;
   }

   public int calculateWages(int nType,int nSalary,int nWork)
    {
      int nCMonth;
      GregorianCalendar Cal = new GregorianCalendar();
      nCMonth = Cal.get(Calendar.MONTH)+1;
      switch(nType)
      {
       case 1:
           m_nSalary = nSalary*nWork;
           if(m_nDOB.getMonth()== nCMonth)
             m_nSalary += m_nBonus;
           break;
       case 2:
           if(nWork>208)
             m_nSalary = nSalary*208 + m_nOTAmount * (nWork-208);
           else
             m_nSalary = nSalary * nWork;
           break;
       default:
           return -1;
      }
     return 1;
    }
   public void getDetails()
   {
    int nDob;
    Scanner in = new Scanner(System.in);
    System.out.printf("\nName:");
    m_sName=in.next();
    System.out.println("\nAadhar Number: "+ m_nAadharNo);
    System.out.printf("\nDate of Birth"+"\n\n"+"Date:");
    nDob=in.nextInt();
    m_nDOB.setDate(nDob);
    System.out.printf("\nMonth:");
    nDob=in.nextInt();
    m_nDOB.setMonth(nDob);
    System.out.printf("\nYear:");
    nDob=in.nextInt();
    m_nDOB.setYear(nDob);
    m_nSalary = 0;
   }
   public void displayDetails()
   {
     System.out.println("Name "+ m_sName);
     System.out.println("Aadhar No: "+m_nAadharNo);
     System.out.println("Salary: "+ m_nSalary);
   }
   private String m_sName;
   private int m_nSalary;
   private int m_nAadharNo;
   private Date m_nDOB;
   private static int m_nBonus;
   private static int m_nOTAmount;
   private static int m_nAssignAadhar=1001;
 }
/**
 *
 * @author Guru Manikandan
 */
public class PayRollManagement 
{
    /**
     * @param args the command line arguments
     */
  public static void main(String[] args) 
  {
   int nCategory;
   int nWork;
   String sName;
   int nMonth;
   int nSalary;
   int nDate;
   int nYear;
   int nBonus;
   Scanner input = new Scanner(System.in);
   System.out.printf("\nEnter the Birthday Bonus Amount: ");
   nBonus = input.nextInt();
   CEmployee.setBonus(nBonus);
   System.out.printf("\nEnter the OT Amount: ");
   nBonus = input.nextInt();
   CEmployee.setOTAmount(nBonus);
   System.out.println("\n***********************Default Constructor**********************\n");
   CEmployee Emp = new CEmployee();
   System.out.println("Enter the Category to which the Employee belong to....\n");
   System.out.println("1.Salaried Employee."+"\n"+"2.Waged Employee."+"\n");
   System.out.printf("Category:");
   nCategory = input.nextInt();
   Emp.getDetails();
   switch(nCategory)
   {
    case 1:
           System.out.printf("\nEnter the Basic Pay for the Employee:");
           nSalary = input.nextInt();
           System.out.printf("\nEnter the No. of days the Employee Worked:");
           nWork = input.nextInt();
           Emp.calculateWages(nCategory,nSalary,nWork);
           break;
    case 2:
           System.out.println("\nEnter the Basic Pay for the Employee:");
           nSalary = input.nextInt();
           System.out.println("\nEnter the No. of Hours the Employee Worked:");
           nWork = input.nextInt();
           Emp.calculateWages(nCategory,nSalary,nWork);
           break;
    default:
           System.out.println("******************There is no such Category***************");
   }
   System.out.println("Employee Details:");
   Emp.displayDetails();

   System.out.println("\n***********************Parametarized Constructor**********************\n");
   System.out.println("\nEnter the Category to which the Employee belong to.... \n");
   System.out.println("1.Salaried Employee."+"\n"+"2.Waged Employee."+"\n");
   System.out.printf("Category:");
   nCategory = input.nextInt();
   System.out.printf("\nName:");
    sName=input.next();
    System.out.printf("\nDate of Birth"+"\n\n"+"Date:");
    nDate = input.nextInt();
    System.out.printf("\nMonth:");
    nMonth = input.nextInt();
    System.out.printf("\nYear:");
    nYear = input.nextInt();
    CEmployee Emp1 = new CEmployee(sName,nDate,nMonth,nYear);
   switch(nCategory)
   {
    case 1:
           System.out.printf("\nEnter the Basic Pay for the Employee:");
           nSalary = input.nextInt();
           System.out.printf("\nEnter the No. of days the Employee Worked:");
           nWork = input.nextInt();
           Emp1.calculateWages(nCategory,nSalary,nWork);
           break;
    case 2:
           System.out.printf("\nEnter the Basic Pay for the Employee:");
           nSalary = input.nextInt();
           System.out.printf("\nEnter the No. of Hours the Employee Worked:");
           nWork = input.nextInt();
           Emp1.calculateWages(nCategory,nSalary,nWork);
           break;
    default:
           System.out.println("******************There is no such Category***************");
   }
   System.out.println("Employee Details:");
   Emp1.displayDetails();

   System.out.println("\n***********************Copy Constructor**********************\n");
   System.out.println("Previous Employee Details has been copied");
   CEmployee Emp2 = new CEmployee(Emp1);
   System.out.println("Enter the Category to which the Employee belong to....\n ");
   System.out.println("1.Salaried Employee."+"\n"+"2.Waged Employee."+"\n");
   System.out.printf("Category:");
   nCategory = input.nextInt();
   switch(nCategory)
   {
    case 1:
           System.out.printf("\nEnter the Basic Pay for the Employee:");
           nSalary = input.nextInt();
           System.out.printf("\nEnter the No. of days the Employee Worked:");
           nWork = input.nextInt();
           Emp2.calculateWages(nCategory,nSalary,nWork);
           break;
    case 2:
           System.out.printf("\nEnter the Basic Pay for the Employee:");
           nSalary = input.nextInt();
           System.out.printf("\nEnter the No. of Hours the Employee Worked:");
           nWork = input.nextInt();
           Emp2.calculateWages(nCategory,nSalary,nWork);
           break;
    default:
           System.out.println("******************There is no such Category***************");
   }
   System.out.println("Employee Details:");
   Emp2.displayDetails();

 }
}
