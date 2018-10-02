import java.io.*;
import java.util.*;
/**
*This Class is to check the gregorian Calender
*/
 public class Sample
{
 public static void main(String arg[])
  {
   int nMonth,Day,Year;
    GregorianCalendar Cal = new GregorianCalendar();
      nMonth = Cal.get(Calendar.MONTH);
      Day = Cal.get(Calendar.DATE);
      Year= Cal.get(Calendar.YEAR);
   System.out.println("Date: "+Day+"\nMonth:"+nMonth+"\nYear : "+Year);

   
  }
}
