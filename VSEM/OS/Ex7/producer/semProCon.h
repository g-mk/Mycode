#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MEM 100
#define SEMKEY 2500
#define SHMSIZE 5
#define MUTEX 0
#define FULL 1
#define EMPTY 2
#define LIMIT 10

