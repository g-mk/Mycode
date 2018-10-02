import payroll.*;
import java.io.*;
import java.util.*;
public class CPayRollManagement
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
   CEmployee emp = new CEmployee();
   System.out.println("Enter the Category to which the Employee belong to....\n");
   System.out.println("1.Salaried Employee."+"\n"+"2.Waged Employee."+"\n");
   System.out.printf("Category:");
   nCategory = input.nextInt();
   emp.getDetails();
   switch(nCategory)
   {
    case 1:
           System.out.printf("\nEnter the Basic Pay for the Employee:");
           nSalary = input.nextInt();
           System.out.printf("\nEnter the No. of days the Employee Worked:");
           nWork = input.nextInt();
           emp.calculateWages(nCategory,nSalary,nWork);
           break;
    case 2:
           System.out.println("\nEnter the Basic Pay for the Employee:");
           nSalary = input.nextInt();
           System.out.println("\nEnter the No. of Hours the Employee Worked:");
           nWork = input.nextInt();
           emp.calculateWages(nCategory,nSalary,nWork);
           break;
    default:
           System.out.println("******************There is no such Category***************");
   }
   System.out.println("Employee Details:");
   emp.displayDetails();

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
   CEmployee emp1 = new CEmployee(sName,nDate,nMonth,nYear);
   switch(nCategory)
   {
    case 1:
           System.out.printf("\nEnter the Basic Pay for the Employee:");
           nSalary = input.nextInt();
           System.out.printf("\nEnter the No. of days the Employee Worked:");
           nWork = input.nextInt();
           emp1.calculateWages(nCategory,nSalary,nWork);
           break;
    case 2:
           System.out.printf("\nEnter the Basic Pay for the Employee:");
           nSalary = input.nextInt();
           System.out.printf("\nEnter the No. of Hours the Employee Worked:");
           nWork = input.nextInt();
           emp1.calculateWages(nCategory,nSalary,nWork);
           break;
    default:
           System.out.println("******************There is no such Category***************");
   }
   System.out.println("Employee Details:");
   emp1.displayDetails();

   System.out.println("\n***********************Copy Constructor**********************\n");
   try
   {
    System.out.println("Previous Employee Details has been copied");
    CEmployee emp2 = emp1.clone();
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
            emp2.calculateWages(nCategory,nSalary,nWork);
            break;
     case 2:
            System.out.printf("\nEnter the Basic Pay for the Employee:");
            nSalary = input.nextInt();
            System.out.printf("\nEnter the No. of Hours the Employee Worked:");
            nWork = input.nextInt();
            emp2.calculateWages(nCategory,nSalary,nWork);
            break;
     default:
            System.out.println("******************There is no such Category***************");
    }
    System.out.println("Employee Details:");
    emp2.displayDetails();
   }
   catch(CloneNotSupportedException se)
   {

   }
   System.out.println("********************Thank You******************");
   }
 }
