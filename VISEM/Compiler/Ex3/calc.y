%{
#include<stdio.h>
#include<stdlib.h>
%}
%union
{
	int i;
	float dval;
}
%token OPENB CLOSEB NEWLINE
%token <i> INTEGER
%token <dval> REAL
%left PLUS MINUS
%left MUL DIV
%type <dval> E
%%
S:	E NEWLINE	{
	printf("The Value of Expression is %f\n", $1);
	exit(0);
	}
E:	E PLUS E	{
	$$ = $1 + $3;
	}
	| E MINUS E {
  $$ = $1 - $3;
  }
  |	E MUL E	{
  $$ = $1 * $3;
	}
	| E DIV E
	{
	if($3!=0)
		$$ = $1 / $3;
	else
	{
		yyerror("Divide by Zeor Error");
		exit(0);
	}
	}
	|	OPENB E CLOSEB 
	{
	$$ = $2;
	}
	|	INTEGER
	{
	$$ = $1;
	}
	| REAL 
	{
	$$ = $1;
	}

%%

int main()
{
	yyparse();
}
void yyerror (char const *s)
{
  fprintf (stderr, "%s\n", s);
}

