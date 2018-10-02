#include<stdio.h>
#include<string.h>
typedef struct Token
{
  char label[20];
  char opcode[20];
  char operand1[20];
  char operand2[20];
  int loctr;
}Token;
void macroPass(FILE *);
void displayMacro();
Token SeperateTokens(char *);
