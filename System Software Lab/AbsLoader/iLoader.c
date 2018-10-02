#include"hLoader.h"
int absLoader(char * prgName)
{
    FILE * fp = fopen("../PassTwo/Record.txt","r");
    FILE * ot = fopen("LoderFile.txt","w");
    char line[30],newline,rlen[2],sName[10],mCode[10];
    int startAddr,slen,addr,i,FirstExAddr,count=0;
    int val[4];
    char name[20];
    unsigned char AbsCode;
    unsigned char garb;
    fscanf(fp,"%[^\n]%c",line,&newline);
    sscanf(line,"80%2s%4X%2X%s",rlen,&startAddr,&slen,name);
    if(strcmp(name,prgName)==0)
    {
        fscanf(fp,"%[^\n]%c",line,&newline);
        printf("\n-----------\n");
        while(line[0]!='8'&&line[1]!='A')
        {
            sscanf(line,"A0%2s%2d%[A-Z]%4X%s",rlen,&slen,sName,&addr,mCode);
            slen=codeExtraction(&val,mCode);
            for(i=0;i<slen;i++,startAddr++)
            {
                if(startAddr==addr)
                {
                    AbsCode = codeConversion(val[i]);
                    load(addr++,AbsCode,ot);
                }
                else
                {
                    load(startAddr,garb++,ot);
                    i--;
                }

            }
            fscanf(fp,"%[^\n]%c",line,&newline);
        }
        if(line[0]=='8'&&line[1]=='A')
            sscanf(line,"8A%4X",&FirstExAddr);
    }
    else
        return -1;
    fprintf(ot,"\nStarting Address: %04X\n",FirstExAddr);
    fclose(ot);
    fclose(fp);
    return FirstExAddr;
}

int codeExtraction(int * val,char *code)
{
    int len;
    len = strlen(code);
    switch(len/2)
    {
        case 1:
            sscanf(code,"%2X",&val[0]);
            break;
        case 2:
            sscanf(code,"%2X%2X",&val[0],&val[1]);
            break;
        case 4:
            sscanf(code,"%2X%2X%2X%2X",&val[0],&val[1],&val[2],&val[3]);
            break;
    }
    return len/2;
}
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
void load(int addr,unsigned char code,FILE * ot)
{
    static int i =0;
    if(i>9||i==0)
    {
        fprintf(ot,"\n|%X\t",addr);
        printf("\n|%X\t",addr);
        i=0;
    }
    fprintf(ot,"%02X\t",code);
    printf("%02X\t",code);
    i++;
}
