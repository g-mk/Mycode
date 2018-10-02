#include "hQueue.h"

void initialize(Queue * pros,int size)
{
    pros->head = -1;
    pros->tail = -1;
    pros->p = (int*) malloc(size*sizeof(int));
    pros->count = 0;
    pros->size = size;
}

void enqueue(Queue *pros,int val)
{
    int i;
    if(pros->count<pros->size)
    {
        pros->tail = (pros->tail+1)%pros->size;
      
        pros->p[pros->tail]=val;
        pros->count++;
    }
}

int dequeue(Queue* pros)
{
    int i;
    if(pros->count!=0)
    {
        pros->head = (pros->head+1)%pros->size;
        pros->count--;
        return pros->p[pros->head];
    }
    
}
