#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
    char name[25];
    strcpy(name,"   MOV AX,BX");
    char label[10],opcode[20],op1[10],op2[10];
    sscanf(name,"%s%s%s,%s",label,opcode,op1,op2);
    printf("Lable:%s\nopcode:%s\nop1:%s\nop2:%s\n",label,opcode,op1,op2);
}
