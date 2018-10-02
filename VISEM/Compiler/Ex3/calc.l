%{
#include<stdio.h>
#include<stdlib.h>
#include"y.tab.h"
%}
%%
[0-9]+	{
		yylval.i = atoi(yytext);
		return INTEGER;
}
[0-9]+[.][0-9]+	{
		yylval.dval = atof(yytext);
		return REAL;
}
"+"	{
		return PLUS;
}
"-" {
		return MINUS;
}
"*"	{
		return MUL;
}
"/"	{
		return DIV;
}
"("	{
		return OPENB;
}
")"	{
		return CLOSEB;
}
"\n"	{
		return NEWLINE;
}
%%
