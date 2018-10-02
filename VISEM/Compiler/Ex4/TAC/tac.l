%{
	#include<stdio.h>
	#include<string.h>
	#include "y.tab.h"
	char buffer[10];
%}
%%
"\n"	{return NEWLINE;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
"("	{return OPEN;}
")"	{return CLOSE;}
[a-z]+	{
			strcpy(buffer,yytext);
			return ID;
		}
%%
yywrap()
{
	printf("End");
	return 1;
}
