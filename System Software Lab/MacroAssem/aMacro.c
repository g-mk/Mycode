#include"hMacro.h"
int main()
{
    FILE* IN;
    char fileName[20];
    do
    {
        printf("Enter the Macro File Name: ");
        scanf("%s",fileName);
        IN = fopen(fileName,"r");
    }while(!IN);
    printf("File Opened\n");
    macroPass(IN);
    printf("Procesed\n");
    displayMacro();
    return 0;
  }

