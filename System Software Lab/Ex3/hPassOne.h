#include"hSymbol.h"
typedef struct Token
{
 char label[10];
 char opcode[10];
 char operand1[10];
 char operand2[10];
 int loctr;
}Token;
Token separateToken(char*);
void passOne(FILE*,ht);
int isRegister(char *);
int isOpcode(char*);
void storeSymbolTable(ht );
ht loadSymbolTable();
void displayIntermediate();
