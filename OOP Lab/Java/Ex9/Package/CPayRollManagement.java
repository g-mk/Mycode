import payroll.*;
import java.io.*;
import java.util.*;
/**
 * To Calculate the Salary for the Employee using package
 * @author Guru Manikandan
 */
public class CPayRollManagement
{
 public static void main(String args[])
  {
   int nCondition=0;
   int nCategory;
   int nWork;
   String sName;
   int nMonth;
   int nSalary;
   int nDate;
   int nYear;
   int nBonus;
   int nEmployee;
   int nLoop=0;
   Scanner input = new Scanner(System.in);
   System.out.printf("\nEnter the Birthday Bonus Amount: ");
   nBonus = input.nextInt();
   CEmployee.setBonus(nBonus);
   System.out.printf("\nEnter the OT Amount: ");
   nBonus = input.nextInt();
   CEmployee.setOTAmount(nBonus);
   System.out.printf("\nEnter the No. of Employee:");
   nEmployee=input.nextInt();
   CEmployee []emp=new CEmployee[nEmployee];
   do
   {
    System.out.println("\n***********************Default Constructor**********************\n");
    emp[nLoop] = new CEmployee();
    System.out.println("Enter the Category to which the Employee belong to....\n");
    System.out.println("1.Salaried Employee."+"\n"+"2.Waged Employee."+"\n");
    System.out.printf("Category:");
    nCategory = input.nextInt();
    emp[nLoop].getDetails();
    switch(nCategory)
    {
     case 1:
            System.out.printf("\nEnter the Basic Pay for the Employee:");
            nSalary = input.nextInt();
            System.out.printf("\nEnter the No. of days the Employee Worked:");
            nWork = input.nextInt();
            nCondition=emp[nLoop].calculateWages(nCategory,nSalary,nWork);
            break;
     case 2:
            System.out.println("\nEnter the Basic Pay for the Employee:");
            nSalary = input.nextInt();
            System.out.println("\nEnter the No. of Hours the Employee Worked:");
            nWork = input.nextInt();
            nCondition=emp[nLoop].calculateWages(nCategory,nSalary,nWork);
            break;
     default:
            System.out.println("******************There is no such Category***************");
    }
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
     emp[nLoop]= new CEmployee(sName,nDate,nMonth,nYear);
     switch(nCategory)
     {
      case 1:
             System.out.printf("\nEnter the Basic Pay for the Employee:");
             nSalary = input.nextInt();
             System.out.printf("\nEnter the No. of days the Employee Worked:");
             nWork = input.nextInt();
             nCondition=emp[nLoop].calculateWages(nCategory,nSalary,nWork);
             break;
      case 2:
             System.out.printf("\nEnter the Basic Pay for the Employee:");
             nSalary = input.nextInt();
             System.out.printf("\nEnter the No. of Hours the Employee Worked:");
             nWork = input.nextInt();
             nCondition=emp[nLoop].calculateWages(nCategory,nSalary,nWork);
             break;
      default:
             System.out.println("******************There is no such Category***************");
     }
    }
    else
     break;
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
              nCondition=emp[nLoop].calculateWages(nCategory,nSalary,nWork);
              break;
       case 2:
              System.out.printf("\nEnter the Basic Pay for the Employee:");
              nSalary = input.nextInt();
              System.out.printf("\nEnter the No. of Hours the Employee Worked:");
              nWork = input.nextInt();
              nCondition=emp[nLoop].calculateWages(nCategory,nSalary,nWork);
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

