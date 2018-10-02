#include"hRev.h"
main()
{
 int a[25],n,i,ch=0;
 char c[30];
// void * r;
 do
 {
 printf("Enter your Choice:\n");
 printf("1) Reverse Integer array\n2) Reversr String.\n3)Exit.\n");
 scanf("%d",&ch);
 if(ch!=3)
  {
   switch(ch)
    {
     case 1:
            printf("Enter the No. of Elements:");
            scanf("%d",&n);
            printf("Enter the values:\n");
            for(i=0;i<n;i++)
              scanf("%d",&a[i]);
            irev(a,n);
            printf("Reversed Array:\n");
            for(i=0;i<n;i++)
              printf("%d\n",a[i]);
            break;
           
     case 2:
            printf("Enter the string:");
            scanf("%s",c);
            crev(c);
            printf("Reversed string:\n");
            printf("%s\n",c);
            break;
    case 3:
           printf("Thank You.....");
    default:
            printf("Invalid Option...\n");
     }
    
  }
 }while(ch!=3);

} 
