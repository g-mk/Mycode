#include"hCopy.h"
void read(FILE *s, FILE *d, int n)
{
 int a[3]={0,0,0},i=1;
 char c;
 fseek(s,n,SEEK_SET);
 c=fgetc(s);
 while(c!=EOF)
 {  
   fprintf(d,"%c",c);
   c=fgetc(s);
  }
}
void calc(FILE *d)
{
 int a[3]={0,0,0};
 char o ='0';
 while(o!=EOF)
 { a[0]++;
   o=fgetc(d);
  if(o==32)
    { a[1]++;

    }
   else if(o=='\n')
    { a[2]++;
    }
 }
  printf("\nTotal Character %d\n",a[0]-1);
  printf("Total Words %d\nTotal No. Of Lines %d\n",a[1]+1,a[2]);

}
