void count(char *s,int *c)
{
 int l,i;
 for(i=0;s[i]!='\0';i++);
 l=i;
 for(i=0;i<l;i++)
 {
  if(s[i]>=65&&s[i]<=90||s[i]>=97&&s[i]<=122)
  {
   switch(s[i])
   {
    case 'a':
    case 'A':
    case 'e':
    case 'E':
    case 'i':
    case 'I':
    case 'o':
    case 'O':
    case 'u':
    case 'U':c[0]++;
             break;
    default: c[1]++;
   }
  }
 }
}

