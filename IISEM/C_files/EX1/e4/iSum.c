long int sum(char *v[],int n)
{
 int i,sum=0;
for(i=1;i<n;i++)
 {
  sum+=strtol(v[i],0,10);
 }
 return sum;
}

