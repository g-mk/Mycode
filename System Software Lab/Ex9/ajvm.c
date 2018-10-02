#include"hjvm.h"
main()
{
 int lc=0;
 char line[50];
 char error[50];
 int e;
 bc b,d;
 int n=1;
 FILE *ip,*op;
 char new;
 ip=fopen("input.txt","r");
 op=fopen("output.txt","w");
 token t;
 printf("\nlocation\topcode\t\toperand1\toperand2\n");
 fscanf(ip,"%[^\n]%c",line,&new);
 char opcode[10][20];
 int k=0;
 while(!feof(ip))
 {
  t=separateTokens(line);
  strcpy(opcode[k],t.opcode);
  k++;
  e=processRow(t);
  if(e!=-1)
  {
   if(e==0&&(strcmp(t.operand1,"")==0)&&(strcmp(t.operand2,"")==0))
    {
      t.lc=lc;
      lc=lc+1;
      strcpy(t.operand1,"---");
      strcpy(t.operand2,"---");
      strcpy(error,"");
    
   }
   else if(e==1&&(strcmp(t.operand1,"")!=0)&&(strcmp(t.operand2,"")==0))
   {
    t.lc=lc;
    lc=lc+3;
    strcpy(t.operand2,"---");
    strcpy(error,"");
   }
   else if(e==2&&(strcmp(t.operand1,"")!=0)&&(strcmp(t.operand2,"")!=0))
   {
    t.lc=lc;
    lc=lc+5;
      strcpy(error,"");
   }
   else
   {
    strcpy(error,"Invalid no of operands"); 
   }
  }
  else
  {
    strcpy(error,"Invalid opcode");
  }
  if(strcmp(error,"")!=0)
  {
   printf("lcccccc:\n%d",lc);
   printf("error:..%s\n",error);
  }
  else
  {
   fprintf(op,"%d\t%s\t%s\t%s\n",t.lc,t.opcode,t.operand1,t.operand2);
   printf("%d\t\t%s\t\t%s\t\t%s\n",t.lc,t.opcode,t.operand1,t.operand2);
  }
  fscanf(ip,"%[^\n]%c",line,&new);
  n++;
 }
 fclose(op);
/* FILE *dp;
 dp=fopen("output.txt","r");
 printf("\nlocation\topcode\toperand1\toperand2");
 fread(&t,sizeof(token),1,dp);
 while(!feof(op))
 {
  printf("\n%d\t%s\t%s\t%s",t.lc,t.opcode,t.operand1,t.operand2);
  fread(&t,sizeof(token),1,dp);
 }*/
 printf("\n******************************************\n");
 printf("\tThe binary Class");
 printf("\n******************************************\n");
 b=binaryClassFormat(d,opcode,k);
 display(b);
 loadAndLink(b,(n-1));
 fclose(op);
}

