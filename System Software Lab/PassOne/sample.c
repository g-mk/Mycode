#include<stdio.h>
char Register[16][3]={"AL","CL","DL","BL","AH","CH","DH","BH","AX","CX","DX","BX","SP","BP","SI","DI"};

int isRegister(char* reg)
  {
      int i;
      for(i=0;i<16;i++)
      {
          if(!strcmp(Register[i],reg))
            return i;
      }
      return -2;
  }

  main()
  {
  }
