#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ARRIVAL 1
#define JOB 2
#define PRIORITY 4
#define RR 5

typedef struct {
    int id;
    int burst;
    int arrival;
    int priority;
    int stat;
    int rem;
    int waiting;
    int tround;
}process;

