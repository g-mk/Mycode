#include"hCount.h"
main()
{
 char *s;
 int c[2]={0,0};
 s=(char*)malloc(30*sizeof(char));
 printf("Enter the String to Count:\n");
 gets(s);
 count(s,c);
 printf("\nTotal No. of Vowels in the string is %d\n",*c);
 printf("Total No. of Consonants in the string is %d\n",*(c+1));
}

