#include<iostream>
using namespace std;
class Base
{ public:
    void virtual disp() =0;
    virtual ~Base()=0;

};
Base :: ~Base()
{
    cout<<"\n Base destructor \n";
}
/*void Base :: disp()
   {
        cout<<"\n base\n";
    }*/
class Derived:public Base
{ public:
    ~Derived()
    {
       cout<<"\n Destructor derived\n";
    }
    void disp()
    {
        cout<<"\n derived \n ";
    }
};
main()
{
    Base *b;
    Derived d;
    b = &d;
    d.disp();
    b->disp();
}
