%{
#include<stdlib.h>
#include<string.h>
#include<stdio.h>
extern char buffer[10];
char *op1,*op2,*x,*t;
int cnt=0;
struct Stack
{
	char *a[100];
	int top;
};
struct Stack s;
//s.top=-1;
char* pop()
{
	x=s.a[s.top];

	s.a[s.top]="\0";
	s.top--;
	return x;
}
char temp[6]="temp";
char* createNewTemp()
{
	char buf[10];
	cnt++;
	temp[4]=48+cnt;
	temp[5]='\0';
	return temp;
}
void push(char *a)
{
	s.top++;

	s.a[s.top]=(char*)malloc(strlen(a)*sizeof(char));
	strcpy(s.a[s.top],a);	
}

%}
%token ID NEWLINE OPEN CLOSE PLUS MUL INT MINUS DIV
%start LS
%%
LS:	LS L
		|
		L
		;
L:	E NEWLINE	{s.top=-1;}
		|
		NEWLINE
		;
E:	E PLUS T	{t=createNewTemp();op1=pop();op2=pop();printf("\n%s=%s + %s",t,op1,op2);push(t);}
		|
		E MINUS T	{t=createNewTemp();op1=pop();op2=pop();printf("\n%s=%s - %s",t,op1,op2);push(t);}
		|
		T	{}
T:	T MUL F	{t=createNewTemp();op1=pop();op2=pop();printf("\n%s=%s * %s",t,op1,op2);push(t);}
		|
		F	{}
F:	OPEN E CLOSE	{}
		|
		ID	{push(buffer);}
%%
yyerror()
{
	printf("Parse Error\n");
	exit(-1);
}
