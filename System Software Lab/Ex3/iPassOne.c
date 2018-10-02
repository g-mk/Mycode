#include"hPassOne.h"
char Reg[20][3]={"AL","CL","DL","BL","AH","CH","DH","BH","AX","CX","DX","BX","SP","BP","SI","DI","DS","ES","CS","SS"};
Token separateToken(char *line )
{
 Token parse;
 int i,j;
 i=0;
 j=0;
 if(line[i]!=' ')
 {
  for(;line[i]!=' ';i++)
  {
   parse.label[j]=line[i];
   j++;
  }
   parse.label[j]='\0';
 }
 else
  strcpy(parse.label,"");
 i++;
 for(j=0;line[i]!=' '&&line[i]!='\0';i++)
 {
  parse.opcode[j]=line[i];
  j++;
 }
 parse.opcode[j]='\0';
 if(line[i]!='\0')
 {
  i++;
  for(j=0;line[i]!=','&&line[i]!='\0';i++)
  {
   parse.operand1[j]=line[i];
   j++;
  }
  parse.operand1[j]='\0';
 }
 else
  strcpy(parse.operand1,"");
 if(line[i]==',' && line[i]!='\0')
 {
  i++;
  for(j=0;line[i]!='\0';i++)
  {
   parse.operand2[j]=line[i];
   j++;
  }
  parse.operand2[j]='\0';
 }
 else
  strcpy(parse.operand2,"");
 return parse;
}

