#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int head;
    int tail;
    int *p;
    int count;
    int size;

}Queue;


void initialize(Queue *,int );
void enqueue(Queue *,int );
int dequeue(Queue *);
