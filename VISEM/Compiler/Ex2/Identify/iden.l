%{
#include<stdio.h>
%}
num [\60-\71]
alpha   [\101-\132\141-\172]
%%
{num}+  {
            if(yyleng==3)
              printf("%s is a 3 Digit Number\n",yytext);
            else
              printf("%s not a 3 Digit Number\n",yytext);
        }
{num}+{alpha}*  {
            printf("%s is Invalid Identifier\n",yytext);
}

({alpha}|_)+({alpha}|{num}|_)* {
					printf("%s is Identifier\n",yytext);
				}
.  {
		printf("%s is invalid\n",yytext);
	}

%%
main(int argc,char*argv[])
{
	FILE *ptr = fopen(argv[1],"r");
	yyin = ptr;
	yylex();
	fclose(ptr);
}
