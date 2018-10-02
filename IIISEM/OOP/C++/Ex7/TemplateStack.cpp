#include<iostream>
using namespace std;
template<typename X>
class Node
{
public:
    template<typename T>
    friend class Stack;
    X Val;
    Node *pNext;
};
template<typename T>
class Stack
{
public:
    Stack();
    ~Stack();
    T Pop();
    T Push(T Val);
    T ReturnTop();
    int Display();
    bool IsEmpty();
    bool IsFull(Node<T> *);
private:
    Node<T> *top;
    Node<T> *head;

};
template<typename T>
Stack<T>::Stack()
{
    top =NULL;
    head =NULL;

}
template<typename T>
Stack<T>::~Stack()
{
    while(top)
        Pop();
}
template<typename T>
T Stack<T>::Push (T Val)
{
    Node<T> *newNode = new Node<T>;
    if(newNode == NULL )
        return 0;
    if(IsEmpty())
    {
        head = newNode;
        newNode -> Val = Val;
        newNode -> pNext = NULL;
        top = newNode;
        return 1;
    }
    else
    {
        newNode -> Val = Val;
        newNode -> pNext = NULL;
        top -> pNext = newNode;
        top = newNode;
        return 1;
    }
}
template<typename T>
T Stack<T> :: Pop()
{
    T Val;
    if(IsEmpty())
    {
        return 0;
    }
    else
    {
        Node<T> *current = head;
        if(head!=top)
        {
        while(current -> pNext != top)
        {
            current = current -> pNext;
        }
        }
        Val=top->Val;
        delete top;
        if(head==top)
        {
            top=NULL;
            head=NULL;
        }
        else
        {
          top = current;
          top->pNext = NULL;
        }
          return Val;
    }
}
template<typename T>
T Stack<T> :: ReturnTop()
{
    T Val;
    if(IsEmpty())
     {
        return 0;
     }
    else
    {
        return top->Val;
    }
}
template<typename T>
bool Stack<T> :: IsEmpty()
{
    if(top == NULL)
        return 1;
    else
        return 0;
}
template<typename T>
bool Stack<T> :: IsFull(Node<T> * newNode)
{
    if(newNode==NULL)
        return 1;
    else
        return 0;
}
template<typename T>
int Stack<T> :: Display()
{
    Node<T> *Current = head;
    if(Current==NULL)
        return 0;
    while(Current)
    {
        cout<<" "<<Current ->Val<<"->";
        Current=Current->pNext;
    }
    return 1;
}
//Application
main()
{
    /*do
    {
        int nType;
        cout<<"1.Integer\n2.Float.\n3.Exit.\nEnter Your Choice: ";
        cin>>nType;
        switch(nType)
        {
        case 1:*/
            cout<<"Integer Stack Implimentation.....\n";
            Stack<int> iStack;
            int nStatus;
            int nChoice;
            int Val;
            do
                {
                    cout<<"\nEnter the Choice:\n";
                    cout<<"1.Push in Stack\n2.Pop out the Stack\n3.Retrive Top\n4.Display\n5.Exit..\nEnter the Choice :";
                    cin>>nChoice;
                    switch(nChoice)
                    {
                        case 1:
                            cout<<"\nEnter the Value to Push: ";
                            cin>>Val;
                            nStatus=iStack.Push(Val);
                            if(nStatus==1)
                                cout<<"\n*********Object is Pushed********\n";
                            else
                                cout<<"\n*****Object is not pushed ********\n";
                            break;
                        case 2:
                            Val=iStack.Pop();
                            if(Val)
                                {
                                    cout<<"\nValue Popped out was: "<<Val<<endl;
                                }
                            else
                            {
                                cout<<"\n*********Stack is Empty*********\n";
                            }
                            break;
                        case 3:
                            Val=iStack.ReturnTop();
                            if(Val)
                                {
                                    cout<<"Top Element is: "<<Val;
                                }
                            else
                                {
                                    cout<<"\n*********Stack is Empty*********\n";
                                }
                            break;
                        case 4:
                            nStatus = iStack.Display();
                            if(!nStatus)
                                cout<<"\n*********Stack is Empty*********\n";
                            else
                                cout<<"\nElement in Stack were Displayed...\n";
                            break;
                        case 5:
                            cout<<"\n***********Thank You************\n";
                            break;
                        default:
                            cout<<"\nInvalid Option...\n";
                    }
               }while(nChoice !=5);
               //break;
        //case 2:
            cout<<"Float Stack Implimentation.....\n";
            Stack <float> CStack;
            float fVal;
            do
                {
                    cout<<"\nEnter the Choice:\n";
                    cout<<"1.Push in Stack\n2.Pop out the Stack\n3.Retrive Top\n4.Display\n5.Exit..\nEnter the Choice :";
                    cin>>nChoice;
                    switch(nChoice)
                    {
                        case 1:
                            cout<<"\nEnter the Value to Push: ";
                            cin>>fVal;
                            nStatus=CStack.Push(fVal);
                            if(nStatus==1)
                                cout<<"\n*********Object is Pushed********\n";
                            else
                                cout<<"\n*****Object is not pushed ********\n";
                            break;
                        case 2:
                            fVal=CStack.Pop();
                            if(fVal)
                                {
                                    cout<<"\nValue Popped out was: "<<fVal<<endl;
                                }
                            else
                                {
                                    cout<<"\n*********Stack is Empty*********\n";
                                }
                            break;
                        case 3:
                            fVal=CStack.ReturnTop();
                            if(fVal)
                                {
                                    cout<<"Top Element is: "<<fVal;
                                }
                            else
                            {
                                cout<<"\n*********Stack is Empty*********\n";
                            }
                            break;
                        case 4:
                            nStatus = CStack.Display();
                            if(!nStatus)
                                cout<<"\n*********Stack is Empty*********\n";
                            else
                                cout<<"\nElement in Stack were Displayed...\n";
                            break;
                        case 5:
                            cout<<"\n***********Thank You************\n";
                            break;
                        default:
                            cout<<"\nInvalid Option...\n";
                    }
                }while(nChoice !=5);
          //      break;
           // default:
             //   cout<<"\nInvalid Option....\n";
        //}
     //}while(nType!=3);

}
