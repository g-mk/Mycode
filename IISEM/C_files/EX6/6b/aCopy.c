#include"hCopy.h"
main()
{
 FILE * fp1,*fp2;
 char ip[10],op[20];
 char a;
 int n;
 printf("Enter the Source File Name:");
 scanf("%s",ip);
 printf("Enter the Destination File Name:");
 scanf("%s",op);
 fp1=fopen(ip,"r");
 fp2=fopen(op,"w");
 if(fp1==NULL||fp2==NULL)
   printf("File Error.....");
 printf("Enter the position from where it has to be printed:");
 scanf("%d",&n);
 read(fp1,fp2,n);
 printf("<<<<<File is readed and Counted....>>>>>\n");
 fcloseall();
 fp2=fopen(op,"r+");
 calc(fp2);
 fcloseall();
}
