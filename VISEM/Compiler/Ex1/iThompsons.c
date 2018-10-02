#include "hThompsons.h"
void initStack(stack* s, int n)
{
    s->size=n;
    s->top=-1;
    s->rel = (E**)malloc(n*sizeof(E*));
}
void push(stack* s,E* r)
{
    if(s->top<s->size)
        s->rel[++s->top] = r;
}

E* pop(stack* s)
{
    if(s->top>=0)
        return s->rel[s->top--];
}
void init(E *r,char input)
{
  int i;
  r->ns=2;
  r->nt=1;
  r->nip=1;    
  r->states = (char*)malloc(r->ns*sizeof(char));
  for(i=0;i<r->ns;i++)
    r->states[i]=state++;
  r->inputsymbols = (char*)malloc(sizeof(char));
  r->inputsymbols[0]=input;
  r->startstate = r->states[0];
  r->finalstates = (char*)malloc(sizeof(char));
  r->finalstates[0]=r->states[1];
  r->transitions = (trans *) malloc(sizeof(trans));
  r->transitions->input=input;
  r->transitions->startstate = r->startstate;
  r->transitions->endstate = r->finalstates[0];
}

E* orExpression(E* r1, E* r2)
{
    E *r = (E *)malloc(sizeof(E));
    int i;
    r->ns= r1->ns + r2->ns + 2;
    r->nt = r1->nt + r2->nt + 4;
    r->nip = r1->nip + r2->nip;

    r->states = (char*)malloc(r->ns*sizeof(char));
    memcpy(r->states,r1->states,r1->ns);
    memcpy(&r->states[r1->ns],r2->states,r2->ns);

    r->startstate = state++;
    r->finalstates = (char*)malloc(sizeof(char));
    r->finalstates[0]=state++;

    r->states[r1->ns+r2->ns] = r->startstate;
    r->states[r1->ns+r2->ns+1] = r->finalstates[0];

    r->transitions = (trans *) malloc(r->nt*sizeof(trans));
    memcpy(r->transitions,r1->transitions,sizeof(trans)*r1->nt);
    memcpy(&r->transitions[r1->nt],r2->transitions,sizeof(trans)*r2->nt);
    
    i=r1->nt+r2->nt;
        
        r->transitions[i].input = 'e';
        r->transitions[i].startstate = r->startstate;
        r->transitions[i].endstate = r1->startstate;
    
    i++;
    
        r->transitions[i].input = 'e';
        r->transitions[i].startstate = r->startstate;
        r->transitions[i].endstate = r2->startstate;

    i++;
     
        r->transitions[i].input = 'e';
        r->transitions[i].startstate = r1->finalstates[0];
        r->transitions[i].endstate = r->finalstates[0];
    
    i++;
    
        r->transitions[i].input = 'e';
        r->transitions[i].startstate = r2->finalstates[0];
        r->transitions[i].endstate = r->finalstates[0];
        
    r->inputsymbols = (char*)malloc(r->nip*sizeof(char));    
    memcpy(r->inputsymbols,r1->inputsymbols,r1->nip);
    memcpy(&r->inputsymbols[r1->nip],r2->inputsymbols,r2->nip);    
    return r;
    
}

E* andExpression( E* r1, E* r2)
{
    E *r = (E *)malloc(sizeof(E));
    int i;
    r->ns= r1->ns + r2->ns;
    r->nt = r1->nt + r2->nt + 1;
    r->nip = r1->nip + r2->nip;

    r->states = (char*)malloc(r->ns*sizeof(char));
    memcpy(r->states,r1->states,r1->ns);
    memcpy(&r->states[r1->ns],r2->states,r2->ns);

    r->startstate = r1->startstate;
    r->finalstates = (char*)malloc(sizeof(char));
    r->finalstates[0]=r2->finalstates[0];

    r->transitions = (trans *) malloc(r->nt*sizeof(trans));
    memcpy(r->transitions,r1->transitions,sizeof(trans)*r1->nt);
    memcpy(&r->transitions[r1->nt],r2->transitions,sizeof(trans)*r2->nt);
    
    i=r1->nt+r2->nt;
        
        r->transitions[i].input = 'e';
        r->transitions[i].startstate = r1->finalstates[0];
        r->transitions[i].endstate = r2->startstate;
      
    r->inputsymbols = (char*)malloc(r->nip*sizeof(char));    
    memcpy(r->inputsymbols,r1->inputsymbols,r1->nip);
    memcpy(&r->inputsymbols[r1->nip],r2->inputsymbols,r2->nip);    
    
    return r;


}
