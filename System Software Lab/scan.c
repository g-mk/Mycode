#include<stdio.h>
unsigned char codeConversion(int val)
{
    unsigned char code = 0x0;
    int digit;
    digit = val % 0x10;
    val = val /0x10;
    code = code | val;
    code <<= 4;
    code = code | digit;
    return code;


}

main()
{
   char name[50];
   int num=0xA5,i;
   unsigned char val=0x0;
       printf("%X",codeConversion(num));
}
