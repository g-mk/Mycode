#include"hListarray.h"
main()
{
 int n,p,element,ch=1;
 cout<<"Enter the Maximum No. Of Elements to Store ";
 cin>>n;
 ListArr l(n);
 l.GetData();
 while(ch!=6)
 {
 cout<<"\n1.Insert\n2.Delete\n3.Find by element\n4.Find by Position\n5.Print\n6.Exit\nEnter your Choice:";
 cin >> ch;
  switch(ch)
  {
   case 1: cout<<"Enter the element to be inserted ";
           cin>>element;
           cout<<"Enter the Position ";
           cin >> p;
          int flag;
          flag = l.Insert(element,p);
           if(flag==1)
            {
             cout<<"Insertion is SUCCESS\n";
            }
           else
             cout<<"Limit Exceeds\n";
           break;
   case 2: cout<<"Enter the Position to Delete the Element:";
           cin>>p;
           int d;
           d=l.Delet(p);
           if(d!=-1)
            cout<<"Deleted Item is "<< d<<"\n";
           else
            cout<<"No such posotion in tha list\n";
           break;
   case 3: cout<<"Enter the Element to be found";
           cin >> element;
           int f;
           f= l.FindByEle(element);
           if(f!=-1)
            {
             cout<<"Given element is found at the Position "<< f+1<<endl;
            }
           else 
            cout<<"No such element if found\n ";
           break;
   case 4: cout<<"Enter the Position to retrive the element:";
           cin >> p;
           f=l.FindByPos(p);
           if(f!=-1)
            {
             cout<<"Element at the position "<<p<<" is "<<f+1<<endl;
            }
           else
            cout<<"No such position is found\n ";
           break;
   case 5: l.Print();
           break;
   case 6: cout<<"Thank You\n";
           break;
   default: cout << "Invalid Choice";
  }
 }
}

