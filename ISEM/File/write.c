#include<stdio.h>
main()
{
 FILE *fp;
 char c[50];
 fp=fopen("New.txt","w+");
 if(fp==NULL)
 {
  printf("Process Cannot Be Proceed");
  return 0;
 }
 printf("Enter the Data to store in File: ");
 fflush(stdin);
 scanf("%[^*]",c);
 printf("The string is \n %s\n",c);
	fputs(c,fp);

 fclose(fp);
}

