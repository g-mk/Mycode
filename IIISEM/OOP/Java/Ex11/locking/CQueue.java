package locking;
import java.util.concurrent.locks.*;
import java.util.Scanner.*;
public class CQueue
{
    public CQueue(int nSize)
    {
        m_nQueue = new int[nSize];
        m_nFront= 0;
        m_nRear=-1;
        m_nSize=nSize;
        m_queuelock=new ReentrantLock();
        m_insertionwait = m_queuelock.newCondition(); 
        m_deletionwait = m_queuelock.newCondition();
    }
    public void enqueue(int nVal) throws InterruptedException 
    {
        //System.out.println("Enqueue:");
        m_queuelock.lock();
        try
        {
            
            while(m_nRear==m_nSize-1)
            {
                System.out.println(""+Thread.currentThread()+"Deletion await");
                m_deletionwait.await();
            }
            if(++m_nRear<m_nSize)
            {
                m_nQueue[m_nRear]=nVal;
                display();
                m_insertionwait.signalAll();
            }
        }
        finally
        {
            m_queuelock.unlock();
        }
        
    }
    public void dequeue() throws InterruptedException 
    {
        //System.out.println("Dequeue:");
        m_queuelock.lock();
        try
        {
            while(m_nRear<0)
            {
            	System.out.println(""+Thread.currentThread()+"Insertion await");
            	m_insertionwait.await();
            }
            m_nRear=m_nRear-1;
            for(int nLoop=0;nLoop<=m_nRear;nLoop++)
            {
                  m_nQueue[nLoop]=m_nQueue[nLoop+1];
            }
            display();
            m_deletionwait.signalAll();
        }
        finally
        {
            m_queuelock.unlock();
        }
    }
    public void display()
    {
        if(m_nRear>=0)
        {
            for(int nLoop=0;nLoop<=m_nRear;nLoop++)
            {
                System.out.printf("%d -> ", m_nQueue[nLoop]);
            }
            System.out.println("\n");
        }
        else
            System.out.println("Queue Empty");
    }
    private int []m_nQueue;
    private int m_nFront;
    private int m_nRear;
    private int m_nSize;
    private Lock m_queuelock;
    private Condition m_deletionwait;
    private Condition m_insertionwait;
}
