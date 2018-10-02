%{
#include<stdio.h>
int nc=0, nw=0,nl=0,iden=0,n=0;
%}
num [\60-\71]
word [^ \t\n]+
alpha   [\101-\132\141-\172]
lines [\n]
%%
{num}+  {
            n++;
            nc+=yyleng;
            nw++;
        }
{alpha}({alpha}|{num})* {
                    printf("Identifier %s\n",yytext);
					iden++;
					nc+=yyleng;
					nw++;
				}
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
    // 100 200 300 
	FILE *ptr = fopen(argv[1],"r");
	yyin = ptr;
	yylex();
	printf("Number of Lines: %d\n",nl);
	printf("Number of Words: %d\n",nw-nl);	
	printf("Number of Character: %d\n",nc);
	printf("Number of Identifiers: %d\n",iden);
	printf("Number of Constant: %d\n",n);		
}

