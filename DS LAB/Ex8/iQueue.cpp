#include"hQueue.h";
CQueue::CQueue()
{
    cqueue_arr = new int [MAX];
    rear = front = -1;
}
void CQueue::Enqueue(int item)
{
    if ((front == 0 && rear == MAX-1) || (front == rear+1))
        {
            return;
        }
    if (front == -1)
        {
            front = 0;
            rear = 0;
        }
    else
        {
            if (rear == MAX - 1)
                rear = 0;
            else
                rear = rear + 1;
        }
    cqueue_arr[rear] = item ;
}
void CQueue::Dequeue()
{
    if (front == -1)
        {
            return ;
        }
    if (front == rear)
        {
            front = -1;
            rear = -1;
        }
    else
        {
            if (front == MAX - 1)
                front = 0;
            else
                front = front + 1;

        }
}
int CQueue::ReturnFront()
{
    if (front == -1)
        return -1;
    else
        return cqueue_arr[front];
}
int CQueue :: isEmpty()
{
    if(front ==-1)
        return 1;
    else
        return 0;
}
