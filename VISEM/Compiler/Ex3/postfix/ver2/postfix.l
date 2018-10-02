%{
#include<string.h>
#include"y.tab.h"
char buffer[10];
%}
%%
[a-z]+  {strcpy(buffer,yytext); return ID;}
"+"	{return PLUS;}
"-"	{return MINUS;}
"*"	{return MUL;}
"/"	{return DIV;}
%%

int yywrap(){
    return 1;
}
