#include"hStock.h"
main()
{
 struct stock *it;
 int n,i,ch=0,l,q,f;
 int c;
 printf("Enter the No. items to be stored:");
 scanf("%d",&n);
 it=(struct stock *)malloc(n*sizeof(struct stock));
// get(it,n);
 printf("Enter the Stocks:");
 for(i=0;i<n;i++)
 {
  printf("Name:");
  scanf("%s",it[i].n);
  printf("ID:");
  scanf("%d",&it[i].id);
  printf("Price:");
  scanf("%f",&it[i].r);
  printf("Quantity:");
  scanf("%d",&it[i].s);
 } 
 while(ch!=5)
 {
 printf("Enter the choice:");
 printf("\n1)Adding Items to the Stock..\n2)Removing Items..\n3)Printing the Details of all items..\n4)Availabilitiy of a particular items..5)Exit..");
 scanf("%d",&ch);
 if(ch!=5)
{
 switch(ch)
 {
  case 1:printf("\n1]To add New Items..\n2]To add quantity..\n");
         scanf("%d",&q);
         n= alloc(it,n,ch,q);
         break;
  case 2:printf("Enter the Id. to Remove:");
         scanf("%d",&c);
         for(i=0;i<n;i++)
           if(it[i].id==c)
            {
             n=remov(it,n,c);
             f=0;
            }
           
           if(f!=0) printf("No items is available in such ID....\n");
         break;
  case 3:print(it,n);
         break;
  case 4:{printf("Enter the Item ID. to check the Availability:");
         scanf("%d",&c);
         printf("Enter the Quantity Needed:");
         scanf("%d",&q);
         l= check(it,c,n,q);
         if(l==1)
           printf("Given Item is available...\n");
         else
           printf("Given items is unavailable\n");
         
         break;}
  default:printf("Invlaid Option\n:");
 }
 }
}
}

