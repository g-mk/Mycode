%{
#include<stdio.h>
extern char *buffer;
%}
%token ID
%left PLUS MINUS
%left MUL DIV
%%
S:  E {printf("\n");}
E:  E PLUS E {printf("+");}
    |   E MUL E {printf("*");}
    |   E MINUS E {printf("-");}
    |   E DIV E {printf("/");}
    |   ID     {printf("%s", buffer);}
    ;
%%

int main(){
    yyparse();
}

int yyerror (char *msg) {
    return printf ("error YACC: %s\n", msg);
}
