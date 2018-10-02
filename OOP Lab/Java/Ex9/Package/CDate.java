package payroll;
import java.io.*;
import java.util.*;
/**
 * This Class descries the Date field of CEmployee
 * @author Guru Manikandan
 */
public class CDate implements Cloneable
 {
    /**
     * Default Constructor to allocate and assign default value
     */
  public CDate()
  {
      m_nDate=0;
      m_nMonth=0;
      m_nYear=0;
  }
  /**
   * Parametarized Constructor to assign the values given by the user
   * @param nDate Date of Birth
   * @param nMonth Month of Birth
   * @param nYear  Year of Birth
   */
  public CDate(int nDate,int nMonth,int nYear)
  {
      m_nDate=nDate;
      m_nMonth=nMonth;
      m_nYear=nYear;
  }
  /**
   * Set the Date of Birth
   * @param nDate Birth Date
   */
  public void setDate(int nDate)
  {
   m_nDate = nDate;
  }
  /**
   * Set the Month
   * @param nMonth Birth Month
   */
  public void setMonth(int nMonth)
  {
   m_nMonth = nMonth;
  }
  /**
   * Set the Year
   * @param nYear Year of Birth
   */
  public void setYear(int nYear)
  {
   m_nYear = nYear;
  }
  /**
   * Gets the Date
   * @return m_nDate
   */
 public int getDate()
  {
   return m_nDate;
  }
/**
 * Gets the Month
 * @return m_nMonth
 */
  public int getMonth()
  {
   return m_nMonth;
  }
/**
 * Gets the Year
 * @return m_nYear
 */
  public int getYear()
  {
   return m_nYear;
  }
  /**
   * This Metho is to Clone the Object
   * @return Object
   * @throws CloneNotSupportedException Exception Handling for Cloning
   */
   public Object clone()throws CloneNotSupportedException
   {
     return super.clone();
   }

  private int m_nDate;
  private int m_nMonth;
  private int m_nYear;
 }
