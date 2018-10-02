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
            int nLoop=5;
            while(nLoop-->0)
            {
            m_nqueue.dequeue();
            }
        }
        catch(InterruptedException err)
        {
            
        } 
        
    }
    private CQueue m_nqueue;
}