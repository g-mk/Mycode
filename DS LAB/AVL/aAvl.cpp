#include"hAvl.h"
int main()
{
 Info Element;
 AVL Tree;
 char cChoice;
 int nChoice;
 do
 {
     int nFlag=0;
     cout<<"\nEnter Your Option:\n";
     cout<<"1)Insert\n2)Traverse\n3)Exit.\nEnter Your Option:";
     cin>>nChoice;
     switch(nChoice)
     {
     case 1:
        cout<<"\nEnter the Details of the Command:\n";
        Element=Tree.GetInfo();
        nFlag=Tree.Insert(Element);
        if(nFlag==1)
            cout<<"\n**********Element Inserted**********\n";
        else
            cout<<"\n**********Element Not Inserted**********\n";
        break;
     case 2:
        cout<<"\n**********Element in the AVL Tree**********\n";
        Tree.Postorder(Tree.GetRoot());
        break;
     case 3:
         cout<<"\n**********Thank You**********\n";
         break;
     default:
        cout<<"\n**********No Such Option Exists**********\n";
     }
 }while(nChoice !=3);
}
