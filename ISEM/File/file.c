#include<stdio.h>
main()
{
 FILE *fp;
 int ch;
 fp=fopen("sample.txt","a+");
 if(fp==NULL)
  {
  printf("File Missing");
  return 0;
  }
 ch=fgetc(fp);
 while(ch!=EOF)
  {
   printf("%c",ch);
   ch=fgetc(fp);
  }
  fputs("Work Has Been Finished",fp);
 
  fclose(fp);
}

