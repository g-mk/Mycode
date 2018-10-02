#include<stdio.h>
main()
{
  FILE *fp=fopen("name1.txt","r+");
  char c=fgetc(fp);
  while(c!=EOF)
  {
   printf("%c",c);
   fgetc(fp);
  }
  fclose(fp);
}
