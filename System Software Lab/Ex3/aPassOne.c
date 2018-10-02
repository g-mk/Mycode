#include"hPassOne.h"
main()
{
 ht hash;
 ht retrive;
 FILE *fp;
 char Input[10];
 do
 {
  printf("Enter the Input file name with extension: ");
  scanf("%s",Input);
  fp = fopen(Input,"r");
 }while(!fp);
 printf("File Opened\n");
 hash=initialize();
 passOne(fp,hash);
 storeSymbolTable(hash);
 retrive=loadSymbolTable();
 displaySymbol(retrive);
 displayIntermediate();
 fclose(fp);
}
