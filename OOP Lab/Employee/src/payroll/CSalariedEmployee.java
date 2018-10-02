package payroll;
import java.util.*;

public class CSalariedEmployee implements CEmployee{
	/**
	  * Default Constructor for initializing the field 
	  */
	  public CSalariedEmployee()
	  {
	      super();
	  }
	  /**
	  * Parametarized Constructor for initializing the field 
	  * @param sName Name of the Waged Employee
	  * @param nDate Birth Date of the Employee
	  * @param nMonth Birth Month of the Employee
	  * @param nYear  Birth Year of the Employee
	  */
	  public CSalariedEmployee(String sName,int nDate,int nMonth,int nYear)
	  {
	      super(sName,nDate,nMonth,nYear);
	  }
	  /**
	  * Method to Calculate the Salary of the Employee
	  * @param nSalary Daily Wages amount
	  * @param nDays No.of Days the Employee worked
	  * @return Calculated Salary 
	  */
	  public int calculateWages(int nSalary,int nDays)
	    {
	      int nCMonth;
	      GregorianCalendar Cal = new GregorianCalendar();
	      nCMonth = Cal.get(Calendar.MONTH)+1;
	      nSalary = nSalary*nDays;
	      if(getDOBMonth()== nCMonth)
	        nSalary += m_nBonus;
	      setSalary(nSalary);
	      return 1;
	    }
	 /**
	 * Static Function to set Bonus Amount
	 * @param nBonus Bonus Amount
	 */
	   public static void setBonus(int nBonus)
	   {
	    m_nBonus = nBonus;
	   }
	 private static int m_nBonus;

}
