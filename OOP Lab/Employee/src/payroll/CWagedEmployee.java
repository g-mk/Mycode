package payroll;

public class CWagedEmployee implements CEmployee{
	/**
     * Default Constructor for initializing the field
     */
    public CWagedEmployee()
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
    public CWagedEmployee(String sName,int nDate,int nMonth,int nYear)
    {
        super(sName,nDate,nMonth,nYear);
    }
    /**
     * Method to Calculate the Salary of the Employee
     * @param nSalary Daily Wages amount
     * @param nHours No.of Hours the Employee worked
     * @return Calculated Salary
     */
    public int calculateWages(int nSalary,int nHours)
    {
        int nWage;
        if(nHours>208)
            nWage = nSalary*208 + m_nOTAmount * (nHours-208);
        else
            nWage = nSalary * nHours;
        setSalary(nWage);
        return 1;
    }
    /**
    * Static Function to set Over Time Amount
    * @param nOT Over Time Amount
    */
   public static void setOTAmount(int nOT)
   {
    m_nOTAmount = nOT;
   }
    private static int m_nOTAmount;

}
