#include<stdio.h>
#include<string.h>
main()
{
 char s[30],f;
 int c,ch,i;
 printf("\t1.To Search a character in the given String.\n");
 printf("\t2.To Find the character at specific Position.\n");
 printf("\t3.To display the Number of occurance of a particular character.\n");
 printf("\t4.To find No. words in the given String.\n");
 printf("\t5.Check whether the string is Palindrome or Not.\n");
 printf("Enter your choice:");
 scanf("%d",&ch);
 switch(ch)
  {
   case 1:{
          printf("Enter the string:");
          scanf("%s",s);
          printf("Enter the character to be searched:");
          scanf(" %c",&f);
          i=0;c=0;
          while(s[i]!='\0')
           {
            if(s[i]==f)
             {
              printf("The Given Character %c is found in the given string at %d Position..\n\n",f,i+1);
              c++;
             }
            i++;
           }
          if(c==0)
           printf("The given character %c is not found in the given string..\n\n",f);           
          break;
          }
   case 2:{
           printf("Enter the string:");
           scanf("%s",s);
           printf("Enter the Position to print the character:");
           scanf("%d",&i);
           if(i<=(strlen(s)))
           {
            printf("The character in the %d position is %c\n\n",i,s[i-1]);
           }
           else
           {
            printf("No Character was found at %d Position\n\n",i);
           }
           break;
          }
   case 3:{
           printf("Enter the string:");
           scanf("%s",s);
           printf("Enter the character which the Occurence is to be found: ");
           scanf(" %c",&f);
           i=0;c=0;
           while(s[i]!='\0')
            {
             if(s[i]==f)
              c++;
             i++;
            }
            printf("The character %c occurs %d Times in the given string..\n\n",f,c);
            break;
           }
    case 4:{
            printf("Enter the statement to count the words:");
            scanf("%c",&f);            
            gets(s);
            i=0;c=1;
            while(s[i]!='\0')
             {
              if(s[i]==32)
               c++;
              i++;
             }
            printf("No. of words in the given statement is %d\n\n",c);
            break;
           }
    case 5:{
            printf("Enter the String in lower case:");
            scanf("%s",s);
            char temp[20],t;
            i=0;int l=strlen(s);
            strcpy(temp,s);
            while(i<l/2)
             {
              t=temp[i];
              temp[i]=temp[l-i-1];
              temp[l-i-1]=t;
              i++;
             }
            if(strcmp(temp,s))
             {
              printf("Given String %s is NOt a Palindrome..\n\n",s);
             }
            else
             {
              printf("Given String %s is Palindrome..\n\n");
             }
            break;
            }
      default: printf("Invalid Option......\n\n");
   }
}
    
