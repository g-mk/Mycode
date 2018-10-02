#include"hjvm.h"
token separateTokens(char* line)
{
 token l;
 int i=0,k=0;
 strcpy(l.opcode,"");
 strcpy(l.operand1,"");
 strcpy(l.operand2,"");
 while(line[i]!='\0' && line[i]!='\n' && line[i]!=' ')
 {
  l.opcode[k]=line[i];
  k++;
  i++;
  l.opcode[k]='\0';
 }
 if(line[i]==' ')
 {
  i=i+1;
 }
 k=0;
 while(line[i]!=' '&& line[i]!='\n')
 {
   l.operand1[k]=line[i];
   k++;
   i++;
  // l.operand1[k]='\0';
 }
 if(k!=0)
 l.operand1[k]='\0';
 else
 strcpy(l.operand1,"");
 k=0;
 //i++;
 while(line[i]!=' '&&line[i]!='\n')
 {
   l.operand2[k]=line[i];
   k++;
   i++;
  // l.operand2[k]='\0';
 }
 if(k!=0)
   l.operand2[k]='\0';
 else
 strcpy(l.operand2,"");
 return l;
}
int processRow(token t)
{
 FILE *op;
 op=fopen("opcode.txt","r");
 int nop;
 char opc[20],new,mc[10];
 fscanf(op,"%s\t%d\t%s%c",opc,&nop,mc,&new);
 while(!feof(op))
 {
  if(strcmp(t.opcode,opc)==0)
  {
   return nop;
  }
  fscanf(op,"%s\t%d\t%s%c",opc,&nop,mc,&new);
 }
   return -1;
}
bc binaryClassFormat(bc b,char opco[10][20],int k)
{
 b.mn=12;
 b.vn=1.0;
 b.ps=4;
 strcpy(b.access,"default");
 strcpy(b.tc,"binaryClass");
 strcpy(b.sc,"object");
 b.ic=0;
 strcpy(b.interface,"");
 b.fc=3;
 b.fi=(void*)malloc((b.fc+1)*sizeof(double));
 b.mc=1;
 int i=0,nop,s;
 char opc[12],new;
 char met[10];
 for(s=0;s<k;s++)
 {
   FILE *op;
   op=fopen("opcode.txt","r");
   fscanf(op,"%s\t%d\t%s%c",opc,&nop,met,&new);
   while(!feof(op))
   {
    if(strcmp(opco[s],opc)==0)
    {
     strcpy(b.method[i],met);
    // printf("%s\n",b.method[i]);
     i++;
     break;
   }
   fscanf(op,"%s\t%d\t%s%c",opc,&nop,met,&new);
  }
  fclose(op);
 }
 b.ac=13;
 strcpy(b.attribute,"");
 return b;
}
void display(bc b)
{
 printf("Magic Number:%d\nVersion Number:%f\nPool Size:%d\nAccess:%s\nThis class:%s\nSuperClass:%s\nInterface Count:%d\nFieldCount:%d\nMethodCount:%d\nAttributeCount:%d\n",b.mn,b.vn,b.ps,b.access,b.tc,b.sc,b.ic,b.fc,b.mc,b.ac);
}
void loadAndLink(bc b,int n)
{
 printf("\n********************************************\n");
 printf("\tLoading.......");
 printf("\n********************************************\n");
 double stack[50];
 int sp=0,i=0;
 char opc[20],new;
 int nop;
 unsigned char mc[2];
 int j;
 for(j=0;j<6;j++)
 {
  if(strcmp(b.method[j],"6A")==0)
  {
   printf("\nEnter the Number of type double\n");
   scanf("%lf",&stack[sp]);
   *((double*)b.fi+i)=stack[sp];
   i++;
   sp++;
  }
  else if(strcmp(b.method[j],"6B")==0)
  {
    double a,b,c;
    sp--;
    a=stack[sp];
    sp--;
    b=stack[sp];
    printf("\n*************************************\n");
    printf("FirstValue:%lf\nSecondValue:%lf\n",a,b);
    c=a+b;
    stack[sp]=c;
    sp++;
    printf("\n*************************************\n");
    printf("The output is:%lf",c);
    printf("\n*************************************\n");
  }
  else if(strcmp(b.method[j],"6C")==0)
  {
    exit(0);
  }
 }
}

