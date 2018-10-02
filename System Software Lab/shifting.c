#include<stdio.h>
main()
{

    int x=14,c;
    int y=0,k;
    y=y|x;
    y=y<<1;
    y=y|1;
    int dec=0;
    for (c = 8; c >= 0; c--)
  {

    k = 15 >> c;
    dec = dec<<1;
    if (k & 1)
      {
         dec= dec|1;
      }
  }
  printf("%X",dec);
}
