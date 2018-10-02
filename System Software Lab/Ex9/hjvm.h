#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct token
{
 char opcode[25];
 char operand1[25];
 char operand2[25];
 int lc;
}token;
typedef struct token* tokens;
typedef struct bclass
{
 int mn;
 float vn;
 int ps;
 char access[25];
 char tc[25];
 char sc[25];
 int ic;
 char interface[25];
 int fc;
 void *fi;
 int mc;
 unsigned char method[10][25];
 int ac;
 char attribute[25];
}bc;
//typedef struct bclass* bc;
token separateTokens(char* line);
bc binaryClassFormat(bc,char opc[10][20],int);
void loadAndLink(bc,int);
void display(bc);
int processRow(token);

