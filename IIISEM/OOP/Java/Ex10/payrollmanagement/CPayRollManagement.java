 package payrollmanagement;
import payroll.*;
import java.io.*;
import java.util.*;
/**
 * To Calculate the Salary for the Employee using package
 * @author Guru Manikandan
 */
public class CPayRollManagement
{
    /**
     * To Implement the Pay Roll Management System (Main Function)
     * @param args Comment Line Argument Varible
     */
 public static void main(String args[])
  {
   int nCondition=0;
   int nCategory;
   int nWork=0;
   String sName;
   int nMonth;
   int nSalary=0;
   int nDate;
   int nYear;
   int nBonus;
   int nEmployee;
   int nLoop=0;
   Scanner input = new Scanner(System.in);
   System.out.printf("\nEnter the Birthday Bonus Amount: ");
   nBonus = input.nextInt();
   CSalariedEmployee.setBonus(nBonus);
   System.out.printf("\nEnter the OT Amount: ");
   nBonus = input.nextInt();
   CWagedEmployee.setOTAmount(nBonus);
   System.out.printf("\nEnter the No. of Employee:");
   nEmployee=input.nextInt();
   CEmployee []emp=new CEmployee[nEmployee];
   do
   {
    System.out.println("\n***********************Default Constructor**********************\n");
    System.out.println("Enter the Category to which the Employee belong to....\n");
    System.out.println("1.Salaried Employee."+"\n"+"2.Waged Employee."+"\n");
    System.out.printf("Category:");
    nCategory = input.nextInt();
    switch(nCategory)
    {
     case 1:
            emp[nLoop] = new CSalariedEmployee();
            emp[nLoop].getDetails();
            System.out.printf("\nEnter the Basic Pay for the Employee:");
            nSalary = input.nextInt();
            System.out.printf("\nEnter the No. of days the Employee Worked:");
            nWork = input.nextInt();
            break;
     case 2:
            emp[nLoop] = new CWagedEmployee();
            emp[nLoop].getDetails();
            System.out.println("\nEnter the Daily Wage for the Employee:");
            nSalary = input.nextInt();
            System.out.println("\nEnter the No. of Hours the Employee Worked:");
            nWork = input.nextInt();
            break;
     default:
            System.out.println("******************There is no such Category***************");
    }
    nCondition=emp[nLoop].calculateWages(nSalary,nWork);
    if(nCondition==1)
        System.out.println("*******************Salary of the Employee Calculated*************");
    else
        System.out.println("*******************Salary of the Employee Not Calculated*************");
    if(++nLoop<nEmployee)
    {
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
     switch(nCategory)
     {
      case 1:
             emp[nLoop]= new CSalariedEmployee(sName,nDate,nMonth,nYear);
             System.out.printf("\nEnter the Basic Pay for the Employee:");
             nSalary = input.nextInt();
             System.out.printf("\nEnter the No. of days the Employee Worked:");
             nWork = input.nextInt();
             break;
      case 2:
             emp[nLoop]= new CWagedEmployee(sName,nDate,nMonth,nYear);
             System.out.printf("\nEnter the Daily Wages for the Employee:");
             nSalary = input.nextInt();
             System.out.printf("\nEnter the No. of Hours the Employee Worked:");
             nWork = input.nextInt();
             break;
      default:
             System.out.println("******************There is no such Category***************");
     }
    }
    else
     break;
    nCondition=emp[nLoop].calculateWages(nSalary,nWork);
    if(nCondition==1)
        System.out.println("*******************Salary of the Employee Calculated*************");
    else
        System.out.println("*******************Salary of the Employee Not Calculated*************");
    if(++nLoop<nEmployee)
    {
     System.out.println("\n***********************Cloning**********************\n");
     try
     {
      System.out.println("Previous Employee Details has been copied");
      emp[nLoop] = emp[nLoop-1].clone();
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
              break;
       case 2:
              System.out.printf("\nEnter the Daily Wages for the Employee:");
              nSalary = input.nextInt();
              System.out.printf("\nEnter the No. of Hours the Employee Worked:");
              nWork = input.nextInt();
              break;
       default:
              System.out.println("******************There is no such Category***************");
      }
     }
     catch(CloneNotSupportedException exp)
     {
       System.out.println("Clone not Created");
     }
    }
    else
     break;
    nCondition=emp[nLoop].calculateWages(nSalary,nWork);
    if(nCondition==1)
        System.out.println("*******************Salary of the Employee Calculated*************");
    else
        System.out.println("*******************Salary of the Employee Not Calculated*************");
   }while(++nLoop<nEmployee);
  System.out.println("Employee Details:");
  for(CEmployee employee : emp)
   {
    employee.displayDetails();
   }
   System.out.println("********************Thank You******************");
  }
 }

