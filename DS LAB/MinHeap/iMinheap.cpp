#include"hMinheap.h"
MinHeap :: MinHeap()
{
    m_nCapacity=0;
    m_nHeapsize=-1;
    heap =new Info[1];
}

MinHeap :: MinHeap(int nCap)
{
    m_nCapacity=nCap;
    m_nHeapsize=-1;
    heap = new Info[nCap];
}
MinHeap :: ~MinHeap()
{
    delete []heap;
}
int MinHeap :: Insert (Info info)
{
    if(m_nHeapsize<m_nCapacity-1)
    {
        m_nHeapsize+=1;
        int nCurrent=m_nHeapsize;
        while(nCurrent!=0 && strcmp(heap[nCurrent/2].CommandName,info.CommandName)>0)
        {
            heap[nCurrent]=heap[nCurrent/2];
            nCurrent /=2;
        }
        heap[nCurrent]=info;
        return 1;
    }
    else
        return 0;
}

int MinHeap :: Delete()
{
    if(m_nHeapsize>=0)
    {
        Info LastElement=heap[m_nHeapsize];
        m_nHeapsize-=1;
        int nCurrent=0;
        int nChild=1;
        while(nChild<m_nHeapsize)
        {
            if((nChild<m_nHeapsize) && strcmp(heap[nChild].CommandName,heap[nChild+1].CommandName)>0)
                nChild=nChild+1;
            if(strcmp(LastElement.CommandName,heap[nChild].CommandName)<=0)
                break;
            heap[nCurrent]=heap[nChild];
            nCurrent=nChild;
            nChild*=2;
        }
        heap[nCurrent]=LastElement;
        return 1;
    }
    else
        return 0;
}

int MinHeap :: Display(void (*fpointer)(Info))
{
    if(m_nHeapsize!=-1)
    {
        for(int i=0;i<=m_nHeapsize;i++)
            {
                (*fpointer)(heap[i]);
            }
        return 1;
    }
    else return 0;
}
