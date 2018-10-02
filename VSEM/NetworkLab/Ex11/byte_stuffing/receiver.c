#include<stdio.h>
#include<string.h>
main()
{
 int i,j=0,len;
 char data[50],sdata[50],flag='f',esc='$',ch;
 printf("\nEnter the data: ");
 scanf("%s",data);
 printf("\nEnter the delimiting character: ");
 scanf("\n%c",&ch);
 len=strlen(data);
 for(i=1;i<len-1;i++)
 {
  if((data[i]==esc && data[i+1]==ch) || (data[i] == esc && data[i+1]==flag))
  {
   sdata[j]=data[i+1];
   j++;
   i++;
  }
  else
  {
   sdata[j]=data[i];
   j++;
  }
 }
 sdata[j]='\0';
 printf("\nStuffed Data: %s",sdata);
}
