#include<stdio.h>
#include<string.h>
main()
{
 int i,j=1,len;
 char data[50],sdata[50],flag='f',esc='$',ch;
 printf("\nEnter the data: ");
 scanf("%s",data);
 printf("\nEnter the delimiting character: ");
 scanf("\n%c",&ch);
 sdata[0]=flag;
 for(i=0;data[i]!='\0';i++)
 {
  if(data[i]==ch || data[i] == flag)
  {
   sdata[j]=esc;
   j++;
   sdata[j]=data[i];
   j++;
  }
  else
  {
   sdata[j]=data[i];
   j++;
  }
 }
 sdata[j++]=flag;
 sdata[j]='\0';
 printf("\nStuffed Data: %s",sdata);
}
