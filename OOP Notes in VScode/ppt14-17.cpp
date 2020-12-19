#include <iostream>
#include <conio.h>
using namespace std;

class BaseClass       //Abstract class
{
    public:
    virtual void Display1() = 0;     
    virtual void Display2() = 0;     
    void Display3()
    {
    cout << "This is Display3() method of Base Class\n";
    }
};

class DerivedClass : public BaseClass
{
    public:
    void Display1()
    {
    cout << "This is Display1() method of Derived Class\n";
    }
    void Display2()
    {
    cout << "This is Display2() method of Derived Class\n";
    }
};  

int main()
{
    DerivedClass D;
    D.Display1(); 
    D.Display2();
    D.Display3();          
 }
