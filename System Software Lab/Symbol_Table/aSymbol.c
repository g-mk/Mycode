#include"hSymbol.h"
int main()
{
    ht hash;
    hash = initialize();
    Symbol temp;
    List Status;
    int nFlag=0;
    int nChoice,nOption,nStatus;
    do
    {
        do
        {
            printf("\n1.Insert.\n2.Search.\n3.Modify.\n4.Display.\n5.Exit.\nYour Choice: ");
            scanf("%d",&nChoice);
            if(nChoice>5)
                printf("\nInvalid Option\nPlease try Again\n");
        }while(nChoice>5);
        switch(nChoice)
        {
        case 1:
            printf("Enter the Name of the Symbol: ");
            scanf("%s",temp.m_sName);
            printf("Enter the Segment Name of the Symbol: ");
            scanf("%s",temp.m_sSegName);
            printf("Enter the Type of the Symbol: ");
            scanf("%s",temp.m_sType);
            printf("Enter the Address of the Symbol: ");
            scanf("%u",&temp.m_nAddress);
            printf("Enter the Length of the Symbol: ");
            scanf("%u",&temp.m_nLength);
            nStatus=insertSymbol(temp.m_sName,temp.m_sSegName,temp.m_sType,temp.m_nAddress,temp.m_nLength,hash);
            if(nStatus)
            {
                nFlag++;
                printf("\n*************Symbol is Inserted*************\n");
            }
            else
                printf("\n********Symbol is Not Inserted/Duplication********");
            break;
        case 2:
            if(nFlag)
            {
             printf("Enter the Name of the Symbol: ");
             scanf("%s",temp.m_sName);
             printf("Enter the Segment Name of the Symbol: ");
             scanf("%s",temp.m_sSegName);
             nStatus = searchSymbol(temp.m_sName,temp.m_sSegName,hash);
             if(nStatus)
             {
                 printf("\n********Symbol Found in the Symbol Table********\n");
             }
             else
                 printf("\n*******Symbol Not Found in the Symbol Table*****\n");
            }
            else
                printf("\n*****\t\tBucket Empty\t\t*****\n");
             break;
        case 3:
            if(nFlag)
            {
             printf("Enter the Name of the Symbol: ");
             scanf("%s",temp.m_sName);
             printf("Enter the Segment Name of the Symbol: ");
             scanf("%s",temp.m_sSegName);
             Status = searchSymbol(temp.m_sName,temp.m_sSegName,hash);
             if(Status)
              {
                printf("\nSelect the Field to modify\n");
                do
                {
                    printf("\n1.Type.\n2.Length.\n3.Address.\n");
                    scanf("%d",&nOption);
                    if(nOption>3)
                        printf("\nInvalid Option\nPlease try Again\n");
                }while(nOption>3);
               switch(nOption)
               {
                case 1:
                  printf("Enter the Type of the Symbol: ");
                  scanf("%s",temp.m_sType);
                  break;
                case 2:
                  printf("Enter the Length of the Symbol: ");
                  scanf("%u",&temp.m_nLength);
                  break;
                case 3:
                  printf("Enter the Address of the Symbol: ");
                  scanf("%u",&temp.m_nAddress);
                  break;
               }
                int nStatus = modifySymbol(temp,nOption,hash);
                if(nStatus)
                  printf("\n**********Modified**********\n");
              }
             else
                printf("\n*******Symbol Not Exist********\n");
            }
            else
                printf("\n*****\t\tBucket Empty\t\t*****\n");
            break;
        case 4:
            if(nFlag)
             displaySymbol(hash);
            else
                printf("\n*****\t\tBucket Empty\t\t*****\n");
            break;
        case 5:
            printf("\n***********Thank You**********\n");
         }
    }while(nChoice != 5);

//    storeSymbolTable(hash);
}
