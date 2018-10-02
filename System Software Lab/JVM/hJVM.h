#include<stdio.h>
#include<string.h>
typedef struct Token
{
    char opcode[10];
    char operand[10];
    char operand1[10];
    int oplen;
}Token;
Token SepToken(char line[50]);
