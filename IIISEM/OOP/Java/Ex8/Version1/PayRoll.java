 import java.io.*;
 import java.util.*;
 class CEmployee
 {
   public CEmployee()
   {
     m_sName =" ";
     m_nSalary = 0;
     m_nAadharNo = m_nAssignAadhar++;
     m_nDate = 0;
     m_nMonth = 0;
     m_nYear = 0;
   }
   public CEmployee(String sName,int nDate,int nMonth,int nYear)
   {

     m_sName = sName;
     m_nSalary = 0;
     m_nAadharNo = m_nAssignAadhar++;
     m_nDate = nDate;
     m_nMonth = nMonth;
     m_nYear = nYear;
   }
  public CEmployee(CEmployee Emp)
   {

     m_sName = Emp.m_sName;
     m_nSalary = 0;
     m_nAadharNo = Emp.m_nAadharNo+1;
     m_nDate = Emp.m_nDate;
     m_nMonth = Emp.m_nMonth;
     m_nYear = Emp.m_nYear;
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
           if(m_nMonth == nCMonth)
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
    Scanner in = new Scanner(System.in);
    System.out.printf("\nName:");
    m_sName=in.next();
    m_nAadharNo=m_nAssignAadhar++;
    System.out.println("Aadhar Number:"+m_nAadharNo);
    System.out.printf("\nDate of Birth"+"\n\n"+"Date:");
    m_nDate = in.nextInt();
    System.out.printf("\nMonth:");
    m_nMonth = in.nextInt();
    System.out.printf("\nYear:");
    m_nYear = in.nextInt();
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
   private int m_nDate;
   private int m_nMonth;
   private int m_nYear;
   private static int m_nBonus=0;
   private static int m_nOTAmount=0;
   private static int m_nAssignAadhar=1000;

 }

 public class PayRoll
 {
  public static void main(String args[])
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
   System.out.println("***************************Thank You*****************");

 }
}
