package locking;
import java.io.*;
import java.util.*;
public class CEnqueueRunnable implements Runnable
{
    public CEnqueueRunnable(CQueue q)
    {
        m_nqueue = q;
    }
    public void run()
    {
        
        try
        {
             double nVal=50*Math.random();
             m_nqueue.enqueue((int)nVal);
             Thread.sleep(50);
        }
        catch(InterruptedException err)
        {
            
        }
        
    }
    private CQueue m_nqueue;
}
