#include<stdio.h>
#include<string.h>
main()
{
    int a = 3;
    char val = 0X03;
    printf("%02X",val);
    val = val << 3 ;
    printf("%02X",val);
}
