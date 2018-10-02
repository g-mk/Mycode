#include<stdio.h>
#include<string.h>
struct Loder
{
    unsigned int Address;
    unsigned char code;
};
int absLoader(char *);
int codeExtraction(int*,char*);
unsigned char codeConversion(int val);
void load(int addr,unsigned char code,FILE *);
