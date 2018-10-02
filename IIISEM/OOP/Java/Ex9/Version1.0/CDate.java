package payroll;
import java.io.*;
import java.util.*;
public class CDate implements Cloneable
 {
  public CDate()
  {
      m_nDate=0;
      m_nMonth=0;
      m_nYear=0;
  }
  public CDate(int nDate,int nMonth,int nYear)
  {
      m_nDate=nDate;
      m_nMonth=nMonth;
      m_nYear=nYear;
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
   public Object clone()throws CloneNotSupportedException
   {
     return super.clone();
   }

  private int m_nDate;
  private int m_nMonth;
  private int m_nYear;
 }
