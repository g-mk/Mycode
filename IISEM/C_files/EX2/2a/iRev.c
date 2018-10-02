int * irev(int *a,int n)
{
 int i,t;
 for(i=0;i<n/2;i++)
 {
  t=*(a+i);
  *(a+i)=a[n-i-1];
  a[n-i-1]=t;
 }
 return a;
}

char *crev(char * c)
{
 int i,l;
 char t;
 for(i=0;*(c+i)!='\0';i++);
 l=i;
 for(i=0;i<l/2;i++)
  {
   t=*(c+i);
  *(c+i)=*(c+(l-i-1));
  *(c+(l-1-i))=t;
  }
 return c;
}

