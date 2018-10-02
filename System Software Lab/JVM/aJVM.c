#include"hJVM.h"
main()
{
    char line[50],newline;
    FILE *fp;
    fp = fopen("JCode.txt","r");
    while(!feof(fp))
    {
        fscanf(fp,"%[^\n]%c",line,&newline);
        Token sToken = SepToken(line);

    }
    fclose(fp);

}
