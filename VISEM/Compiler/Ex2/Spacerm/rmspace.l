%{
#include<stdio.h>
%}
%%
[\t\n ]	;
.	{
		ECHO;
	}
%%
main(int argc,char*argv[])
{
	FILE *ptr;
	ptr = fopen(argv[1],"r");
	yyin = ptr;
	yylex();
}
