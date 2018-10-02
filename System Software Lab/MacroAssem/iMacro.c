#include"hMacro.h"
void macroPass(FILE* In)
{
  char macDef[20][50],line[50],newline,macName[15];
  Token sepToken;
  int count=0;
  FILE* macro;
  macro = fopen("FULLMASM.txt","w");
  do
  {
      fscanf(In,"%[^\n]%c",line,&newline);
      sepToken= SeperateTokens(line);
        if(strcmp(sepToken.opcode,"MACRO")==0)
        {
            strcpy(macName,sepToken.label);
            while(strcmp(sepToken.opcode,"ENDM")!=0)
            {
                fscanf(In,"%[^\n]%c",macDef[count],&newline);
                sepToken = SeperateTokens(macDef[count]);
                count++;
            }
        }
        else if(strcmp(sepToken.opcode,macName)==0)
        {
            int i=0;
            while(i<count-1)
            {
                fprintf(macro,"%s\n",macDef[i]);
                i++;
            }
        }
        else
        {
            fprintf(macro,"%s\n",line);
        }
   }while(!feof(In)&& strcmp(sepToken.opcode,"END"));
  fclose(macro);
}

Token SeperateTokens(char *line)
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


void displayMacro()
{
    char line[30],nl;
    FILE* macro;
    macro = fopen("FULLMASM.txt","r");

    while(!feof(macro))
    {
        fscanf(macro,"%[^\n]%c",line,&nl);
        printf("%s\n",line);
    }
    fclose(macro);
}
