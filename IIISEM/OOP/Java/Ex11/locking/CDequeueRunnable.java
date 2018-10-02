package locking;
import java.io.*;
import java.util.*;
public class CDequeueRunnable implements Runnable
{
    public CDequeueRunnable(CQueue q)
    {
        m_nqueue = q;
    }
    public void run()
    {
        try
        {
            //int nLoop=10;
            //while(nLoop-->0)
           // {
             m_nqueue.dequeue();
             Thread.sleep(50);
            //}
        }
        catch(InterruptedException err)
        {
            
        } 
        
    }
    private CQueue m_nqueue;
}
