#ifndef YYERRCODE
#define YYERRCODE 256
#endif

#define OPENB 257
#define CLOSEB 258
#define NEWLINE 259
#define INTEGER 260
#define REAL 261
#define PLUS 262
#define MINUS 263
#define MUL 264
#define DIV 265
typedef union
{
	int i;
	float dval;
} YYSTYPE;
extern YYSTYPE yylval;
