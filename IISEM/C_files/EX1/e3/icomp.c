int strc(char a[],char b[])
{
 int i;
  for(i=0;a[i]!='\0'||b[i]!='\0';i++)
  {
   if(a[i]!=b[i])
     goto x;
  }
  return 0;
  x: if(a[i]>b[i])
      return 1;
     else 
      return 2;
}

