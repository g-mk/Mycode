#include<stdio.h>
#include<stdlib.h>
#include<string.h>
static int state=0;

typedef struct
{
 char input;
 char startstate;
 char endstate;
}trans;

//All states are represented only as numbers like 0,1,2...
//All inputsymbols are represented as single byte char like a,b,c...

typedef struct
{
 int ns,nt,nip;
 char *states;
 char *inputsymbols;
 char startstate;
 char *finalstates;
 trans *transitions;
}E;

typedef struct 
{
    E** rel;
    int size;
    int top;
}stack;

void initStack(stack* , int);
void init(E *r,char input);
void push(stack *,E*);
E* pop(stack* s);
E* orExpression( E* r1, E* r2);
E* andExpression( E* r1, E* r2);
