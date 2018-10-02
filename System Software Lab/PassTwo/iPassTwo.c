#include"hPassTwo.h"
char* packObject(int mCode,char *op1,char* op2,int address,char *addressingMode)
{
    unsigned char fByte=0x0;
    unsigned char sByte = 0X0,tByte=0x0,ftByte=0x0;
    char machineCode[20];
    int reg,flag;
    fByte = fByte | mCode;
    if(!strcmp(addressingMode,"Implied"))
    {
        sprintf(machineCode,"%02X",fByte);
        return machineCode;
    }
    else if(!strcmp(addressingMode,"Register"))
    {
        fByte = fByte >>2;
        fByte = fByte <<2;
        fByte = fByte | 2;
        if(isRegister(op1)>8 || isRegister(op2)>8)
        {
            fByte = fByte | 1;
        }
        sByte = sByte | 3;
        reg = isRegister(op1);
        if(reg>7)
            reg -=8;
        sByte = sByte << 3;
        sByte = sByte | reg;
        reg = isRegister(op2);
        if(reg>7)
            reg -=8;
        sByte = sByte << 3;
        sByte = sByte | reg;
        sprintf(machineCode,"%02X%02X",fByte,sByte);
        return machineCode;

    }
    else
    {
        fByte = fByte >>2;
        fByte = fByte <<2;
        flag = isRegister(op1);
        if(flag!=-2&&flag < 8)
        {
            fByte = fByte | 2;
            sByte = sByte <<5;
            sByte = sByte | flag;
        }
        else if(flag!=-2&&flag >7)
        {
            fByte = fByte | 3;
            sByte = sByte <<5;
            sByte = sByte | (flag - 8);
        }
        else
        {
            flag = isRegister(op2);
            if(flag > 8)
            {
                fByte = fByte | 1;
                sByte = sByte << 5;
                sByte = sByte | (flag - 8);
            }
            else
            {
                sByte = sByte << 5;
                sByte = sByte | (flag);
            }
        }
        sByte = sByte << 3;
        sByte = sByte |6;
        reg = address;
        reg = reg >>8;
        tByte = address;
        ftByte = reg;
        sprintf(machineCode,"%02X%02X%02X%02X",fByte,sByte,tByte,ftByte);
        return machineCode;

    }

}

void passTwo(FILE *In,ht hash,char *fileName)
{
    int firstAddress = 0,mcode,address,code;
    char segName[10],dataSeg[15],codeSeg[10],*check,addressingMode[10];
    char PackedCode[20];
    strcpy(PackedCode,"");
    Token SepToken,StatToken;
    FILE *Record,*Error;
    int FLAG=0;
    List Status;
    Record = fopen("Record.txt","w");
    fread(&SepToken,1,sizeof(struct Token),In);
    createTHEAD(Record,fileName,SepToken.loctr);
    strcpy(segName,"");
    fread(&SepToken,1,sizeof(struct Token),In);
    while(strcmp(SepToken.opcode,"END"))
    {
        if(!strcmp(SepToken.opcode,"SEGMENT"))
        {
            strcpy(segName,SepToken.label);
        }
        else if(!strcmp(SepToken.opcode,"ENDS"))
        {
            strcpy(segName,"");
        }
        else if(!strcmp(SepToken.opcode,"ASSUME"))
        {
            sscanf(SepToken.operand1,"CS:%s",codeSeg);
            sscanf(SepToken.operand2,"DS:%s",dataSeg);
        }
        else if(isOpcode(SepToken.opcode)!=-2)
        {
            if(firstAddress == 0 && !strcmp(segName,codeSeg))
                firstAddress = SepToken.loctr;
            mcode = isOpcode(SepToken.opcode);
            if(!strcmp(SepToken.opcode,"JUMP"))
            {
                Status = searchSymbol(SepToken.operand1,codeSeg,hash);
            }
            if(Status)
            {
                address = Status->m_nAddress;
            }
            else
            {
                Error=fopen("Error.txt","w");
                fprintf(Error,"\nUNDEFINED SYMBOL\n");
                fclose(Error);
                address = 0;
            }
            if(isRegister(SepToken.operand1)!=-2 && isRegister(SepToken.operand2)!=-2)
            {
                strcpy(addressingMode,"Register");
                address =SepToken.loctr;
            }

            else if(searchSymbol(SepToken.operand1,dataSeg,hash)||searchSymbol(SepToken.operand2,dataSeg,hash))
            {
                Status = searchSymbol(SepToken.operand1,dataSeg,hash);
                if (Status)
                {
                    address = Status->m_nAddress;
                }
                else
                {
                    Status = searchSymbol(SepToken.operand2,dataSeg,hash);
                    address = Status->m_nAddress;
                }
                strcpy(addressingMode,"Direct");
            }
            else
            {
                strcpy(addressingMode,"Implied");
                address=SepToken.loctr;
            }
            strcpy(PackedCode,packObject(mcode,SepToken.operand1,SepToken.operand2,address,addressingMode));
            createLEDATA(Record,segName,PackedCode,SepToken.loctr);
        }
        else if(!strcmp(SepToken.opcode,"DW") || !strcmp(SepToken.opcode,"DB") )
        {
            check = strstr(SepToken.operand1,"H");
            if(!strcmp(SepToken.opcode,"DW"))
            {
                if(check)
                {
                    sscanf(SepToken.operand1,"%X",&code);
                }
                else
                    sscanf(SepToken.operand1,"%d",&code);
                    sprintf(PackedCode,"%04X",code);
            }
            else
            {
                if(check)
                {
                    sscanf(SepToken.operand1,"%X",&code);
                }
                else
                    sscanf(SepToken.operand1,"%d",&code);
                    sprintf(PackedCode,"%02X",code);
            }
            address = SepToken.loctr;
            createLEDATA(Record,segName,PackedCode,address);
        }
        fread(&SepToken,1,sizeof(struct Token),In);
    }
    createMODEND(Record,firstAddress);
}


void createTHEAD(FILE * Rec,char *fileName,int address)
{
    int length = strlen(fileName);
    int recordLength = 4+length;
    fprintf(Rec,"80%02X%04X%02X%s\n",recordLength,address,length,fileName);
}

void createLEDATA(FILE* Rec,char * segName,char *PackCode,int address)
{
    int recordLength,segLength,Length;
    Length = strlen(PackCode);
    segLength = strlen(segName);
    recordLength = 4+Length+segLength;
    fprintf(Rec,"A0%02X%02X%s%04X%s\n",recordLength,segLength,segName,address,PackCode);
}

void createMODEND(FILE* Rec,int address)
{
    fprintf(Rec,"8A%04X\n",address);
}


void displayRecord()
{
    char character;
    FILE* Rec = fopen("Record.txt","r");
    character = fgetc(Rec);
    printf("\n*****\t\tMachine Code File\t\t*****");
    char line[50],newline;
    fscanf(Rec,"%s",line);
    while(!feof(Rec))
    {
        printf("\n%s\n",line);
        fscanf(Rec,"%s",line);

    }
}
