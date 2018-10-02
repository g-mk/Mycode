%{
#include<stdio.h>
int nc=0,nw=0,nl=0;
%}
word [^ \t\n]+
lines [\n]
%%
{word}	{
					nw++;
					nc+=yyleng;
				}
{lines} {
          nw++;
          nc+=yyleng;
          nl++;
        }
.	{
		nc++;
	}
%%
main(int argc, char*argv[])
{
	FILE *ptr = fopen(argv[1],"r");
	yyin = ptr;
	yylex();
	printf("Number of Character: %d\n",nc);
	printf("Number of Words: %d\n",nw-nl);
	printf("Number of Lines: %d\n",nl);
}
