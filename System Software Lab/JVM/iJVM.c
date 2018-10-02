#include"hJVM.h"
Token SepToken(char line[50])
{
    Token sToken;
    int i=0,j=0;
    while(line[i]!=' '&&line[i]!='\n'&&line[i]!='\0')
    {
        sToken.opcode[j++]=line[i++];
    }
    sToken.opcode[j]='\0';
    j=0;
    printf("%s\n",sToken.opcode);
    if(line[i]!='\n')
    {
        i++;
        while(line[i]!=' '&&line[i]!='\n')
        {
            sToken.operand[j++]=line[i++];
        }
        sToken.operand[j]='\0';
    }
    if(line[i]!='\n')
    {
        i++;
        j=0;
        while(line[i]!='\0'&&line[i]!='\n')
        {
            sToken.operand1[j++]=line[i++];
        }
        sToken.operand1[j]='\0';
    }
    if(!strcmp(sToken.operand," ")&&!strcmp(sToken.operand1," "))
               sToken.oplen=0;
    else if(!strcmp(sToken.operand," ")||!strcmp(sToken.operand1," "))
               sToken.oplen=1;
    else
               sToken.oplen=2;

    return sToken;
}