void passOne(FILE *Input,ht hashtable)
{
 Token sepToken;
 int Length=1;
 List symStats;
 int Loctr=0;
 char* check=NULL;
 FILE *Error,*Inter;
 Inter=fopen("../PassTwo/Inter.txt","wb");
 Error = fopen("Error.txt","w");
 char segName[10],newline;
 char line[50];
 strcpy(segName,"");
 fscanf(Input,"%[^\n]%c",line,&newline);
 sepToken = separateToken(line);
 if(!strcmp(sepToken.opcode,"ORG"))
  {
   check = strstr(sepToken.operand1,"H");
   if(check)
   {
       sscanf(sepToken.operand1,"%X",&Loctr);
   }
   else
     sscanf(sepToken.operand1,"%d",&Loctr);
     sepToken.loctr=Loctr;
   fwrite(&sepToken,1,sizeof(sepToken),Inter);
   fscanf(Input,"%[^\n]%c",line,&newline);
   sepToken=separateToken(line);
  }
 while(strcmp(sepToken.opcode,"END"))
  {
    if(!strcmp(sepToken.opcode,"ORG"))
        {
            check = strstr(sepToken.operand1,"H");
            if(check)
            {
                sscanf(sepToken.operand1,"%X",&Loctr);
            }
            else
                sscanf(sepToken.operand2,"%d",&Loctr);
                sepToken.loctr=Loctr;
            fwrite(&sepToken,1,sizeof(sepToken),Inter);
            fscanf(Input,"%[^\n]%c",line,&newline);
            sepToken=separateToken(line);

        }

    if(strcmp(sepToken.label,"-")&&!strcmp(sepToken.opcode,"SEGMENT"))
    {

     insertSymbol(sepToken.label,sepToken.label,"SEGMENT",Loctr,0,hashtable);
     sepToken.loctr =Loctr;
     strcpy(segName,sepToken.label);
     strcpy(sepToken.operand1,"-");
     strcpy(sepToken.operand2,"-");
    }
   else if(strcmp(sepToken.label,"-")!=0&&!strcmp(sepToken.opcode,"ENDS"))
   {
    strcpy(segName,"");
    sepToken.loctr=Loctr;
    strcpy(sepToken.operand1,"-");
    strcpy(sepToken.operand2,"-");
    }
   else if(strcmp(sepToken.label,"-")!=0 || isOpcode(sepToken.opcode)!=-2)
   {
       if(strcmp(segName,"")!=0)
       {
           symStats=searchSymbol(sepToken.label,segName,hashtable);
           if(symStats)
           {
               fprintf(Error,"\nDuplicate Symbol Definition\n");
           }
           else
           {
               if(strcmp(sepToken.opcode,"DW")==0||strcmp(sepToken.opcode,"DB")==0)
               {
                   if(strcmp(sepToken.opcode,"DB")==0)
                   {
                       insertSymbol(sepToken.label,segName,"BYTE",Loctr,1,hashtable);
                       Loctr+=1;
                   }
                   else
                   {
                       insertSymbol(sepToken.label,segName,"WORD",Loctr,2,hashtable);
                       Loctr+=2;
                   }
                }
            }
        }
        else
            fprintf(Error,"\nDefinition outside the Segment\n");
        if(isOpcode(sepToken.opcode)!=-2)
        {
            if(strcmp(sepToken.label,"")!=0&&strcmp(sepToken.label," ")!=0&&strcmp(sepToken.label,"-")!=0)
                {
                    insertSymbol(sepToken.label,segName,"NEAR",Loctr,2,hashtable);
                }

            if(searchSymbol(sepToken.operand1,"CODE",hashtable)!= NULL||searchSymbol(sepToken.operand1,"DATA",hashtable)!= NULL|| searchSymbol(sepToken.operand2,"DATA",hashtable)!=NULL)
                Length=4;
            else if(isRegister(sepToken.operand1)>0 && isRegister(sepToken.operand2)>0)
                Length=2;
            else if(strcmp(sepToken.opcode,"JUMP")==0)
                Length = 3;
            else
                {
                    strcpy(sepToken.operand1,"-");
                    strcpy(sepToken.operand2,"-");
                    Length = 1;
                }

            Loctr+=Length;

        }
    }
        if(strcmp(segName,"")|| !strcmp(sepToken.opcode,"ENDS"))
        {
            fwrite(&sepToken,1,sizeof(sepToken),Inter);
        }
       fscanf(Input,"%[^\n]%c",line,&newline);
       sepToken=separateToken(line);
       sepToken.loctr=Loctr;
   }
   sepToken.loctr=Loctr;
   strcpy(sepToken.operand1,"-");
   strcpy(sepToken.operand2,"-");
   fwrite(&sepToken,1,sizeof(sepToken),Inter);
   fclose(Inter);
  }

  int isRegister(char* reg)
  {
      int i;
      for(i=0;i<20;i++)
      {
          if(strcmp(Reg[i],reg)==0)
            return i;
      }
      return -2;
  }

  int isOpcode(char* opcode)
  {
      char mNemonic[5];
      int mCode=-2;
      FILE *OPTAB;
      OPTAB=fopen("Optable.txt","r");
      fscanf(OPTAB,"%s\t%X\n",mNemonic,&mCode);
      while(!feof(OPTAB))
      {
          if(strcmp(opcode,mNemonic)==0)
            return mCode;
          fscanf(OPTAB,"%s\t%X\n",mNemonic,&mCode);
      }
      return -2;
      fclose(OPTAB);
  }

void storeSymbolTable(ht hash)
 {
     FILE *symTab;
     symTab = fopen("../PassTwo/SymbolTable.txt","wb");
     fwrite(hash,1,sizeof(struct Hashtable),symTab);
     fclose(symTab);

 }

 ht loadSymbolTable()
 {
     ht hash= initialize();
     FILE *symTab;
     symTab = fopen("../PassTwo/SymbolTable.txt","rb");
     fread(hash,1,sizeof(struct Hashtable),symTab);
     fclose(symTab);
     return hash;

 }

  void displayIntermediate()
 {
     FILE *Inter;
     Token sep;
     Inter = fopen("../PassTwo/Inter.txt","rb");
     fread(&sep,1,sizeof(struct Token),Inter);
     while(!feof(Inter))
     {
         printf("\n%X\t%s\t%s\t%s\t%s\n",sep.loctr,sep.label,sep.opcode,sep.operand1,sep.operand2);
         fread(&sep,1,sizeof(Token),Inter);
     }
     fclose(Inter);
 }
