#include"hLoader.h"
int main()
{
    unsigned char Load[55];
    char fileName[15];
    int i,Start;
    printf("Enter the File Name to load: ");
    scanf("%s",fileName);
    Start=absLoader(fileName);
    if(Start!=-1)
    {
        printf("\nStarting Address: %04X\n",Start);
    }
    else
        printf("\"Invalid Program Name\"");
}
