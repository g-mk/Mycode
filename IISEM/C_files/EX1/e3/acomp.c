#include"hComp.h"
main(int argc,char *argv[])
{
 int f;
 f=strc(argv[1],argv[2]);
 if(f==0)
  printf("String is Equal");
 else if(f==1)
  printf("String I is Greater");
 else if(f==2)
  printf("String I is Lesser");
}

