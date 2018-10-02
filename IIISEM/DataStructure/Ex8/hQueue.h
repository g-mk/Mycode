#include <iostream>
#define MAX 7

using namespace std;
class CQueue
{
    private:
        int *cqueue_arr;
        int front, rear;
    public:
        CQueue();
        void Enqueue(int item);
        void Dequeue();
        int isEmpty();
        int ReturnFront();
};
