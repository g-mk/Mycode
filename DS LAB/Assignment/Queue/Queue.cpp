#include <iostream>
#define MAX 7

using namespace std;
class Circular_Queue

{
    private:
        int *cqueue_arr;
        int front, rear;
    public:
        Circular_Queue();
        void Enqueue(int item);
        void Dequeue();
        void Display();
        int ReturnFront();
        int ReturnRear();
    };
Circular_Queue::Circular_Queue()
{
    cqueue_arr = new int [MAX];
    rear = front = -1;
}
void Circular_Queue::Enqueue(int item)
{
    if ((front == 0 && rear == MAX-1) || (front == rear+1))
        {
            cout<<"\nQueue Overflow \n";
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
void Circular_Queue::Dequeue()
{
    if (front == -1)
        {
            cout<<"\nQueue Underflow\n";
            return ;
        }
    cout<<"\nElement deleted from queue is : "<<cqueue_arr[front]<<endl;
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

void Circular_Queue:: Display()
{
    int front_pos = front, rear_pos = rear;
    if (front == -1)
        {
            cout<<"\nQueue is empty\n";
            return;
        }
    cout<<"\nQueue elements :\n";
    if (front_pos <= rear_pos)
        {
            while (front_pos <= rear_pos)
            {
                cout<<cqueue_arr[front_pos]<<"  ";
                front_pos++;

            }
        }

    else
        {
            while (front_pos <= MAX - 1)
            {
                cout<<cqueue_arr[front_pos]<<"  ";
                front_pos++;
            }
            front_pos = 0;
            while (front_pos <= rear_pos)
                {
                    cout<<cqueue_arr[front_pos]<<"  ";
                    front_pos++;

                }
        }
        cout<<endl;
}
int Circular_Queue::ReturnFront()
{
    if (front == -1)
        return -1;
    else
        return cqueue_arr[front];
}
int Circular_Queue::ReturnRear()
{
    if (front == -1)
        return -1;
    else
    return cqueue_arr[rear];
}
main()
{
    int choice, item;
    Circular_Queue cq;
    do
        {
            cout<<"1.Insert\n";
            cout<<"2.Delete\n";
            cout<<"3.Display\n";
            cout<<"4.Retrive Front\n";
            cout<<"5.Retrive Last\n";
            cout<<"6.Quit\n";
            cout<<"Enter your choice : ";
            cin>>choice;
            switch(choice)
            {
            case 1:
                cout<<"\nInput the element for insertion in queue : ";
                cin>>item;
                cq.Enqueue(item);
                break;
            case 2:
                cq.Dequeue();
                break;
            case 3:
                cq.Display();
                break;
            case 4:
                item=cq.ReturnFront();
                if(item==-1)
                    cout<<"\nEmpty..\n";
                else
                    cout<<"\nFront Element: "<<item<<endl;
                break;
            case 5:
                item=cq.ReturnRear();
                if(item==-1)
                    cout<<"\nEmpty..\n";
                else
                    cout<<"\nRear Element: "<<item<<endl;
                break;
            case 6:
                cout<<"\nThank You....\n";
                break;
            default:
                cout<<"Wrong choice\n";
                }
        }while(choice != 6);
}
