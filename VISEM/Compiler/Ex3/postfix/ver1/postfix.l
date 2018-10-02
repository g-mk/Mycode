%{
#include<stdio.h>
#include<string.h>
#include "y.tab.h"
char buffer[10];
%}
%%
[a-z]+	{strcpy(buffer,yytext);return ID;}
"+"	{return PLUS;}
"*"	{return MUL;}
"("	{return OPEN;}
")"	{return CLOSE;}
%%
int yywrap()
{
	return 1;
}
