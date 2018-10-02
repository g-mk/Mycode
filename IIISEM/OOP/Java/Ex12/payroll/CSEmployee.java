package payroll;
import java.io.*;
import java.util.*;
/**
 * This Class describes the Employee details
 * @author Guru Manikandan
 */
public abstract class CSEmployee implements Cloneable,IEmployee
 {
    /**
     * Default Constructor to allocate memory
     */
   public CSEmployee()
   {
     m_sName =" ";
     m_nSalary = 0;
     m_nAadharNo = m_nAssignAadhar++;
     m_nDOB = new CDate();
   }
   /**
    * Parametarized Constructor to assign the give values
    * @param sName Name of the Employee
    * @param nDate Birth Date of the Employee
    * @param nMonth Birth Month of the Employee
    * @param nYear  Birth Year of the Employee
    */
   public CSEmployee(String sName,int nDate,int nMonth,int nYear)
   {

     m_sName = sName;
     m_nSalary = 0;
     m_nAadharNo=m_nAssignAadhar++;
     m_nDOB = new CDate(nDate,nMonth,nYear);

   }
   /**
    * Clone Function to create a copy of the Object of class CEmployee
    * @return CEmployee Object
    * @throws CloneNotSupportedException Exception Handling for Cloning
    */
   public CSEmployee clone()throws CloneNotSupportedException
   {
     CSEmployee emp=(CSEmployee)super.clone();
     try
     {
     emp.m_nDOB=(CDate)m_nDOB.clone();
     }
     catch (CloneNotSupportedException exp)
     {
         System.err.println("Error in cloning");
     }
     return emp;
   }
   /**
    * To get the Employee details from the user
    */
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
   }
   /**
    * Method to Display the Employee Details
    */
   public void displayDetails()
   {
     System.out.println("\nName "+ m_sName);
     System.out.println("Aadhar No: "+m_nAadharNo);
     System.out.printf("Salary: %,3d \n",m_nSalary);
   }
   public void setSalary(int nSalary)
   {
       m_nSalary=nSalary;
   }
   public int getDOBMonth()
   {
       return m_nDOB.getMonth();
   }
   
    public void setName(String sName)
   {
       m_sName=sName;
   }
   
   public void setDate(int nDate )
   {
       m_nDOB.setDate(nDate);
   }
   public void setMonth(int nMonth)
   {
       m_nDOB.setMonth(nMonth);
   }
   public void setYear(int nYear)
   {
       m_nDOB.setYear(nYear);
   }
   private String m_sName;
   private int m_nSalary;
   private int m_nAadharNo;
   private CDate m_nDOB;
   private static int m_nAssignAadhar=1001;
 }

