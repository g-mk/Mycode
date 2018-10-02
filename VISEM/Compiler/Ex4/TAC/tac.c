#include<stdio.h>
#include"y.tab.c"
#include"lex.yy.c"
int main()
{
	yyparse();
	printf("\nParse Success\n");
	return 1;
}
