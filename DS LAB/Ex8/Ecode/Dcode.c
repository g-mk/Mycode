#include<stdio.h>
char dcode(int val,int key)
{
    return val - 4*key;
}

int main()
{
    FILE *fp;
    FILE *dp;
    char sFile[20],c;
    int key;
    do
    {
        printf("Enter the File Name(.txt) for Input :");
        scanf("%s",sFile);
        fp=fopen(sFile,"r+");
    }while(fp==NULL);
    fscanf(fp,"%d",&key);
    printf("%d",key);
    dp=fopen("Recycle.txt","w");
    while(!feof(fp))
    {
        c=dcode(fgetc(fp),key);
        printf("%c",c);
        fputc(c,dp);
    }
    fclose(fp);
    fclose(dp);
}
