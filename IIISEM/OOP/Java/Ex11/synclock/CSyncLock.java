package synclock;
import locking.*;
import java.util.*;
public class CSyncLock
{
    public static void main(String []args)
    {
        Scanner in = new Scanner(System.in);
        System.out.printf("Enter the Size of Queue: ");
        int nSize = in.nextInt();
        CQueue queue = new CQueue (nSize);
        System.out.printf("Enter the Thread Count for Each Operation:");
        int nCount = in.nextInt();
        for(int nLoop=0;nLoop<nCount;nLoop++)
        {
            CEnqueueRunnable enqueuerun = new CEnqueueRunnable(queue);
            Thread t = new Thread(enqueuerun);
            t.start();
        }
        for(int nLoop=0;nLoop<nCount;nLoop++)
        {
            CDequeueRunnable dequeuerun = new CDequeueRunnable(queue);
            Thread t = new Thread(dequeuerun);
            t.start();
        }
        
    }
}
