package payroll;
import java.io.*;
import java.util.*;
public class CEmployee implements Cloneable
 {
   public CEmployee()
   {
     m_sName =" ";
     m_nSalary = 0;
     m_nAadharNo = m_nAssignAadhar++;
     m_nDOB = new CDate();
   }
   public CEmployee(String sName,int nDate,int nMonth,int nYear)
   {

     m_sName = sName;
     m_nSalary = 0;
     m_nAadharNo=m_nAssignAadhar++;
     m_nDOB = new CDate(nDate,nMonth,nYear);

   }
   public CEmployee clone()throws CloneNotSupportedException
   {
     CEmployee emp=(CEmployee)super.clone();
     try
     {
     emp.m_nDOB=(CDate)m_nDOB.clone();
     }
     catch (CloneNotSupportedException exp)
     {
     }
     return emp;
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
   private CDate m_nDOB;
   private static int m_nBonus;
   private static int m_nOTAmount;
   private static int m_nAssignAadhar=1001;
 }
