%{
extern char buffer[10];
%}
%token OPEN CLOSE ID
%left PLUS
%left MUL
%start E
%%
E:	E PLUS T	{printf("+");}
	|
	T	{ }
T:	T MUL F	{printf("*");}
	|
	F	{ }
F:	OPEN E CLOSE	{

		}
	|
	ID	{printf("%s+",buffer);}
%%
yyerror()
{
	printf("Parse Error");
}
