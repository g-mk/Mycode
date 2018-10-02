#include<stdio.h>
#include"y.tab.c"
#include"lex.yy.c"
int main()
{
	yyparse();
	printf("Parse Success");
	return 1;
}
