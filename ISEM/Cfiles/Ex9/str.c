#include<stdio.h>
#include<ctype.h>
#include<string.h>
main()
{
 char s[20];
 int up=0,lw=0,al=0,v=0,d=0;
 int i=0;
 printf("Enter the string ");
 gets(s);
 while(s[i]!='\0')
  {
   if(isalnum(s[i]))
    {
     if(isalpha(s[i]))
      {
       al++;
       if(isupper(s[i]))
        {
         up++;
        }
       else 
        lw++;
       if(s[i]=='a'||s[i]=='A'||s[i]=='e'||s[i]=='E'||s[i]=='i'||
            s[i]=='I'||s[i]=='o'||s[i]=='O'||s[i]=='U'||s[i]=='u')
        {
         v++;
        }
     
     }
   if(isdigit(s[i]))
    d++;
  }
  i++;
}
 printf("No.of alphabets: %d ",al);
 printf("\nNo. Vowels: %d",v);
 printf("\nNo. of Upper Case Letter: %d",up);
 printf("\nNo. of Lower Case Letter: %d",lw);
 printf("\nNo. of Numeric Numbers: %d\n\n",d);

}

