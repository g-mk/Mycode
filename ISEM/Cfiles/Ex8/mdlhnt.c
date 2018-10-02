#include<stdio.h>
main()
{
 int i,j,s[5],maxg=0,maxm=0,temp,c=1,a[5][4],sum;
 printf("Enter the No. of Gold, Silver, Bronze Medal won by the country in order: ");
 for(i=0;i<5;i++)
  {
   sum=0;
   printf("\nEnter the medal list for %d Country",i+1);  //to read and find total medals
   for(j=0;j<3;j++)
    {
     scanf("%d",&a[i][j]);
     sum=sum+a[i][j];
    }
   a[i][3]=sum;
  }
 printf("\tGold\tSilver\tBronze\tTotal\n");  //to display the given data
 for(i=0;i<5;i++)
  { 
   printf("Country %d",i+1);
   for(j=0;j<4;j++)
    {
     printf(" %d\t",a[i][j]);
    }
   printf("\n");
  }

 for(i=0;i<5;i++) //to find the country having more gold and medals
  {
   if(maxg<a[i][0])
    {
     maxg=a[i][0];
    }
   if(a[i][3]>maxm)
    {
     maxm=a[i][3];
    }	
  }
		
  for(i=0;i<5;i++) //taking back up of total
   s[i]=a[i][3];
  for(i=0;i<5;i++) //displaying the max no. gold and medal winning country
   {
     if(maxg==a[i][0])
      {
       printf("\nMaximum No. of Gold Medal(%d) Winners is Country %d",maxg,i+1);
      }
     if(maxm==a[i][3])
      {
       printf("\nCountry who has Maximum No. of medal(%d) is Country %d",maxm,i+1);
      }
   }


 for(i=0;i<5;i++) //sorting back up total
  {
   for(j=i+1;j<5;j++)
    {
     if(s[i]<s[j])
      {
       temp=s[j];
       s[j]=s[i];
       s[i]=temp; 
      }
    }
  }
	
 printf("\nRanking Of the Country Are as Follows..........\n");

 for(i=0;i<5;i++) //to find the rank and to print the country
  { 
   for(j=0;j<5;j++)
    {
     if(s[i]==a[j][3])
      {
       a[j][3]=0;
       printf(" %d Rank in winning the medals is Country %d\n",c,j+1);
      }
    }
  if(s[i]==s[i+1])
   {
    i=i+1;
   }
  c++;
  }
}
