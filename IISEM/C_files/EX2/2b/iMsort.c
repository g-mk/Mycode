int *merge(int *a,int *b,int m,int n)
{
 int c[20],i;
 for(i=0;i<m+n;i++)
 {
  if(i<m)
   c[i]=a[i];
  else 
   c[i]=b[i-m];
 }
 return c;
}
int sort(int *c,int l)
{
 int i,j,k,t;
for(i=0;i<l;i++)
 {
  for(j=i+1;j<l;j++)
  {
   if(c[i]>c[j])
    { t=c[i];
      c[i]=c[j];
      c[j]=t;
    }
  }
 }

for(i=0;i<l;i++)
 {
  for(j=i+1;j<l;j++)
  {
   if(c[i]==c[j])
    {
     for(k=j;k<l;k++)
      {
       c[k]=c[k+1];
      }
      l--;
     }
    }
  }
 for(i=0;i<l;i++)
 {
   printf("\n%d",c[i]);
 }

 return l;
}     
