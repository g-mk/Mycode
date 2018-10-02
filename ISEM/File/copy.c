#include<stdio.h>
main()
{
 FILE *fps,*fpt;
 char *ch,value[10];
 fps=fopen("sample.txt","r");
 if(fps==NULL)
  {
  printf("File Missing");
  return 0;
  }
 fpt=fopen("copy.txt","a");
 if(fpt==NULL)
  {
  printf("File Missing");
  return 0;
  }
 do
 {
  ch=fgets(value,10,fps);
  if(ch!=NULL)
   {
    fputs(value,fpt);
   }
 }while(ch!=NULL);
 fcloseall();
}

