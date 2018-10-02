#include"hPassTwo.h"
int main()
{
    char FileName[20],Input[20];
    FILE* Inter,*fp;
    ht hash,retrive;
 do
 {
  printf("Enter the Input file name with extension: ");
  scanf("%s",Input);
  fp = fopen(Input,"r");
 }while(!fp);
 hash=initialize();
 passOne(fp,hash);
 storeSymbolTable(hash);
 displayIntermediate();
 retrive=loadSymbolTable();
    do
    {
        printf("Enter the Intermediate File Name: ");
        scanf("%s",FileName);
        Inter=fopen(FileName,"rb");
    }while(Inter==NULL);
    passTwo(Inter,retrive,FileName);
    printf("*****\tMachine code Generated\t*******");
}
