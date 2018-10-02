#include<iostream>
using namespace std;
class Stack
{
             int *Stk;
             int Top;
             int nCapacity;
      public:
          Stack(int);
          ~Stack();
          int push(int);
          int pop();
          void display();
          int returnTop();

};
Stack :: Stack(int nCap)
{
    nCapacity = nCap;
    Stk = new int [nCapacity];
    Top=-1;
}
Stack :: ~Stack()
{
    delete []Stk;
}
int Stack :: push(int x)
{
 if(Top == nCapacity-1)
  {
    return -1;
   }
   Stk[++Top]=x;
   return 1;
}
int Stack :: pop()
{
  if(Top <0)
     return -1;
   return Stk[Top--];
}
void Stack :: display()
{
 if(Top<0)
 {
  cout <<" \nStack Empty \n";
  return;
 }
 for(int i=Top;i>=0;i--)
  cout <<Stk[i] <<" ";
 cout<<endl;
}
int Stack :: returnTop()
{
    if(Top<0)
        return -1;
    else
        return Stk[Top];
}

main()
{
     int nChoice=0;
     int nVal;
     cout<<"Enter the Stack Capacity: ";
     cin>>nVal;
     Stack st(nVal);
     while(nChoice!=5)
        {
             cout <<"\n1.Push\n2.Pop\n3.Display\n4.Return Top\n5.Exit\n\nEnter ur choice: ";
             cin >> nChoice;
             switch(nChoice)
              {
               case 1:  cout <<"\nEnter the element: ";
                        cin >> nVal;
                        nVal = st.push(nVal);
                        if(nVal ==-1 )
                            cout<<"\nStack Over Flow\n";
                        else
                            cout<<"\nElement inserted\n";
                        break;
               case 2:  nVal=st.pop();
                        if(nVal == -1)
                            cout<<"\nStack Empty\n";
                        else
                            cout<<"\nElement Popped : "<<nVal;
                        break;
               case 3:  st.display();
                        break;
               case 4: nVal =st.returnTop();
                    if(nVal != -1)
                        cout<<"\nTop Element : "<<nVal<<endl;
                    else
                        cout<<"\nStack Empty\n";
                        break;
               case 5:  cout<<"\nThank You...\n";
                        break;
               default: cout<<"\nThere is no such Option in the list..\n ";

               }
         }
}
