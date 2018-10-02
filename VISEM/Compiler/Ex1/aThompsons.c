#include "hThompsons.h"
int  main(int count,char *argv[])
{
    E* new;
	int i,len;
	char exp[20];
	stack * s = (stack*) malloc(sizeof(stack));
	printf("Enter the Expression in postfix form: ");
	scanf("%s", exp);
	len = strlen(exp);
	initStack(s,len);	
	for(i=0;i<len;i++)
	{
	    if(exp[i]=='.')
	    {
	        E* r2 = pop(s);
            E* r1 = pop(s);
            E* r =andExpression(r1,r2);
            push(s,r);
	    }
	    else if(exp[i]=='|')
	    {
	        E* r2 = pop(s);
            E* r1 = pop(s);
            E* r =orExpression(r1,r2);
            push(s,r);
	    }
	    else 
	    {
	        E *n = (E*)malloc(sizeof(E));
	        init(n,exp[i]);
	        push(s,n);
	    }
	            
	            
	}
	
	if(s->top==0)
	{
	    new = pop(s);
	    printf("\nNumber of States: %d ",new->ns);
	    printf("\nInput Symbols: ");
	    for(i=0;i<new->nip;i++)
	        printf("%c ",new->inputsymbols[i]);
	    printf("\nStart State: %d\n",new->startstate);
	    printf("Final State: %d\n",new->finalstates[0]);
	    printf("\nTransition: \n");
	    for(i=0;i<new->nt;i++)
	    {
	        printf("\n(%d,%c) = %d\n",new->transitions[i].startstate,
	                   new->transitions[i].input,new->transitions[i].endstate);
	    }
	}
	else
	    printf("\nNot a Complete Expression\n");
	
}
