#include"hFile.h"
main()
{
 FILE *fp1;
 int n;
 long int tot;
 char ip[10];
 printf("Enter the Input File Name:");
 scanf("%s",ip);
 fp1=fopen(ip,"r");
 if(fp1==NULL)
   {
     printf("File Error...");
   }
 fscanf(fp1,"%d",&n);
 printf("Sum of %d Values :\n",n);
 tot=sum(fp1,n);
 printf("\nTOTAL IS :%ld",tot);
 fclose(fp1);
 }


