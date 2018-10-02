#include<stdio.h>
#include<math.h>
main()
{
 int x1,y1,x2,y2;
 float dist;
 printf("Enter the x-coordinate of first point: ");
 scanf("%d",&x1);
 printf("Enter the y-xoordinate of first point: ");
 scanf("%d",&y1);
 printf("Enter the x-coordinate of second point: ");
 scanf("%d",&x2);
 printf("Enter the y-xoordinate of second  point: ");
 scanf("%d",&y2);
 dist = sqrt( (y2-y1)*(y2-y1) + (x2-x1)*(x2-x1) );
 printf("Distance Between The co-ordinte (%d,%d) and (%d,%d) is %f",x1,y1,x2,y2,dist);
}

 

